#include<lpc21xx.h>
#include"gate.h"

// board 07
typedef struct can2
{
	unsigned int id;
	unsigned int rtr;
	unsigned int dlc;
	unsigned int byteA;
  unsigned int byteB;
}can2_msg;
#include"candriver2.h"

int main()
{
	
	can2_msg m1;
	IODIR0=1<<0;
	
	can2_init();
	pwm_init();
	uart0_init(115200);
	uart0_tx_string("ready to receive  ");
	while(1)
	{
		can2_rx(&m1);
		if(m1.rtr==0)
		{
			uart0_tx_string("received  ");
			uart0_tx_string("RTR = ");
			uart0_tx_integer(m1.rtr);

			uart0_tx_string(" ID = ");
			uart0_tx_hex(m1.id);

			uart0_tx_string("\r\n");
			
			if(m1.id==0x150||m1.id==0x151)
        	{
	        	uart0_tx_string("gate opened  ");
				IOCLR0=1<<0;
	        	gate();
				delay_mills(3000);
			    uart0_tx_string("gate closed  ");
				uart0_tx_string("\r\n");
				IOCLR0=1<<0;
        	}
		}
		else
		{
		uart0_tx_string(" not receive");
		}
		delay_mills(1000);
	}
}


