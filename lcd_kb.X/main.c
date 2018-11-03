
#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "include_utils/defgrl.h"
#include "lcdan/lcdan.h"
#include "lcdan/lcdan_aux.h"

//pic18f452 relevante
#pragma config "OSC=HS","OSCS=OFF","PWRT=ON","BOR=OFF","BORV=20","WDT=OFF","LVP=OFF","DEBUG=OFF"
//pic18f452 dependent
//#pragma config "STVR = ON"
//#pragma config "WDTPS = 128"
//#pragma config "CCP2MUX = ON"
//#pragma config "CP0 = OFF","CP1 = OFF" ,"CP2 = OFF","CP3 = OFF"
//#pragma config "CPB = OFF","CPD = OFF"
//#pragma config "WRT0 = OFF","WRT1 = OFF", "WRT2 = OFF","WRT3 = OFF"
//#pragma config "WRTC = OFF" ,"WRTB = OFF","WRTD = OFF"
//#pragma config "EBTR0 = OFF","EBTR1 = OFF","EBTR2 = OFF","EBTR3 = OFF"
//#pragma config "EBTRB = OFF"

//PIC16F877A
//#pragma config "FOSC=HS", "PWRTE=ON", "WDTE=OFF", "BOREN=OFF", "DEBUG=OFF", "LVP=OFF", "CPD=OFF", "CP=OFF"

inline
void _delay1s(void)
{
    int i;
    for (i=0; i<100; i++)
    {
        __delay_ms(10);
        //__delaywdt_ms(25);
    }
}


void main(void)
{
    uint16_t n=0;
    char buff[10];

    lcdan_init();

//    lcdan_write_data('1');
//    lcdan_write_data('2');
//    lcdan_print_string("juan carlos");

    while (1)
    {
        for (n=0;n<60;n++)
        {
            lcdan_set_pos_f0(0);
            sprintf(buff,"%i",n);
            lcdan_print_string(buff);
            _delay1s();
        }
        
    }

}

