/*
	@File 		tm1628.cpp
	@Author		JOSIMAR PEREIRA LEITE
	@country	Brazil
	@Date		07/06/2021
	

    Copyright (C) 2021  JOSIMAR PEREIRA LEITE

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/

#include "tm1628.h"

#include <avr/io.h>

void TM1628::Write(unsigned char data)
{
	for (int i=0; i<8; i++)
	{
		TM1628_SCK_LOW; 
		
		if (data & (1 << i))
		TM1628_MOSI_HIGH;
		else
		TM1628_MOSI_LOW;
		
		TM1628_SCK_HIGH;
	}
}

void TM1628::Command(unsigned char data)
{
	TM1628_CS_LOW;
	
	TM1628::Write(data);
	
	TM1628_CS_HIGH;
}

void TM1628::Data(unsigned char address, unsigned char data)
{
	TM1628::Command(0x44);
	
	TM1628_CS_LOW;
	
	TM1628::Write(0xC0 | address);
	TM1628::Write(data);
	
	TM1628_CS_HIGH;
}

void TM1628::SetBright(unsigned char bright)
{
	char DisplayLight[] = {0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F};
	bright = (bright % 7);
	Command( DisplayLight[ bright ] );
}

void TM1628::Init()
{
	DDRD |= (1<<TM1628_MOSI);
	DDRD |= (1<<TM1628_SCK);
	DDRD |= (1<<TM1628_CS);
	
	TM1628_SCK_HIGH;
	TM1628_CS_HIGH;

	// COMMAND 1: 7 GRIDS
	Command( 0x00 | 0x03 );

	// COMMAND 2: FIXED ADDRESS
	Command( 0x40 | 0x04 );

	// COMMAND 3:
	Command( 0xC0 | 0x00 );

	// COMMAND 4: 001 : Pulse width = 2/16
	Command( TM1628_DISPLAY_ON | TM1628_BRIGHTLESS_7 );
}
