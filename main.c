/*
 * walker10bit.c
 *  EXAMPLE USE OF THE LIBRARIES.
 * Created: 8/13/2021 5:26:39 PM
 * Author : audiodiWHY
 */ 

#include <avr/io.h>
#include "MCP4911.h"
#include "MCP4921.h"
#include "spi3.h"






int main(void)
{
    UartInit();
    init_spi_master();

    spi_mode(0);

    /* Replace with your application code */
    while (1) 
    {
    
	   for (uint16_t x = 0; x < 1025; x++)
	   {
		write4911(x);
	   }
	
	   	   for (uint16_t x = 0; x < 4097; x++)
	   {
		write4921(x);
	   } 
	    
	}
}

