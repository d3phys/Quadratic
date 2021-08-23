#include <assert.h>
#include "../include/io.h"

int getl(char *buffer, const size_t size, FILE *stream) {
    assert(buffer);

    char c = 0;
    int i = 0;

    do {
        c = fgetc(stream);
        if (i < size)
            buffer[i++] = c;
    } while (c != '\n' && c != EOF);

    char last = buffer[--i];
    buffer[i] = '\0';

    return (i == (size - 1) && last != '\n' && last != EOF) ? -1 : i;
}
