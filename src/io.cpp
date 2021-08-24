#include <assert.h>
#include "../include/io.h"

const char *text_color_codes[] = {
    "",
    "\u001b[0m",
    "\u001b[31m",
    "\u001b[32m",
    "\u001b[33m",
    "\u001b[34m",
}; 

const char *background_color_codes[] = {
    "",
    "\u001b[0m",
    "\u001b[41m",
    "\u001b[42m",
    "\u001b[43m",
    "\u001b[44m",
}; 

int set_color(colors text, colors background) {
    return printf("%s%s", text_color_codes[text], 
                          background_color_codes[background]);
}

int getl(char *buffer, const size_t size, FILE *stream) {
    assert(buffer);
    assert(ferror(stream) == 0);

    char c = 0;
    int  i = 0;

    do {
        c = fgetc(stream);
        if (i < size)
            buffer[i++] = c;
    } while (c != '\n' && c != EOF);

    char last = buffer[--i];
    buffer[i] = '\0';

    return (i == (size - 1) && last != '\n' && last != EOF) ? -1 : i;
}
