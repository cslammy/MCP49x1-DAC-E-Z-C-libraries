/*
 * MCP4911.c
 *
 * Created: 3/22/2021 11:07:45 AM
PUT THESE 2 lines onto main.c {} file but before while(1) loop.


init_spi_master();
spi_mode(0);




 *  Author: audioDIWHY
*/

#include <stdio.h>
#include "MCP4911.h"
#include "spi3.h"

uint8_t MSBwcontrol = 0;

void write4911(uint16_t data)
    {
	
    {
	
        // code assumes LDAC (4911 pin 5) tied to ground
		uint16_t data12 = data & 0b0000111111111111; // we only want 12 LSBs
		
		

	
		uint8_t MSB = (data12 >> 8);
		MSB |= (1 << 6) | (1 << 5) | (1 << 4) ; // buffered ref in, gain = ref; no shutdown
 
		MSB &= ~(1 << 7);  // this control must be zero always
 
		uint8_t LSB = data12 & 0x00FF;
		
		
		
		

 
		
		
	    // for 4911, you send 2 bytes.  bit 15 is always zero,
	    // bits 14,13,12 are control, 11-10-9-8 are MSBs data 
		//  7 6 5 4 3 2 x x are LSB data
	    
	     

	    //send the data.  4911 can eat 16 bit xfers.
	    SELECT();

        SPI_SendByte(MSB);
      //  SPI_SendByte(0b01110111);
		SPI_SendByte(LSB);
	 //   SPI_SendByte(0x00);
		DESELECT();
	
	    
    }

	
	    
    }
