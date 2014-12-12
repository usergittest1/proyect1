#include <stdio.h> 
/* Replace next line: Include the device system header file here */
//#error "device include file missing"
/* e.g.: #include "STM32F2xx.h" */
#include "stm32f4xx.h"                  // Device header
 
//#pragma import(__use_no_semihosting_swi)


volatile int ITM_RxBuffer = ITM_RXBUFFER_EMPTY;  /*  CMSIS Debug Input        */

struct __FILE{
	void * handler;
};

FILE __stdout={(void*)0};
FILE __stdin={(void*)0};

int fputc(int c, FILE *f) {
  return (ITM_SendChar(c));
}

int fgetc(FILE *f) {
  while (ITM_CheckChar() != 1) __NOP();
  return (ITM_ReceiveChar());
}

int ferror(FILE *f) {
  /* Your implementation of ferror */
  return EOF;
}