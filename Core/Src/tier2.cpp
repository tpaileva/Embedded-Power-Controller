/*
 * tier2.cpp
 *
 *  Created on: Jul 1, 2021
 *      Author: akourchi
 */


#include <tier2.h>

TIER2 Tier2;

TIER2::TIER2(void)
{

}

// TODO: Destructor
TIER2::~TIER2(){}

void TIER2::Init() {

}

EstopState TIER2::getState() {
	// Returns the raw estop state

	// Disable if the Tier2 is disabled
	if (Ignore()) {
		return (EstopState::EstopDisabled);
	}

	return (state_);

}

bool TIER2::Enabled() {

	// Disable if the Tier2 is disabled
	if (Ignore()) {
		return (EstopState::EstopDisabled);
	}

	if (Timeout()) {
		Serial.WriteString("[ TIER2 ] - Xbee Timeout!\r\n");

		// The Xbee is no longer talking to us, system is faulted
		state_ = EstopState::EstopFault;
		return (1);
	}

	// Returns if the vehicle is stopped by this e-stop
	if (TimeRemaining() == 0) {
		// Count down over, Tier2 is enabled
		state_ = EstopState::EstopEnabled;
		return (1);
	} else {
		// Still time on the countdown, let the robot run
		state_ = EstopState::EstopDisabled;
		return (0);
	}

	// Shouldn't get here, return a fault
	Serial.WriteString("[ TIER2 ] - Unreachable fault!\r\n");
	state_ = EstopState::EstopFault;
	return (1);

}

uint32_t TIER2::TimeRemaining(void) {
	// Returns the number of ms left on the Tier2 timer
	// NOT overflow protected but I think that's ok tbh

	if (t_shutdown_ == UINT32_MAX) {
		// Timer hasn't been stated yet, just return the max value we can
		return (UINT32_MAX);
	}

	if (t_shutdown_ < GetTicks()) {
		// Time expired, return 0
		return (0);
	} else {
		// We're in the countdown, simple subtraction
		return (t_shutdown_ - GetTicks());
	}

	// Something is wrong, return system should be killed
	return (0);

};

void TIER2::Update()
{

	// Reads whatever data we have in the buffer to the XBee
	//    You must call RequestXbeeState() to ask for the information
	//    Call Update() as much as you like, but too many RequestXbeeState()
	//    calls will overflow the UART buffer

	// Note: This function is called in 1Hz main loop!
	//		 You can easily overflow the Xbee UART buffer by
	//		 calling this function too many times.


	/* We're going to split this up for now, so this update only reads the buffer

	// If we're in DARPA_MODE, request the state directly from the XBee
	if ((m_mode == kDarpaMode) || (m_mode == kForceDarpaMode))
	{
		// Requests the e-stop status from the Tier II module
		RequestXbeeState();

		// We can wait for the next loop to get the last response from the XBee.
		// That way we're non-blocking here
	}
	*/

	// Read whatever data we have
	uint8_t readByte = 0;

	while (Xbee.Available())
	{
		// TODO: Add error checking. Propagate fault to fault handler
		Xbee.Read(&readByte);

		// Stale code below, just process in DARPA mode and ignore timeouts
		//if (m_mode == kCostarMode)
		//{
		//	// We are in active mode, only accept heartbeat'd packets here
		//	if (_tier2_debug >= 3) { Serial.WriteString("[ Tier2 ] - Forcing COSTAR Mode"); }
		//	DataInCostar(readByte);
		//}
		//else if (m_mode == kForceDarpaMode) {
		//	// For some reason we've forced passive mode.  Maybe for competition?
		//	if (_tier2_debug >= 3) { Serial.WriteString("[ Tier2 ] - Forcing DARPA Mode"); }
		//	DataInDarpa(readByte);
		//}
		//else {
		//	// In passive mode, accept both type of packets (in case we lock onto an active packet)
		//	if (_tier2_debug >= 3) { Serial.WriteString("[ Tier2 ] - DARPA and COSTAR Mode"); }
		//	DataInCostar(readByte);
		//	DataInDarpa(readByte);
		//}

		// For some reason we've forced passive mode.  Maybe for competition?
		if (_tier2_debug >= 3) { Serial.WriteString("[ Tier2 ] - Forcing DARPA Mode\r\n"); }

		// Process X-Bee Packet
		DataInDarpa(readByte);

	}

	// Update our stopped state.  This will also deal with any timeouts
	// We basically do this by asking the state of the system
	Enabled();

	// All done
	return;
}

