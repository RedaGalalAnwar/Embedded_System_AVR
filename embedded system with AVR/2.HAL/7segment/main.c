#define F_CPU 8000000UL
#include <util//delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_interfacing.h"
#include "segment_config.h"
#include "segment_interfacing.h"




int main(void)
{
u8 x=9;
for (x;;x--)
{
	//if(i<0) i=x;
Segment_Display(x);
_delay_ms(500);	
}




    while (1) 
    {
		
		
    }
}

