
//taking two leg common,(diagolnally) running 4 legs on 6  pwm pins trial 

#include "uart.h"
#include "stdlib.h"
#include "config.h"
#include "gpio.h"
#include <string.h>
#include "pwmc.h"

#define SYS_CLK_FREQ 40000000UL

void hop(void)
{		
		int pos1 = 0;
		int pos2 = 30;
		int pos3 = 10;
		//hip
		for (pos1 = 110; pos1 >= 90; pos1 -= 1) { // goes from 0 degrees to 180 degrees
   			servoRotate(PWM_CH_5,pos1);              // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_0,pos1);  
    		udelay(20);                       // waits 15ms for the servo to reach the position
 		 }
  		for (pos1 = 90; pos1 <= 110; pos1 += 1) { // goes from 180 degrees to 0 degrees
    		servoRotate(PWM_CH_5,pos1);               // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_0,pos1);  
    		udelay(1);                       // waits 15ms for the servo to reach the position
  		}
		//knee   
    	for (pos2 = 5; pos2 <= 20; pos2 += 1) { // goes from 0 degrees to 180 degrees
    		servoRotate(PWM_CH_6,pos2);               // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_1,pos2);   
    		udelay(20);                       // waits 15ms for the servo to reach the position
        }
  		for (pos2 = 20; pos2 >= 5; pos2 -= 1) { // goes from 180 degrees to 0 degrees
    		servoRotate(PWM_CH_6,pos2);              // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_1,pos2);  
    		udelay(10);                       // waits 15ms for the servo to reach the position
  		}
		//sholder
		for (pos3 = 30; pos3 <= 40; pos3 += 1) { // goes from 0 degrees to 180 degrees
   
    		servoRotate(PWM_CH_7,pos3);               // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_2,pos3);  
    		udelay(5);                       // waits 15ms for the servo to reach the position
        }
  		for (pos3 = 40; pos3 >= 30; pos3 -= 1) { // goes from 180 degrees to 0 degrees
    		servoRotate(PWM_CH_7,pos3);              // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_2,pos3);  
    		udelay(5);                       // waits 15ms for the servo to reach the position
  		} 
}

void run()
{		
		int pos1 = 0;
		int pos2 = 30;
		int pos3 = 10;
		//hip
		for (pos1 = 80; pos1 >= 60; pos1 -= 1) { // goes from 0 degrees to 180 degrees
   			servoRotate(PWM_CH_5,pos1);              // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_0,pos1);   
    		udelay(1);                       // waits 15ms for the servo to reach the position
 		 }
  		for (pos1 = 60; pos1 <= 80; pos1 += 1) { // goes from 180 degrees to 0 degrees
    		servoRotate(PWM_CH_5,pos1);               // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_0,pos1);   
    		udelay(1);                       // waits 15ms for the servo to reach the position
  		}
		//knee   
    	for (pos2 = 30; pos2 >= 5; pos2 -= 1) { // goes from 0 degrees to 180 degrees
    		servoRotate(PWM_CH_6,pos2);               // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_1,pos2);  
    		udelay(1);                       // waits 15ms for the servo to reach the position
        }
  		for (pos2 = 5; pos2 <= 30; pos2 += 1) { // goes from 180 degrees to 0 degrees
    		servoRotate(PWM_CH_6,pos2);              // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_1,pos2);  
    		udelay(1);                       // waits 15ms for the servo to reach the position
  		}
		//sholder
		for (pos3 = 30; pos3 <= 50; pos3 += 1) { // goes from 0 degrees to 180 degrees
   
    		servoRotate(PWM_CH_7,pos3);               // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_2,pos3);    
    		udelay(20);                       // waits 15ms for the servo to reach the position
        }
  		for (pos3 = 50; pos3 >= 30; pos3 -= 1) { // goes from 180 degrees to 0 degrees
    		servoRotate(PWM_CH_7,pos3);              // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_2,pos3);    
    		udelay(1);                       // waits 15ms for the servo to reach the position
  		}   
}