void TIER2::StartCountdown() {

	// Update the time that we've been asked for the countdouwn
	t_stop_request_ = GetTicks();

	if (TimeRemaining() == UINT32_MAX) {
		// Time not started, we need to start it
		t_shutdown_ = GetTicks() + ms_activate_;

		if (_tier2_debug >= 0) {
			Serial.WriteString("[ Tier2 ] - RF ESTOP SIGNAL RECEIVED!\r\n");
			Serial.WriteString("[ Tier2 ] - Started RF E-Stop countdown...!\r\n");
		}
	}

	// All done
	return;
}


/*
bool TIER2::getTier2EstopState()
{
	// Stale code below, just process in DARPA mode and ignore timeouts
	// Check to see if system has timed out
	//if (Timeout())
	//{
	//	if (_tier2_debug >= 2) { Serial.WriteString("[ Tier2 ] - Timeout"); }
	//
	//	if (m_module_state != kXbeeHardwareStopped)
	//	{
	//		LocalXbeeEstop();
	//	}
	//
	//	m_stopped = true;
	//}

	if (_tier2_debug >= 2) {
		Serial.WriteString("[ Tier2 ] - Stopped : ");
		if (m_stopped) {
			Serial.WriteString("True");
		}
		else {
			Serial.WriteString("False");
		}
	}

	if (m_stopped) {
		state_ = EstopState::EstopEnabled;
	} else {
		state_ = EstopState::EstopDisabled;
	}

	// Returns the Tier II e-stop state
	return (m_stopped);
}*/

// == XBEE functionality stuff ==
void TIER2::SetOperatingMode(Tier2OpMode new_mode)
{
	// Changes the operating mode between DARPA (no heartbeat requirement) and COSTAR (requires a heartbeat) mode
	m_mode = new_mode;

	if (m_mode == kCostarMode)
	{
		// If we're running in COSTAR mode, reduce the allowed timeout period
		ms_xbee_timeout = 500;
	}

	// Reset the state machines
	m_state_costar = 0;
	m_state_darpa = 0;

	return;
}

Tier2OpMode TIER2::GetOperatingMode()
{
	// Returns the current Tier2 E-Stop mode
	return (m_mode);
}

void TIER2::SetDestinationAddress(uint64_t destination_address)
{
	// Set the destination address for the COSTAR transmit signals
	// This is done through a Local AT Command (Type 0x08)

	// Not sure if I need this as I can set all the addressing stuff in the transmission packet making

	m_destination_address = destination_address;

	return;

	// As it stands, I don't think I need to set all this other stuff, I think it'll be something to work out in debugging
	//     |
	//     V

	// Union for transmitting data
	union tx_union
	{
		AT_command_struct msg;
		uint8_t           data[sizeof(AT_command_struct)];
	} tx_buffer;

	// Set our transmit address to the MAC address of the adaptor
	addr_union addr_data;
	addr_data.addr_64bit = InvertEndian64(destination_address);

	// Should check to see what the addresses are here, and if they're different, change them and re-run the function, otherwise just return success

	// Common structure
	tx_buffer.msg.header = 0x7E;                                             // Header
	tx_buffer.msg.packet_length = (uint16_t)InvertEndian16(sizeof(tx_buffer) - 4);  // Packet length bytes (don't include headers or checksum)
	tx_buffer.msg.frame_type = 0x08;                                             // Frame Type: 0x08 AT Command
	tx_buffer.msg.frame_id = 0x01;                                             // Frame ID: 1

	// ==== High Byte ====
	tx_buffer.msg.at_command = InvertEndian16(0x4448);                            // AT command (DH)
	tx_buffer.msg.param_value = addr_data.addr.high_byte;
	tx_buffer.msg.checksum = XbeeChecksum(tx_buffer.data, sizeof(tx_buffer) - 1); // Checksum

	// Debug
	if (_tier2_debug) {
		Serial.WriteString("[ Tier2 ] - Sending: ");
		PrintBuffer(tx_buffer.data, sizeof(tx_buffer));
	}

	// Write the high 4-byte change to the serial port.
	Xbee.Write(tx_buffer.data, sizeof(tx_buffer));
	Delay(200);

	// ==== Low Byte ====
	tx_buffer.msg.at_command = InvertEndian16(0x444C);                            // AT command (DL)
	tx_buffer.msg.param_value = addr_data.addr.low_byte;
	tx_buffer.msg.checksum = XbeeChecksum(tx_buffer.data, sizeof(tx_buffer) - 1); // Checksum

	// Debug
	if (_tier2_debug) {
		Serial.WriteString("[ Tier2 ] - Sending: ");
		PrintBuffer(tx_buffer.data, sizeof(tx_buffer));
	}

	// Write the high 4-byte change to the serial port and delay so the value is accepted
	Xbee.Write(tx_buffer.data, sizeof(tx_buffer));
	Delay(200);

	// Request the data back to make sure it's changed properly
	// We do this by re-invoking the function and checking the result

	return;
}

