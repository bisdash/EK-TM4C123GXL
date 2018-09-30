#include "ti_bsp.h"

void led_test1()
{
	while(1)
	{
		GPIO_pin_write(GPIO_LED_PORT, LED_RED, 1);
		bsp_delay(5000000);
		GPIO_pin_write(GPIO_LED_PORT, LED_BLUE, 1);
		bsp_delay(5000000);
		GPIO_pin_write(GPIO_LED_PORT, LED_GREEN, 1);
		bsp_delay(5000000);
		//GPIO_pin_write(GPIO_LED_PORT, 0, 1);
		bsp_delay(5000000);
	}
}

void led_test2()
{
	while(1)
	{
			GPIO_led_toggle(LED_RED, 900000);
			bsp_delay(5000000);
			GPIO_led_toggle(LED_BLUE, 900000);
			bsp_delay(5000000);
			GPIO_led_toggle(LED_GREEN, 900000);
			bsp_delay(5000000);		
	}
}

#define PRESSED 0
#define RELEASED 1

void button_test()
{
	uint32_t button_state;
	
	while(1)
	{		
			button_state = GPIO_pin_read(GPIO_BUTTON_PORT, ALL_BUTTONS);
			
			// switches are connected weak pull up meaning, 
			// release = 1
			// pressed = 0
		
			if((button_state & BUTTON_RIGHT) == PRESSED)
			{
				GPIO_pin_write(GPIO_LED_PORT, LED_RED, 1);
				bsp_delay(2000000);
				GPIO_pin_write(GPIO_LED_PORT, LED_BLUE, 1);
				bsp_delay(2000000);
				GPIO_pin_write(GPIO_LED_PORT, LED_GREEN, 1);
				bsp_delay(2000000);
			}
			else if((button_state & BUTTON_LEFT) == PRESSED)
			{
				GPIO_pin_write(GPIO_LED_PORT, LED_GREEN, 1);
				bsp_delay(2000000);
				GPIO_pin_write(GPIO_LED_PORT, LED_BLUE, 1);
				bsp_delay(2000000);
				GPIO_pin_write(GPIO_LED_PORT, LED_RED, 1);
				bsp_delay(2000000);
			}
			else
			{
				GPIO_pin_write(GPIO_LED_PORT, 0, 1);
			}
	}
}

int main(void)
{
	// set up the system clock
  bsp_clock_set(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
	
	//configure the led gpio ports & pins 
	GPIO_led_configure(GPIO_BUS_APB);
	
	//configure the button gpio port and pins
	Buttons_configure(GPIO_BUS_APB);
	
	//led_test1();
	button_test();
	return 0;
}
