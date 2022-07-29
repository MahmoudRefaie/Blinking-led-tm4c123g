#include "Blinking.h"

uint32 time_On = 1000U;
uint32 time_Off = 500U;


int main(void)
{
	Blink_Init();
	//TODO: take from the user the user on time and off time
	//btn_1 -> one press adds 1 sec to on-time/off-time
	//btn 2 -> one press change from on-time mode to off-time mode and from off-time mode to start blinking
	
	blink_led();
	while(1)
	{

		
	}
	return 0;
}