void TIER2::TransmitHeartbeat(uint8_t estop)
{
	SendDataPacket(estop);

	// All done
	return;
}

void TIER2::RequestXbeeState()
{
	// Request the state of the xbee.
	Xbee.Flush();

	// We don't read the data here, we only request it
	if (_tier2_debug) { Serial.WriteString("[ Tier2 ] - Requesting State\r\n"); }

	uint8_t tx_buffer[8] = { 0x7E, 0x00, 0x04, 0x08, 0x01, 0x49, 0x53, 0x5A };

	Xbee.Write(tx_buffer, sizeof(tx_buffer));

	return;
}

void TIER2::TransmitDarpaEstop()
{
	// Broadcast a Tier 2 e-stop via the Remote AT Command.
	// This emulates the way DARPA does it

	// Union for transmitting data
	union tx_union
	{
		AT_remote_command_struct msg;
		uint8_t                  data[sizeof(AT_remote_command_struct)];
	} tx_buffer;

	// Fill in data packet
	tx_buffer.msg.header = 0x7E;											// Header
	tx_buffer.msg.packet_length = InvertEndian16(sizeof(tx_buffer) - 4);	// Packet length bytes (don't include headers or checksum)
	tx_buffer.msg.frame_type = 0x17;                                        // Frame Type: 0x17 Remote AT Command
	tx_buffer.msg.frame_id = 0x01;                                          // Frame ID: 1
	tx_buffer.msg.addr_64bit = InvertEndian64(m_destination_address);       // MAC addresses to transmit to
	tx_buffer.msg.addr_16bit = InvertEndian16(0xFFFE);                      // 16b Address = 0xFF FE (Reserved)
	tx_buffer.msg.remote_cmd_options = 0x03;                                // Remote CMD Options = 0b11 (Disable ACK, Apply Changes)  <--- maybe I should put enable ACK in here...
	tx_buffer.msg.at_command = InvertEndian16(0x4431);                      // AT Command: D1 = 0x4431
	tx_buffer.msg.param_value = 0x05;                                       // Digital Output (High) = 0x05
	tx_buffer.msg.checksum = XbeeChecksum(tx_buffer.data, sizeof(tx_buffer) - 1); // Checksum

	// Debugging
	if (_tier2_debug) { Serial.WriteString("\t"); PrintBuffer(tx_buffer.data, sizeof(tx_buffer)); }

	// Write the frame to the serial port.
	Xbee.Write(tx_buffer.data, sizeof(tx_buffer));

	// All done
	return;
}

