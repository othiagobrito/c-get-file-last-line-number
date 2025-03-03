#include <stdio.h>

void get_last_line_number(const char *filepath) {
    FILE *file = fopen(filepath, "rb");

    if (! file) return;

    fseek(file, 0, SEEK_END);

    long file_size = ftell(file);

    if (file_size == 0) {
        printf("%i", 0);

        return;
    }

    long position = file_size - 1;

    int ch, line_number = 1;

    while (position > 0) {
        fseek(file, position, SEEK_SET);

        ch = fgetc(file);

        if (ch == '\n') break;
        
        position--;
    }

    if (position > 0) {
        rewind(file);

        line_number = 1;

        while ( (ch = fgetc(file)) != EOF ) {
            if ( ch == '\n' ) line_number++;
        }
    }

    fclose(file);

    printf("%i", line_number);
}

int main() {
    get_last_line_number("./storage/file.txt");

    return 0;
}
