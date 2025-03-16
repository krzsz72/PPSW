#include <LPC21xx.H>
#include <stdio.h>

//#define NULL '\0';

void lancuchy1(){
	IO1DIR = 0x1;
	IO1SET = 0x1;
}