void TIER2::TransmitDarpaReset()
{
	// Broadcast a reset via the Remote AT Command

	// Union for transmitting data
	union tx_union
	{
		AT_remote_command_struct msg;
		uint8_t                  data[sizeof(AT_remote_command_struct)];
	} tx_buffer;

	// Fill in data packet
	tx_buffer.msg.header = 0x7E;											// Header
	tx_buffer.msg.packet_length = InvertEndian16(sizeof(tx_buffer) - 4);    // Packet length bytes (don't include headers or checksum)
	tx_buffer.msg.frame_type = 0x17;                                        // Frame Type: 0x17 Remote AT Command
	tx_buffer.msg.addr_64bit = InvertEndian64(m_destination_address);       // MAC addresses to transmit to
	tx_buffer.msg.addr_16bit = 0xFFFE;                                      // 16b Address = 0xFF FE (Reserved)
	tx_buffer.msg.remote_cmd_options = 0x03;                                // Remote CMD Options = 0b11 (Disable ACK, Apply Changes)  <--- maybe I should put enable ACK in here...
	tx_buffer.msg.at_command = InvertEndian16(0x4431);                      // AT Command: D1 = 0x4431
	tx_buffer.msg.param_value = 0x04;                                       // Param Value: Digital Output (Low) = 0x04
	tx_buffer.msg.checksum = XbeeChecksum(tx_buffer.data, sizeof(tx_buffer) - 1); // Checksum

	// Debug
	if (_tier2_debug) { Serial.WriteString("\t"); Serial.Write(tx_buffer.data, sizeof(tx_buffer)); }

	// Write the frame to the serial port.
	Xbee.Write(tx_buffer.data, sizeof(tx_buffer));

	// All done
	return;
}

void TIER2::Reset()
{
	// Reset the xbee hardware
	LocalXbeeReset();

	// Reset which state machine we're using
	SetOperatingMode(kDarpaMode);

	// All done
	return;
}

uint32_t TIER2::TimeoutRemaining() {

	// Returns how long we have until a XBee Timeout.  Returns
	//   UINT32_MAX | we're not yet worried (up to 10s since we heard from it)
	//            0 | we've timed out
	//    otherwise | remaining time


	if (GetTicks() - t_last_message < 15UL*1000) {
		// We've heard from the system, don't countdown
		return (UINT32_MAX);
	} else if (GetTicks() - t_last_message > ms_xbee_timeout) {
		// System has timed out, return 0
		alive_ = 0;
		return (0);
	}

	// Return the remaining time
	return (t_last_message+ms_xbee_timeout - GetTicks());
}

bool TIER2::Timeout()
{
	// Returns if the comms have timed out
	if (GetTicks() - t_last_message > ms_xbee_timeout)
	{
		// System has timed out
		return (true);
	}
	else {
		// Still receiving updates regularly enough
		return (false);
	}
}

void TIER2::DataInDarpa(uint8_t readdata)
{
	// State machine for decoding the return from an AT status request from an XBee radio
	if (_tier2_debug >= 2) {
		Serial.WriteString("[ Tier2 ] - Decoding DARPA packet: ");
		char * sendbuf = (char *)malloc(sizeof(sizeof(char) * (18)));
		sprintf(sendbuf, "0x%x \n", readdata);
		Serial.WriteString(sendbuf);

	}
	switch (m_state_darpa)
	{
	case 0:                   // Waiting to lock onto data frame
		if (readdata == 0x7E) // start with a 0x7E
		{
			m_state_darpa = 1;
			m_in_count_darpa = 0;

			// store data to buffer
			m_in_buf_darpa[m_in_count_darpa] = readdata;
			m_in_count_darpa++;
		}

		break;

	case 1: // Packet length (high byte)
	case 2: // Packet length (low byte)
		// Incrememnt the state machine
		m_state_darpa++;

		// store data to buffer
		m_in_buf_darpa[m_in_count_darpa] = readdata;
		m_in_count_darpa++;

		break;

	case 3:
		if (readdata == 0x88)   // 0x88 is a receive packet
		{
			m_state_darpa = 4;

			// store data to buffer
			m_in_buf_darpa[m_in_count_darpa] = readdata;
			m_in_count_darpa++;
		}
		else {
			// The 0x7E we found wasn't the start, back to the beginning
			if (_tier2_debug) { Serial.WriteString("Missed the frame ID for the DARPA state machine\r\n"); }
			m_state_darpa = 0;
		}

		break;

	case 4:                  // data from locked onto, continued reading until we have everything
		m_in_buf_darpa[m_in_count_darpa] = readdata;
		m_in_count_darpa++;

		// Check for end of string
		if (m_in_count_darpa == sizeof(m_in_buf_darpa))
		{
			// decode message
			DecodeStreamDarpa(m_in_buf_darpa);

			// end of frame
			m_state_darpa = 0;
		}

		break;

	default:
		m_state_darpa = 0;
		m_in_count_darpa = 0;

		break;
	}
}

