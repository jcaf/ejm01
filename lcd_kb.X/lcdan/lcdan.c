#include <xc.h>
#include <stdint.h>
#include "include_utils/defgrl.h"
#include "lcdan/lcdan.h"

#define LCDAN_PORT 0
#define LCDAN_BIT 1
//#define LCDAN_MODE LCDAN_PORT
#define LCDAN_MODE LCDAN_BIT

#if LCDAN_MODE==LCDAN_PORT

#define PORTWxLCDAN PORTD//LATD
#define PORTRxLCDAN PORTD
#define CONFIGIOxLCDAN TRISD
#define PINxLCDAN_RS 1
#define PINxLCDAN_RW 2
#define PINxLCDAN_E 3

#elif LCDAN_MODE==LCDAN_BIT

#define PORTWxLCDAN_RS LATD
#define PORTRxLCDAN_RS PORTD
#define CONFIGIOxLCDAN_RS TRISD
#define PINxLCDAN_RS 1

#define PORTWxLCDAN_RW LATD
#define PORTRxLCDAN_RW PORTD
#define CONFIGIOxLCDAN_RW TRISD
#define PINxLCDAN_RW 2

#define PORTWxLCDAN_E LATD
#define PORTRxLCDAN_E PORTD
#define CONFIGIOxLCDAN_E TRISD
#define PINxLCDAN_E 3

#define PORTWxLCDAN_D4 LATD
#define PORTRxLCDAN_D4 PORTD
#define CONFIGIOxLCDAN_D4 TRISD
#define PINxLCDAN_D4 4

#define PORTWxLCDAN_D5 LATD
#define PORTRxLCDAN_D5 PORTD
#define CONFIGIOxLCDAN_D5 TRISD
#define PINxLCDAN_D5 5

#define PORTWxLCDAN_D6 LATD
#define PORTRxLCDAN_D6 PORTD
#define CONFIGIOxLCDAN_D6 TRISD
#define PINxLCDAN_D6 6

#define PORTWxLCDAN_D7 LATD
#define PORTRxLCDAN_D7 PORTD
#define CONFIGIOxLCDAN_D7 TRISD
#define PINxLCDAN_D7 7

#endif

inline
void lcdan_set_controlpins_and_datapins_outputs(void)
{
    #if  LCDAN_MODE==LCDAN_PORT
    CONFIGIOxLCDAN &= 0x01;
    #elif  LCDAN_MODE==LCDAN_BIT
    ConfigOutputPin(CONFIGIOxLCDAN_RS, PINxLCDAN_RS);
    ConfigOutputPin(CONFIGIOxLCDAN_RW, PINxLCDAN_RW);
    ConfigOutputPin(CONFIGIOxLCDAN_E, PINxLCDAN_E);
    ConfigOutputPin(CONFIGIOxLCDAN_D4, PINxLCDAN_D4);
    ConfigOutputPin(CONFIGIOxLCDAN_D5, PINxLCDAN_D5);
    ConfigOutputPin(CONFIGIOxLCDAN_D6, PINxLCDAN_D6);
    ConfigOutputPin(CONFIGIOxLCDAN_D7, PINxLCDAN_D7);
    #endif
}

void lcdan_set_datapins_inputs(void)
{
    #if  LCDAN_MODE==LCDAN_PORT
    CONFIGIOxLCDAN = (CONFIGIOxLCDAN & 0x0f) | 0xf0;
    #elif  LCDAN_MODE==LCDAN_BIT
    ConfigInputPin(CONFIGIOxLCDAN_D4, PINxLCDAN_D4);
    ConfigInputPin(CONFIGIOxLCDAN_D5, PINxLCDAN_D5);
    ConfigInputPin(CONFIGIOxLCDAN_D6, PINxLCDAN_D6);
    ConfigInputPin(CONFIGIOxLCDAN_D7, PINxLCDAN_D7);
    #endif
}

void lcdan_set_datapins_outputs(void)
{
    #if  LCDAN_MODE==LCDAN_PORT
    CONFIGIOxLCDAN &= 0x01;
    #elif  LCDAN_MODE==LCDAN_BIT
    ConfigOutputPin(CONFIGIOxLCDAN_D4, PINxLCDAN_D4);
    ConfigOutputPin(CONFIGIOxLCDAN_D5, PINxLCDAN_D5);
    ConfigOutputPin(CONFIGIOxLCDAN_D6, PINxLCDAN_D6);
    ConfigOutputPin(CONFIGIOxLCDAN_D7, PINxLCDAN_D7);
    #endif
}

inline
void lcdan_set_command_mode(void)
{
    #if  LCDAN_MODE==LCDAN_PORT
    PinTo0(PORTWxLCDAN, PINxLCDAN_RS);
    #elif  LCDAN_MODE==LCDAN_BIT
    PinTo0(PORTWxLCDAN_RS, PINxLCDAN_RS);
    #endif
}

