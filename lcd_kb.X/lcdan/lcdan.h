/* 
 * File:   lcdan.h
 * Author: Katherine
 *
 * Created on 8 de febrero de 2015, 05:18 PM
 */


#ifndef LCDAN_H
#define	LCDAN_H


void lcdan_write_cmd(uint8_t cmd);
void lcdan_write_data(uint8_t data);
void lcdan_init(void);


#define	LCDAN_DISP_ON_CURSOR_ON_BLINK_ON		(0x0F)  //0b00001111	//Display on, cursor on, blink on
#define	LCDAN_DISP_ON_CURSOR_OFF_BLINK_ON		(0x0D)  //0b00001101	//Display on, cursor on, blink on
#define	LCDAN_DISP_ON_CURSOR_OFF_BLINK_OFF		(0x0C)  //0b00001100	//Display on, cursor oFF, blink OFF
#define	LCDAN_DISP_ON_CURSOR_ON_BLINK_OFF		(0x0E)  //0b00001110	//Display on, cursor oFF, blink OFF
#define LCDAN_DISP_CLEAR                              (0x01)	//0b00000001 Aclarar display
#define LCDAN_DISP_OFF				(0x08)	//0b00001000	Apaga el display

#define LCDAN_DISP_CURSOR_DISPLAY_SHIFT (0x10)
#define LCDAN_DISP_DISPLAY_SHIFT (0x08)
#define LCDAN_DISP_CURSOR_MOVE (0x00)

#define LCDAN_XY_FILA_0 (0x80)
#define LCDAN_XY_FILA_1 (0xC0)



#define SHIFT_TO_RIGHT                  (0x04)
#define SHIFT_TO_LEFT                   (0x00)

#define ENTRY_MODE_SET                  (0x04)
#define INCREMENT                       (0x02)
#define DECREMENT                       (0x00)

#define AUTOMATIC_DISPLAY_SHIFT 	    (0x01)
#define NO_AUTOMATIC_DISPLAY_SHIFT      (0x00)

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LCDAN_H */