void TIER2::DataInCostar(uint8_t readdata)
{
	// Decodes a heartbeat packet from the transmitter

	switch (m_state_costar)
	{
	case 0:                   // Waiting to lock onto data frame
		if (readdata == 0x7E) // start with a 0x7E
		{
			m_state_costar = 1;
			m_in_count_costar = 0;

			// store data to buffer
			m_in_buf_costar[m_in_count_costar] = readdata;
			m_in_count_costar++;
		}

		break;

	case 1: // Packet length (high byte)
	case 2: // Packet length (low byte)
		// Incrememnt the state machine
		m_state_costar++;

		// store data to buffer
		m_in_buf_costar[m_in_count_costar] = readdata;
		m_in_count_costar++;

		break;

	case 3:
		if (readdata == 0x90)   // 0x90 is a receive packet
		{
			m_state_costar = 4;

			// store data to buffer
			m_in_buf_costar[m_in_count_costar] = readdata;
			m_in_count_costar++;
		}
		else {
			// The 0x7E we found wasn't the start, back to the beginning (or we just got the wrong packet type)
			if (_tier2_debug)
			{
				Serial.WriteString("[ Tier2 ] - Missed the frame type for the COSTAR state machine\r\n");
				Serial.WriteString("          - Got: ");

				char * sendbuf = (char *)malloc(sizeof(sizeof(char) * (18)));
				sprintf(sendbuf, "0x%x ", readdata);
				Serial.WriteString(sendbuf);
				Serial.WriteString(" Expected: 0x90\r\n");
			}

			m_state_costar = 0;
		}

		break;

	case 4:                  // data from locked onto
		m_in_buf_costar[m_in_count_costar] = readdata;
		m_in_count_costar++;

		// Read in until the data buffer is full (there is no footer to detect)
		if (m_in_count_costar == sizeof(m_in_buf_costar))
		{
			// decode message
			DecodeStreamCostar(m_in_buf_costar);

			// end of frame
			m_state_costar = 0;
		}

		break;

	default:
		m_state_costar = 0;
		m_in_count_costar = 0;

		break;
	}
}

void TIER2::DecodeStreamDarpa(uint8_t data_stream[TIER_II_AT_COMMAND_RESPONSE_STRUCT_SIZE])
{
	if (_tier2_debug) { Serial.WriteString("[ Tier2 ] - Decoding Tier 2 data stream (DARPA)\r\n"); }

	union rx_union
	{
		AT_command_response_struct msg;
		uint8_t                    data[sizeof(AT_command_response_struct)];
	} buffer;

	// Copy data to temporary working buffer
	memcpy(&buffer, data_stream, sizeof(buffer));

	// Calculate checksums
	uint8_t _expected_checksum = XbeeChecksum(buffer.data, sizeof(buffer) - 1);
	uint8_t _received_checksum = buffer.msg.checksum;

	// check the checksum is ok
	if (_expected_checksum != _received_checksum)
	{
		// checksum failed, do nothing
		if (_tier2_debug) {
			Serial.WriteString("[ Tier2 ] - DARPA checksum fail - Got ");

			char * sendbuf = (char *)malloc(sizeof(sizeof(char) * (18)));
			sprintf(sendbuf, "0x%x ", _received_checksum);
			Serial.WriteString(sendbuf);

			Serial.WriteString(", Expected ");
			sprintf(sendbuf, "0x%x \r\n", _expected_checksum);
			Serial.WriteString(sendbuf);
		}

		return;
	}

	// The pin state of D0 indicates if we're e-stopped or not (LOW is E-Stop)
	if (buffer.msg.D0 == pinLevelDisabled_) {
		// Set the state to allow the vehicle to drive
		state_ = EstopState::EstopDisabled;
		t_shutdown_ = UINT32_MAX;

	} else {
		// The vehicle has been commanded to stop
		StartCountdown();

	}

	if (Enabled())
	{
		m_module_state = kXbeeHardwareStopped;
	}
	else {
		m_module_state = kXbeeHardwareEnabled;
	}

	// Signal we have new data and update time
	t_last_message = GetTicks();
	alive_ = 1;

	// Debugging
	/*
	std::string str = "Decoded XBee Packet";
	if (buffer.msg.D0 == pinLevelDisabled_) {
		str += " : GO";
	} else {
		str += " : STOP";
	}
	ROS.publishMsg(str);
	*/


	// All done
	return;
}

