#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void process_text(FILE* istream) {
    int c;
    long long line_count = 0, word_count = 0, char_count = 0;
    bool is_prev_space = true;

    while ((c = fgetc(istream)) != EOF) {
        if (c == '\n') {
            ++line_count;
        }

        if (!isspace(c) && is_prev_space) {
            ++word_count;
        }

        is_prev_space = isspace(c);
        ++char_count;
    }

    printf("%llu\n%llu\n%llu\n", line_count, word_count, char_count);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        process_text(stdin);
        return EXIT_SUCCESS;
    }

    if (argc == 2) {
        char* filename = argv[1];
        FILE* file = fopen(filename, "r");

        if (file == NULL) {
            perror(filename);
            return EXIT_FAILURE;
        }

        process_text(file);

        fclose(file);
        return EXIT_SUCCESS;
    }

    puts("Error: an unexpected number of arguments");
}