inline
void lcdan_set_data_mode(void)
{
    #if  LCDAN_MODE==LCDAN_PORT
    PinTo1(PORTWxLCDAN, PINxLCDAN_RS);
    #elif  LCDAN_MODE==LCDAN_BIT
    PinTo1(PORTWxLCDAN_RS, PINxLCDAN_RS);
    #endif
}

inline
void lcdan_set_write_mode(void)
{
    #if  LCDAN_MODE==LCDAN_PORT
    PinTo0(PORTWxLCDAN, PINxLCDAN_RW);
    #elif  LCDAN_MODE==LCDAN_BIT
    PinTo0(PORTWxLCDAN_RW, PINxLCDAN_RW);
    #endif
}

inline
void lcdan_set_read_mode(void)
{
    #if  LCDAN_MODE==LCDAN_PORT
    PinTo1(PORTWxLCDAN, PINxLCDAN_RW);
    #elif  LCDAN_MODE==LCDAN_BIT
    PinTo1(PORTWxLCDAN_RW, PINxLCDAN_RW);
    #endif
}
//------------------------------------------------------------------------------
//AC Characteristics (VCC = 2.7 to 4.5 V, T a = ?30 to +75�C* 3 ) - peor caso
//write operation

#define lcdan_delay_writeop_tAS() do{__delay_us(1);}while(0)//min 60ns
//#define lcdan_delay_writeop_tEr() do{__delay_us(1);}while(0)//min 25ns
//#define lcdan_delay_writeop_PWEH() do{__delay_us(1);}while(0)//min 450ns
#define lcdan_delay_writeop_tER_PWEH() do{__delay_us(1);}while(0)//

//#define lcdan_delay_writeop_tEf() do{__delay_us(1);}while(0)//min 25ns
//#define lcdan_delay_writeop_tAH() do{__delay_us(1);}while(0)//min 20ns
#define lcdan_delay_writeop_tEf_tAH() do{__delay_us(1);}while(0)//

//#define lcdan_delay_writeop_tDSW() do{__delay_us(1);}while(0)//min 195ns
//#define lcdan_delay_writeop_tH() do{__delay_us(1);}while(0)//min 10ns

//read operation
#define lcdan_delay_readop_tAS() do{__delay_us(1);}while(0)//min 60ns

//#define lcdan_delay_readop_tEr() do{__delay_us(1);}while(0)//min 25ns
//#define lcdan_delay_readop_tDDR() do{__delay_us(1);}while(0)//max 360ns
#define lcdan_delay_readop_tEr_tDDR() do{__delay_us(1);}while(0)//min 25ns+360ns

//#define lcdan_delay_readop_PWEH() do{__delay_us(1);}while(0)//min 450ns
#define lcdan_delay_readop_PWEH_minus_tEr_tDDR() do{__delay_us(1);}while(0)//450ns-(25ns+360ns)

//#define lcdan_delay_readop_tEf() do{__delay_us(1);}while(0)//min 25ns

//#define tcycE() do{__delay_us(1);}while(0)//min 1000ns
#define lcdan_delay_readop_tcycE_minus_PWEH() do{__delay_us(1);}while(0)//min 1000ns - PWEH

#define lcdan_delay_init() do{__delay_ms(10);__delay_ms(10);__delay_ms(10);__delay_ms(10);}while(0)
//------------------------------------------------------------------------------

void lcdan_strobe_enable(void)
{
    #if  LCDAN_MODE==LCDAN_PORT
    lcdan_delay_writeop_tAS();
    PinTo1(PORTWxLCDAN, PINxLCDAN_E);
    lcdan_delay_writeop_tER_PWEH();
    PinTo0(PORTWxLCDAN, PINxLCDAN_E);
    lcdan_delay_writeop_tEf_tAH();
    #elif  LCDAN_MODE==LCDAN_BIT
    lcdan_delay_writeop_tAS();
    PinTo1(PORTWxLCDAN_E, PINxLCDAN_E);
    lcdan_delay_writeop_tER_PWEH();
    PinTo0(PORTWxLCDAN_E, PINxLCDAN_E);
    lcdan_delay_writeop_tEf_tAH();
    #endif
}

