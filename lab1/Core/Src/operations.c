#include "main.h"
#include <string.h>
#include "operations.h"
#include "config.h"
#include <stdio.h>

extern int8_t current_col;
extern int8_t current_row;
extern int8_t ans;
extern int8_t num1;
extern int8_t num2;

int8_t add(int8_t num1, int8_t num2){
	return num1+num2;
}

int8_t subtract(int8_t num1, int8_t num2){
	return num1-num2;
}

void print_key(char* message){
	char key_pressed_c;
	char op;
	sprintf(message, "\nRow: %d Col: %d ", current_row, current_col);
	print_msg(message);
	
	key_pressed_c=(current_row*4)+current_col+'0';
	if(key_pressed_c>57)
		key_pressed_c=key_pressed_c+39;
	sprintf(message, "Key pressed: %c \n", key_pressed_c);
	print_msg(message);
	
	/* Calculator function (doesn't work yet) --------------------------------------------------------*/
	if((num1!=-1) && (num2!=-1)){
		if (key_pressed_c==58){
			op=43;
			ans=add(num1,num2);
		}
		else if (key_pressed_c==59){
			op=45;
			ans=subtract(num1,num2);
		}
		if (ans!=-1){
			sprintf(message, "You calculated %d %c %d = %d \n", num1,op,num2,ans);
			print_msg(message);
		}
		num1=num2=ans=-1;
	}
			
	if ((num1==-1)&&(key_pressed_c<58))
		num1=(current_row*4)+current_col;
	else if ((num2==-1)&&(key_pressed_c<58))
		num2=(current_row*4)+current_col;
	
	
}
