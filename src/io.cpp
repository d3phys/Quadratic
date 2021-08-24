#include <assert.h>
#include "../include/io.h"

int set_text_color(color text) {
    return printf("\u001b[3%dm", text);
}

int set_back_color(color background) {
    return printf("\u001b[4%dm", background);
}

int reset_color() {
    return printf("\u001b[0m");
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
