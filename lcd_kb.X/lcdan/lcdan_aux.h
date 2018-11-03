/* 
 * File:   lcdan_aux.h
 * Author: jcaf
 *
 * Created on February 12, 2015, 10:24 AM
 */

#ifndef LCDAN_AUX_H
#define	LCDAN_AUX_H

#define LCDAN_XY_FILA_0 (0x80)
#define LCDAN_XY_FILA_1 (0xC0)

#define lcdan_set_pos_f0(pos) do{lcdan_write_cmd(LCDAN_XY_FILA_0|pos);}while(0)
#define lcdan_set_pos_f1(pos) do{lcdan_write_cmd(LCDAN_XY_FILA_1|pos);}while(0)

void lcdan_print_string(const char *p);

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* LCDAN_AUX_H */

