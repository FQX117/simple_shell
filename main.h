#ifndef MAIN_H
#define MAIN_H
/* Headers*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdarg.h>
#include "printf-main/_putchar.c"
#include "printf-main/1-C.c"
#include "printf-main/2-Put_string.c"
#include "printf-main/3-I_and_D.c"
#include "printf-main/0-_printf.c"
#define PRMTSIZ 255
#define MAXARGS 63
#define EXITCMD "exit"



/*Prototypes*/
int _putchar (char c, int *k);
int _printf(const char *format, ...);
int _numbers(va_list arg, int *k);
int _string(va_list p, int *k);
int _char(va_list p, int *k);
int main(void);


#endif
