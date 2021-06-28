#include "uart.h"
#include "stdlib.h"
#include "config.h"
#include "gpio.h"
#include <string.h>
#include "pwmc.h"
#include "servo.h"
#include "debug_uart.h"

#define SYS_CLK_FREQ 40000000UL
#define DISABLE 0
#define ENABLE 1


void walk(count){

	int pos1 = count;
	int pos2 = count;

	if(count == 1){
		for (pos1 = 0; pos1 <= 20; pos1 += 1) { // goes from 0 degrees to 180 degrees
		    // in steps of 1 degree
		   servoRotate(PWM_CH_6,pos1);	              // tell servo to go to position in variable 'pos'
		   printf("x\n");
		   udelay(5000);
		  }
		for (pos2 = 0; pos2 <= 20; pos2 += 1) { // goes from 0 degrees to 180 degrees
		    // in steps of 1 degree
		   servoRotate(PWM_CH_7,pos2);	              // tell servo to go to position in variable 'pos'
		   printf("y\n");
		   udelay(5000);
		  }
		for (pos2 = 20; pos2 >= 0; pos2-= 1) { // goes from 0 degrees to 180 degrees
		    // in steps of 1 degree
		   servoRotate(PWM_CH_7,pos2);	              // tell servo to go to position in variable 'pos'
		   printf("z\n");
		   udelay(5000);
		  }
		for (pos1 = 20; pos1 >= 0; pos1 -= 1) { // goes from 0 degrees to 180 degrees
		    // in steps of 1 degree
		   servoRotate(PWM_CH_6,pos1);	              // tell servo to go to position in variable 'pos'
		   printf("x\n");
		   udelay(5000);
		  }
	}
	else{
		servoRotate(PWM_CH_6,0);
		servoRotate(PWM_CH_7,0);
	}
}


void run(){

	int pos1 = 0;
	int pos2 = 0;

	while(1){
		for (pos1 = 0; pos1 <= 20; pos1 += 1) { // goes from 0 degrees to 180 degrees
		    // in steps of 1 degree
		   servoRotate(PWM_CH_6,pos1);	              // tell servo to go to position in variable 'pos'
		   printf("x\n");
		   udelay(2000);
		  }
		for (pos2 = 0; pos2 <= 20; pos2 += 1) { // goes from 0 degrees to 180 degrees
		    // in steps of 1 degree
		   servoRotate(PWM_CH_7,pos2);	              // tell servo to go to position in variable 'pos'
		   printf("y\n");
		   udelay(2000);
		  }
		for (pos2 = 20; pos2 >= 0; pos2-= 1) { // goes from 0 degrees to 180 degrees
		    // in steps of 1 degree
		   servoRotate(PWM_CH_7,pos2);	              // tell servo to go to position in variable 'pos'
		   printf("z\n");
		   udelay(2000);
		  }
		for (pos1 = 20; pos1 >= 0; pos1 -= 1) { // goes from 0 degrees to 180 degrees
		    // in steps of 1 degree
		   servoRotate(PWM_CH_6,pos1);	              // tell servo to go to position in variable 'pos'
		   printf("x\n");
		   udelay(2000);
		  }
	}
	
}
void rest(){

	while(1){
		servoRotate(PWM_CH_6,0);	              
		servoRotate(PWM_CH_7,0);
	}
	
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



/**
 @fn main
 @brief transmit and reception through uart
 @details 1 character is transmitted and received through uart
 @param[in] No input parameter.
 @param[Out] No ouput parameter.
 @return Void function.
 */
void main() {
	char error;       
	char str[100]={0,};
	int count = 0;
	printf("%d",count);
	printf("\n\r *****************************************************************************");
	printf("\n\r INFO: Connect HC-05 Bluetooth module to UART 1 ");	
	printf("\n\r INFO: Please try to connect the Bluetooth device 'HC-05'");	
	printf("\n\r INFO: Press the 'SCAN' button in VEGA bluetooth App from your Android phone");	
	printf("\n\r *****************************************************************************");

	printf("\n\r Setting up Bluetooth Device \n\r");
	printf("\n\r pupper \n\r");
	uart_set_baud_rate(UART_1,9600,40000000);
    //start();
while(1){
		memset(str,0,sizeof(str));
		receive_string(str);	
		printf("%s", str);
		if(strncmp(str,"WALK",2)==0)
		{	
			count =  1;
			walk(count);
			
			
		}
		else if(strncmp(str,"RUN",2)==0)
		{	
			//count = count + 1;
			//printf("%d",count);
		}
		else
		{
			count = 0;
			walk(count);
			//printf("%d",count);
			//servoRotate(PWM_CH_6,0);
		}
			

	}

}

	
	
