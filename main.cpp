/*
	@File 		main.cpp
	@Author		JOSIMAR PEREIRA LEITE
	@country	Brazil
	@Date		07/06/2021
	

    Copyright (C) 2021  JOSIMAR PEREIRA LEITE

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/

#define F_CPU 16000000UL

#include <avr/io.h>

#include "tm1628.h"

TM1628 tm1628;

const char TM1628_SEG[] = {0x00,0x02,0x08,0x0A};
const unsigned char TM1628_DIGITS[] = {0x7e,0x30,0x6d,0x79,0x33,0x5b,0x5f,0x70,0x7f,0x7b};

int main(void)
{
	_delay_ms(100);

	// INIT 
	tm1628.Init();

	// COMMAND 1: 7 GRIDS
	tm1628.Command( 0x00 | 0x03 ); 
	
	// COMMAND 2: FIXED ADDRESS
	tm1628.Command( 0x40 | 0x04 );
	
	// COMMAND 3: 
	tm1628.Command( 0xC0 | 0x00 );
		
	// COMMAND 4: TM1628_BRIGHTLESS_2 .. 7
	tm1628.Command( TM1628_DISPLAY_ON | TM1628_BRIGHTLESS_2 );

	tm1628.Data( TM1628_SEG[ 0 ],  TM1628_DIGITS[ 0 ] );
	tm1628.Data( TM1628_SEG[ 1 ],  TM1628_DIGITS[ 1 ] );
	tm1628.Data( TM1628_SEG[ 2 ],  TM1628_DIGITS[ 2 ] );
	tm1628.Data( TM1628_SEG[ 3 ],  TM1628_DIGITS[ 3 ] );
	
    while(1);
}
