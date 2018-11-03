/* 
 * File:   lcdan_aux.c
 * Author: jcaf
 *
 * Created on February 12, 2015, 10:19 AM
 */

#include <xc.h>
#include <stdint.h>
#include "include_utils/defgrl.h"
#include "lcdan/lcdan.h"


void lcdan_print_string(const char *p)
{
    while (*p)
    {
        lcdan_write_data(*p);
        p++;
    }
}

