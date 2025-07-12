#ifndef STRING_H
#define STRING_H


#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *strdup(const char *);
void log_message(const char *, const char *, ...);


#endif