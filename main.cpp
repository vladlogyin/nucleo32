/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "platform/mbed_thread.h"

DigitalIn but(PB_4);
BusOut SevenDisplay(PA_2,PA_7,PA_6,PA_5,PA_4,PA_3,PA_1,PA_0); //In reverse order: Middle, left up, up, right up, left down, down, right down, decimal point 

int main()
{
but.mode(PullUp);
uint8_t fonk[10]={0b01111110,0b00010010,0b10111100,0b10110110,0b11010010,0b11100110,0b11101110,0b00110010,0b11111110,0b11110110} ;
int i=0;
while(true)
{
    if (!but)
    {
    while(!but);    
    SevenDisplay=fonk[i];
    i++;
    wait(0.1);
    }
    if (i==10)
    {i=0;}
}
}