inline
void lcdan_set_and_latch_4bits(uint8_t data)//high nibble
{
    #if LCDAN_MODE == LCDAN_PORT
    PORTWxLCDAN = (data & 0xf0) | (PORTWxLCDAN & 0x0f);

    #elif LCDAN_MODE == LCDAN_BIT
    if (data & 0x80)
        PinTo1(PORTWxLCDAN_D7, PINxLCDAN_D7);
    else
        PinTo0(PORTWxLCDAN_D7, PINxLCDAN_D7);

    if (data & 0x40)
        PinTo1(PORTWxLCDAN_D6, PINxLCDAN_D6);
    else
        PinTo0(PORTWxLCDAN_D6, PINxLCDAN_D6);

    if (data & 0x20)
        PinTo1(PORTWxLCDAN_D5, PINxLCDAN_D5);
    else
        PinTo0(PORTWxLCDAN_D5, PINxLCDAN_D5);

    if (data & 0x10)
        PinTo1(PORTWxLCDAN_D4, PINxLCDAN_D4);
    else
        PinTo0(PORTWxLCDAN_D4, PINxLCDAN_D4);
    #endif
    lcdan_strobe_enable();
}

inline
void lcdan_set_and_latch_8bits(uint8_t data)
{
    lcdan_set_and_latch_4bits(data);
    lcdan_set_and_latch_4bits(data << 4);
}

uint8_t lcdan_get_data(void)
{
    #if LCDAN_MODE == LCDAN_PORT
    return (PORTRxLCDAN & 0xF0);
    #elif LCDAN_MODE == LCDAN_BIT
    return (ReadPin(PORTRxLCDAN_D7, PINxLCDAN_D7) << 7) |
            (ReadPin(PORTRxLCDAN_D6, PINxLCDAN_D6) << 6) |
            (ReadPin(PORTRxLCDAN_D5, PINxLCDAN_D5) << 5) |
            (ReadPin(PORTRxLCDAN_D4, PINxLCDAN_D4) << 4);
    #endif
}

uint8_t lcdan_test_busy(void)
{
    uint8_t busy_addr, i;

    lcdan_set_datapins_inputs();
    lcdan_set_command_mode();
    lcdan_set_read_mode();

    lcdan_delay_readop_tAS();

    //Enable cycle time tcycE 500ns min
    do
    {
        for (i = 0; i < 2; i++)
        {
            #if LCDAN_MODE == LCDAN_PORT
            PinTo1(PORTWxLCDAN, PINxLCDAN_E);
            #elif LCDAN_MODE == LCDAN_BIT
            PinTo1(PORTWxLCDAN_E, PINxLCDAN_E);
            #endif
            lcdan_delay_readop_tEr_tDDR();
            //data present, read
            if (i == 0)
            {
                busy_addr = lcdan_get_data() & 0xF0;
            }
            else
            {
                busy_addr |= (lcdan_get_data() >> 4);
            }

            lcdan_delay_readop_PWEH_minus_tEr_tDDR();
            #if LCDAN_MODE == LCDAN_PORT
            PinTo0(PORTWxLCDAN, PINxLCDAN_E);
            #elif LCDAN_MODE == LCDAN_BIT
            PinTo0(PORTWxLCDAN_E, PINxLCDAN_E);
            #endif
            lcdan_delay_readop_tcycE_minus_PWEH(); //completando tcycE
        }

    }
    while (busy_addr & 0x80);

    lcdan_set_datapins_outputs();
    return busy_addr;
}

void lcdan_write_cmd(uint8_t cmd)
{
    lcdan_test_busy();
    lcdan_set_command_mode();
    lcdan_set_write_mode();
    lcdan_set_and_latch_8bits(cmd);
}

void lcdan_write_data(uint8_t data)
{
    lcdan_test_busy();
    lcdan_set_data_mode();
    lcdan_set_write_mode();
    lcdan_set_and_latch_8bits(data);
}

void lcdan_init(void)
{
    lcdan_set_controlpins_and_datapins_outputs();
    lcdan_delay_init(); //40ms
    lcdan_set_command_mode();
    lcdan_set_write_mode();
    lcdan_set_and_latch_4bits(0x30); //1 function set
    __delay_ms(6); //>4.1ms
    lcdan_set_and_latch_4bits(0x30); //2 function set
    __delay_us(120); //>100us
    lcdan_set_and_latch_4bits(0x30); //3 function set
    //__delay_us(150);                   //isis compatibility
    lcdan_set_and_latch_4bits(0x20); //DataLength = 4bits
    lcdan_strobe_enable();
    //From now on as 8 Bits.
    lcdan_write_cmd(0x28); //4 bits, 2 lines, font 5x8
    lcdan_write_cmd(LCDAN_DISP_OFF); //Display OFF
    lcdan_write_cmd(LCDAN_DISP_CLEAR); //Clear Display/According to the data sheet most instructions take 3 cycles except "Clear display" which takes 165. Suggest
    lcdan_write_cmd(0x06); //Entry Mode Incremental, no shift
    //end LCD initialization
    lcdan_write_cmd(LCDAN_DISP_ON_CURSOR_OFF_BLINK_OFF); //On display Display Control
}
