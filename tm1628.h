/*
	@File 		tm1628.h
	@Author		JOSIMAR PEREIRA LEITE
	@country	Brazil
	@Date		07/06/2021
	

    Copyright (C) 2021  JOSIMAR PEREIRA LEITE

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/

#ifndef TM1628_H_
#define TM1628_H_
	
#define TM1628_MOSI						PD2
#define TM1628_CS						PD1
#define TM1628_SCK						PD0

#define TM1628_CS_LOW					PORTD &= (unsigned char )~(1<<TM1628_CS)
#define TM1628_CS_HIGH					PORTD |= (1<<TM1628_CS)

#define TM1628_MOSI_LOW					PORTD &= (unsigned char )~(1<<TM1628_MOSI)
#define TM1628_MOSI_HIGH				PORTD |= (1<<TM1628_MOSI)

#define TM1628_SCK_LOW					PORTD &= (unsigned char )~(1<<TM1628_SCK)
#define TM1628_SCK_HIGH					PORTD |= (1<<TM1628_SCK)

#define TM1628_DISPLAY_ON				0x88
#define TM1628_DISPLAY_OFF				0x00

#define TM1628_BRIGHTLESS_0				0x88
#define TM1628_BRIGHTLESS_1				0x89
#define TM1628_BRIGHTLESS_2				0x8A
#define TM1628_BRIGHTLESS_3				0x8B
#define TM1628_BRIGHTLESS_4				0x8C
#define TM1628_BRIGHTLESS_5				0x8D
#define TM1628_BRIGHTLESS_6				0x8E
#define TM1628_BRIGHTLESS_7				0x8F

class TM1628
{
	public:
		void Write(unsigned char data);
		void Command(unsigned char data);
		void Data(unsigned char address, unsigned char data);
		void SetBright(unsigned char bright);
		void Init();
};

#endif /* TM1628_H_ */