void TIER2::DecodeStreamCostar(uint8_t data_stream[TIER_II_REMOTE_RECEIVE_STRUCT_SIZE])
{
	union rx_union
	{
		remote_receive_struct msg;
		uint8_t               data[sizeof(remote_receive_struct)];
	} buffer;

	// Copy data to temporary working buffer
	memcpy(&buffer, data_stream, sizeof(buffer));

	// Calculate checksums
	uint8_t _expected_checksum = XbeeChecksum(buffer.data, sizeof(buffer) - 1);
	uint8_t _received_checksum = buffer.msg.checksum;

	char * sendbuf = (char *)malloc(sizeof(sizeof(char) * (18)));

	// check the checksum is ok
	if (_expected_checksum != _received_checksum)
	{
		// checksum failed, do nothing
		if (_tier2_debug) {
			Serial.WriteString("[ Tier2 ] - COSTAR checksum fail - Got ");
			sprintf(sendbuf, "0x%x ", _received_checksum);
			Serial.WriteString(sendbuf);

			Serial.WriteString(", Expected ");
			sprintf(sendbuf, "0x%x \r\n", _expected_checksum);
			Serial.WriteString(sendbuf);
		}

		return;
	}

	// The payload contains if we are e-stopped or not.
	// Eventually you could extend this to a bitmap if required
	if (buffer.msg.payload == pinLevelDisabled_) {
		// Set the state to allow the vehicle to drive
		state_ = EstopState::EstopDisabled;
		t_shutdown_ = UINT32_MAX;

	} else {
		// The vehicle has been commanded to stop
		StartCountdown();

	}

	// Signal we have new data and update time
	t_last_message = GetTicks();

	// As we have received COSTAR packet, we will now only request/accept them (DARPA packets are now no good)
	SetOperatingMode(kCostarMode);

	// Use AT commands to stop/enable the hardware pins on state change
	if ((Enabled()) && (m_module_state == kXbeeHardwareEnabled))
	{
		// Disable the xbee in hardware
		LocalXbeeEstop();
	}
	else if ((!Enabled()) && (m_module_state == kXbeeHardwareStopped)) {
		// Enable the xbee in hardware
		LocalXbeeReset();
	}

	return;
}

void TIER2::SendDataPacket(uint8_t payload)
{
	// Union for transmitting data
	union tx_union
	{
		transmit_request_struct msg;
		uint8_t                 data[sizeof(transmit_request_struct)];
	} tx_buffer;

	// Assemble the data packet
	tx_buffer.msg.header = 0x7E;
	tx_buffer.msg.packet_length = InvertEndian16(sizeof(tx_buffer) - 4);               // Packet length bytes (don't include headers or checksum)
	tx_buffer.msg.frame_type = 0x10;
	tx_buffer.msg.frame_id = 0x01;

	tx_buffer.msg.addr_64bit = InvertEndian64(m_destination_address);              // MAC addresses to transmit to
	tx_buffer.msg.addr_16bit = InvertEndian16(0xFFFE);                            // 16b Address = 0xFF FE (Reserved)

	tx_buffer.msg.broadcast_radius = 0x00;
	tx_buffer.msg.options = 0xC0;
	tx_buffer.msg.payload = payload;
	tx_buffer.msg.checksum = XbeeChecksum(tx_buffer.data, sizeof(tx_buffer) - 1); // Checksum

	// Debugging
	if (_tier2_debug) {
		Serial.WriteString("[ Tier2 ] - send_data_packet: ");
		PrintBuffer(tx_buffer.data, sizeof(tx_buffer));
	}

	// Send the data packet
	Xbee.Write(tx_buffer.data, sizeof(tx_buffer));

	// All done
	return;
}

