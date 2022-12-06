/*
 * tier2.h
 *
 *  Created on: Jul 1, 2021
 *      Author: akourchi
 */

#ifndef INC_TIER2_H_
#define INC_TIER2_H_

#include <cstring>

#include "uart.h"
#include "util.h"
#include "rosComms.h"

#include "data_structures.h"

// Forward declaration
class TIER2;

extern TIER2 Tier2;

enum Tier2OpMode
{
	kDarpaMode = 0,
	kForceDarpaMode,
	kCostarMode
};

enum Tier2XbeeModuleState
{
	kXbeeHardwareStopped = 0,
	kXbeeHardwareEnabled
};

// Tier 2 DARPA Stream
const static int TIER_II_STREAM_DARPA_BUFFER_SIZE = 15;

// Addressing Structs / Unions
struct addr_struct
{
	uint32_t high_byte;
	uint32_t low_byte;
}__attribute__((packed));

union addr_union
{
	uint64_t addr_64bit;
	addr_struct addr;
};

// AT Command Struct (Frame Type 0x08)
struct AT_command_struct
{
	uint8_t header;
	uint16_t packet_length;
	uint8_t frame_type;
	uint8_t frame_id;

	uint16_t at_command;
	uint32_t param_value;

	uint8_t checksum;
}__attribute__((packed));

// AT Command Response (Frame Type 0x88)
struct AT_command_response_struct
{
	uint8_t header;
	uint16_t packet_length;
	uint8_t frame_type;
	uint8_t frame_id;

	uint16_t AT_command;
	uint8_t  command_status;

	uint8_t D5;
	uint8_t D4;
	uint8_t D3;
	uint8_t D2;
	uint8_t D1;
	uint8_t D0;

	uint8_t checksum;
}__attribute__((packed));

const static int TIER_II_AT_COMMAND_RESPONSE_STRUCT_SIZE = sizeof(AT_command_response_struct);

// Remote AT Command Struct (Frame Type 0x17)
struct AT_remote_command_struct
{
	uint8_t header;
	uint16_t packet_length;
	uint8_t frame_type;
	uint8_t frame_id;

	uint64_t addr_64bit;
	uint16_t addr_16bit;

	uint8_t remote_cmd_options;
	uint16_t at_command;
	uint8_t param_value;

	uint8_t checksum;
}__attribute__((packed));

// Transmit Request Struct  (Frame Type 0x10)
struct transmit_request_struct
{
	uint8_t  header;
	uint16_t packet_length;
	uint8_t  frame_type;
	uint8_t  frame_id;

	uint64_t addr_64bit;;
	uint16_t addr_16bit;
	uint8_t  broadcast_radius;
	uint8_t  options;

	uint8_t payload;

	uint8_t checksum;
}__attribute__((packed));

// Remote Receive Struct (Frame Type 0x90)
struct remote_receive_struct
{
	uint8_t header;
	uint16_t packet_length;
	uint8_t frame_type;

	uint64_t source_addr_64bit;
	uint16_t source_addr_16bit;

	uint8_t receive_options;

	uint8_t payload;

	uint8_t checksum;
}__attribute__((packed));

const static int TIER_II_REMOTE_RECEIVE_STRUCT_SIZE = sizeof(remote_receive_struct);

class TIER2 {
public:
	TIER2(void);

	virtual ~TIER2();

	void Init(void);

	// State feedback
	EstopState getState();       // Returns the raw state
	bool       Enabled();        // Returns if the vehicle is stopped by this EStop
	void       StartCountdown(); // Start a Tier2 countdown to e-stop
	bool       Alive() { return (alive_); }; // Returns if we've heard from the xbee recently
	uint32_t   TimeLastMessage() { return (t_last_message); }; // Returns when we last heard from the xbee

	// Shutdown Timing
	void     SetActivateTime(uint32_t activateTime) { ms_activate_ = activateTime; }
	uint32_t TimeRemaining(void);
	uint32_t TimeoutRemaining(void);
	uint32_t TimeStopRequest(void) { return (t_stop_request_); };

	// Operating Mode and Addressing
	void    SetOperatingMode(Tier2OpMode new_mode);
	Tier2OpMode GetOperatingMode();
	void    SetDestinationAddress(uint64_t destination_address);

	// Heartbeating Functions
	void TransmitHeartbeat(uint8_t estop);

	// Passive E-Stop Functions
	void RequestXbeeState();
	void TransmitDarpaEstop();
	void TransmitDarpaReset();

	// System Arm Status
	void Update();
	//bool getTier2EstopState();

	// Module Reset
	void Reset();

	// Timeouts
	bool Timeout();

	// Debugging
	uint8_t _tier2_debug = 0;

	bool Ignore(void) { return (0); };  // Set to 1 to ignore this e-stop

private:

	// Operation Mode and Addressing
	Tier2OpMode m_mode = kDarpaMode;
	bool        alive_ = false;

	// System Arm Status
	EstopState state_ = EstopState::EstopFault;

	// Pin Levels
	bool pinLevelDisabled_ = 0;  // Pin level when e-stop disabled (robot can move)

	// Serial Read State Machine
	void DataInDarpa(uint8_t readdata);
	void DataInCostar(uint8_t readdata);

	void DecodeStreamDarpa(uint8_t data_stream[TIER_II_AT_COMMAND_RESPONSE_STRUCT_SIZE]);
	void DecodeStreamCostar(uint8_t data_stream[TIER_II_REMOTE_RECEIVE_STRUCT_SIZE]);

	uint8_t m_state_darpa = 0;
	uint8_t m_in_count_darpa = 0;
	uint8_t m_in_buf_darpa[TIER_II_AT_COMMAND_RESPONSE_STRUCT_SIZE];

	uint8_t m_state_costar = 0;
	uint8_t m_in_count_costar = 0;
	uint8_t m_in_buf_costar[TIER_II_REMOTE_RECEIVE_STRUCT_SIZE];

	// UART Functions
	void SendDataPacket(uint8_t payload);
	//uint8_t  Checksum(uint8_t buf[], uint8_t len);
	uint8_t  XbeeChecksum(uint8_t buf[], unsigned int len);
	uint16_t InvertEndian16(uint16_t val);
	uint64_t InvertEndian64(uint64_t val);

	// Radio Functions
	uint64_t m_destination_address = 0x000000000000FFFF;
	void LocalXbeeEstop();
	void LocalXbeeReset();

	Tier2XbeeModuleState m_module_state = kXbeeHardwareEnabled;

	// Debugging Functions
	void PrintBuffer(uint8_t buf[], uint8_t len);

	// Timeouts
	unsigned long t_last_message = 0;
	unsigned long ms_xbee_timeout = UINT32_MAX;
	uint32_t      ms_activate_ = 30UL*1000;       // Time taken for the Tier2 stop to activate
	                                              // Dictated by https://www.subtchallenge.com/resources/Transponder_and_Emergency_Stop_Integration_Guide.pdf, Section 1

	// Shutdown Timing
	uint32_t t_shutdown_ = UINT32_MAX;
	uint32_t t_stop_request_ = 0;           // Time the last stop request was asked

};


#endif /* INC_TIER2_H_ */