void walk()
{
		int pos1 = 0;
		int pos2 = 30;
		int pos3 = 10;
		//hip
		for (pos1 = 80; pos1 >= 40; pos1 -= 1) { // goes from 0 degrees to 180 degrees
   			servoRotate(PWM_CH_5,pos1);              // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_0,pos1);
    		udelay(100);                       // waits 15ms for the servo to reach the position
 		 }
  		for (pos1 = 40; pos1 <= 80; pos1 += 1) { // goes from 180 degrees to 0 degrees
    		servoRotate(PWM_CH_5,pos1);               // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_0,pos1);
    		udelay(20);                       // waits 15ms for the servo to reach the position
  		}
		//knee   
    	for (pos2 = 30; pos2 >= 5; pos2 -= 1) { // goes from 0 degrees to 180 degrees
    		servoRotate(PWM_CH_6,pos2);               // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_1,pos2); 
    		udelay(100);                       // waits 15ms for the servo to reach the position
        }
  		for (pos2 = 5; pos2 <= 30; pos2 += 1) { // goes from 180 degrees to 0 degrees
    		servoRotate(PWM_CH_6,pos2);              // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_1,pos2); 
    		udelay(10);                       // waits 15ms for the servo to reach the position
  		}
		//sholder
		for (pos3 = 30; pos3 <= 50; pos3 += 1) { // goes from 0 degrees to 180 degrees
   
    		servoRotate(PWM_CH_7,pos3);               // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_2,pos3);    
    		udelay(20);                       // waits 15ms for the servo to reach the position
        }
  		for (pos3 = 50; pos3 >= 30; pos3 -= 1) { // goes from 180 degrees to 0 degrees
    		servoRotate(PWM_CH_7,pos3);              // tell servo to go to position in variable 'pos'
			servoRotate(PWM_CH_2,pos3);    
    		udelay(1);                       // waits 15ms for the servo to reach the position
  		} 
}
void rest()
{
	servoRotate(PWM_CH_5,100);  //hip
	servoRotate(PWM_CH_6,0);  //knee
	servoRotate(PWM_CH_7,0);   //sholder
	servoRotate(PWM_CH_0,100);  //hip
	servoRotate(PWM_CH_1,0);   //knee
	servoRotate(PWM_CH_2,0);   //sholder
}

int send_string(char * str)
{
char error;
  while(*str!='\0'){
	 uart_putchar(UART_1,*str, &error);
	if(*str=='\n')
	 uart_putchar(UART_1,'\r', &error);
	str++;
  }
  return 0;
}

void receive_string(char * str)
{
  char error;  
  char data;

  while(1){
	 data = uart_getchar(UART_1, &error);	
	 *str=data;
	  str++;
	 if(data=='\n'){	
	 *str='\r';	
	 break;
	}	
  }
}
int pos = 0;
int pos1 = 0;

void main()
{
	char error;       
	char str[100]={0,};
	printf("\n\r *****************************************************************************");
	printf("\n\r INFO: Connect HC-05 Bluetooth module to UART 1 ");	
	printf("\n\r INFO: Please try to connect the Bluetooth device 'HC-05'");	
	printf("\n\r INFO: Press the 'SCAN' button in VEGA bluetooth App from your Android phone");	
	printf("\n\r *****************************************************************************");

	printf("\n\r Setting up Bluetooth Device \n\r");
	printf("\n\r SEND COMMAND FOR LEGGED ROBOT ONE LEG  \n\r");
	uart_set_baud_rate(UART_1,9600,40000000);
	while(1)
	{
		memset(str,0,sizeof(str));
		receive_string(str);
		if(strncmp(str,"WALK",2)==0)
		{
			for(pos = 0;pos<=20;pos += 1)
			{	
				memset(str,0,sizeof(str));
				receive_string(str);
				printf("%s",str);
				if(strncmp(str,"REST",2)==0)
				{	
					GPIO_write_pin(21,LOW);
					GPIO_write_pin(19,LOW);
					GPIO_write_pin(23,LOW);
					rest();
					break;
				}
				else if(strncmp(str,"RUN",2)==0)
				{
					
					GPIO_write_pin(19,HIGH);
					run();
						
				}
				else if(strncmp(str,"HOP",2)==0)
				{
					hop();
					GPIO_write_pin(23,HIGH);	
				}
				else
				{
					GPIO_write_pin(21,HIGH);
					walk();
					
				}
				
			}

		}

		else if(strncmp(str,"RUN",2)==0)
		{
			for(pos = 0;pos<=20;pos += 1)
			{
				memset(str,0,sizeof(str));
				receive_string(str);
				printf("%s",str);
				if(strncmp(str,"REST",2)==0)
				{
					rest();
					GPIO_write_pin(21,LOW);
					GPIO_write_pin(19,LOW);
					break;
				}
				else if(strncmp(str,"WALK",2)==0)
				{
					walk();
					GPIO_write_pin(21,HIGH);
				}	
				
				else if(strncmp(str,"HOP",2)==0)
				{
					hop();
					GPIO_write_pin(23,HIGH);
						
				}
				else
				{
					run();
					GPIO_write_pin(19,HIGH);
				}
				//break;
			}
		}
		
		else if(strncmp(str,"HOP",2)==0)
		{
			for(pos = 0;pos<=20;pos += 1)
			{
				memset(str,0,sizeof(str));
				receive_string(str);
				printf("%s",str);
				if(strncmp(str,"REST",2)==0)
				{
					rest();
					GPIO_write_pin(21,LOW);
					GPIO_write_pin(19,LOW);
					GPIO_write_pin(23,LOW);
					break;
				}
				else if(strncmp(str,"WALK",2)==0)
				{
					walk();
					GPIO_write_pin(21,HIGH);
					
				}
				else if(strncmp(str,"RUN",2)==0)
				{
					run();
					GPIO_write_pin(19,HIGH);
						
				}
				else
				{
					hop();
					GPIO_write_pin(23,HIGH);
				}
				//break;
			}
		}
		else
		{	
			rest();
			GPIO_write_pin(21,LOW);
			GPIO_write_pin(19,LOW);
			GPIO_write_pin(23,LOW);
	
		}
	}
	
	
}
