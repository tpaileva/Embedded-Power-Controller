#include "heartBeat.h"

HEARTBEAT heartBeat;

HEARTBEAT::HEARTBEAT(void)
{

}

void HEARTBEAT::Init(void)
{
	heartBeatGPIO.Init(HEARTBEAT_LED_GPIO_Port, HEARTBEAT_LED_Pin,
									kGpioModeOutputPP,
									kGpioSpeedLow,
									kGpioStateLow,
									kGpioPullOff);
    Update();
}

void HEARTBEAT::Update(void)
{
  if (GetTicks() - heartBeatTimer > (uint32_t)heartBeatArray[heartBeatIndex]) {
    // Trigger a heartbeat signal
    heartBeatIndex++;
    heartBeatTimer = GetTicks();
    LED_state = !LED_state;
    heartBeatGPIO.SetBit(LED_state);

    // Reset the index back to zero if at the end
    if (heartBeatIndex > sizeof(heartBeatArray) / 2 - 1) {
      heartBeatIndex = 0;
    }
  }
}

void HEARTBEAT::InvertLevel(void)
{
    LED_state = !LED_state;
}
