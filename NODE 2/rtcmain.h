
#include<string.h>
#include<stdio.h>
#include"4bitlcd.h"
#include"i2c.h"


char i2c_rtc_read(char slaveAddr,char wordAddr);


void realtime(char *a)
{
	

	char sec,min,hour;
	

	sec=i2c_rtc_read(0x68,0x00);
	min=i2c_rtc_read(0x68,0x01);
	hour=i2c_rtc_read(0x68,0x02);


	
	sec=(((sec>>4)*10)+(sec&0x0f));
	min=(((min>>4)*10)+(min&0x0f));
//	hour=((((hour>>4)&1)*10)+(hour&0x0f));
 hour = (((hour & 0x30) >> 4) * 10) + (hour & 0x0F);

	sprintf(a,"%02d:%02d:%02d",hour,min,sec);
	return ; 
		
}
 
char i2c_rtc_read(char slaveAddr,char wordAddr)
{
	char data;
	i2c_start();
	i2c_write(slaveAddr<<1);
	i2c_write(wordAddr);
	i2c_restart();
	i2c_write((slaveAddr<<1)|1);
	data=i2c_nack();
	i2c_stop();
	return data;
}
