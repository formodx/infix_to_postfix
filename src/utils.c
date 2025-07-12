#include "utils.h"


char *strdup(const char *s){
    size_t length = strlen(s);
    char *buffer = malloc(length + 1);
    memcpy(buffer, s, length);
    buffer[length] = '\0';

    return buffer;
}


void log_message(const char *level, const char *format, ...){
    FILE *file = fopen("log", "a");
    if(file == NULL){
        perror("log_message");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "[%s] ", level);

    va_list args;
    va_start(args, format);
    vfprintf(file, format, args);
    va_end(args);

    fprintf(file, "\n");
    fclose(file);
}