uint8_t TIER2::XbeeChecksum(uint8_t buf[], unsigned int len)
{
	// Formula: Add all bytes (except for start delimiter and length), keep only the lowest 8 bits, and subtract off 0xFF.
	uint32_t chksum = 0;

	for (uint8_t ii = 3; ii < len; ii++)
	{
		chksum += buf[ii];
	}

	chksum = chksum & 0xFF;
	chksum = 0xFF - chksum;

	return (uint8_t)(chksum);
}

uint16_t TIER2::InvertEndian16(uint16_t val)
{
	union val_union
	{
		uint16_t data16;
		uint8_t  data8[2];
	} inval;

	// Copy the data over
	inval.data16 = val;

	// Create the new data
	val_union retval;
	for (uint8_t ii = 0; ii < sizeof(inval); ii++)
	{
		retval.data8[ii] = inval.data8[2 - ii - 1];
	}

	// Return the reverse value
	return (retval.data16);
}

uint64_t TIER2::InvertEndian64(uint64_t val)
{
	union val_union
	{
		uint64_t data64;
		uint8_t  data8[8];
	} inval;

	// Copy the data over
	inval.data64 = val;

	// Create the new data
	val_union retval;
	for (uint8_t ii = 0; ii < sizeof(inval); ii++)
	{
		retval.data8[ii] = inval.data8[8 - ii - 1];
	}

	// Return the reverse value
	return (retval.data64);
}

void TIER2::LocalXbeeEstop()
{
	// Sets a local xbee to DARPA estop
	uint8_t _xbee_estop_command[9] = { 0x7E,0x00,0x05,0x08,0x01,0x44,0x31,0x05,0x7C };

	// Set reset command
	Xbee.Write(_xbee_estop_command, sizeof(_xbee_estop_command));

	if (_tier2_debug) { Serial.WriteString("[ Tier2 ] - Sending local xbee estop command\r\n"); }

	// Update the software state
	m_module_state = kXbeeHardwareStopped;
}

void TIER2::LocalXbeeReset()
{
	// Resets a local xbee to DARPA estop
	uint8_t _xbee_reset_command[9] = { 0x7E,0x00,0x05,0x08,0x01,0x44,0x31,0x04,0x7D };

	Xbee.Write(_xbee_reset_command, sizeof(_xbee_reset_command));

	if (_tier2_debug) { Serial.WriteString("[ Tier2 ] - Sending local xbee reset command\r\n"); }

	// The problem with this reply stuff at the moment is we may have heartbeat packets
	// coming through that we'll have to filter out and I really don't want to.  Therefore
	// let's just assume everything worked out ok ;)

	// Update the software state
	m_module_state = kXbeeHardwareEnabled;
}

void TIER2::PrintBuffer(uint8_t buf[], uint8_t len)
{
	char * sendbuf = (char *)malloc(sizeof(sizeof(char) * (18)));

	// Prints a buffer in HEX for the debugs :)
	for (uint8_t ii = 0; ii < len; ii++)
	{
		//DEBUG_SERIAL.print("0x");

		if (buf[ii] < 0x10)
		{
			sprintf(sendbuf, "0x0%x ", buf[ii]);
			Serial.WriteString(sendbuf);
		}
		else {
			sprintf(sendbuf, "0x%x ", buf[ii]);
			Serial.WriteString(sendbuf);
		}
	}

	Serial.WriteString("");
}
