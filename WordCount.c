#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    int count = 0;
    int wordCount = 0;
    int isWord = 0; // 标记是否处于一个单词中

    if (argc != 3) {
        printf("Usage: WordCount -[c/w] input_file_name\n");
        return 1;
    }

    if (strcmp(argv[1], "-c") != 0 && strcmp(argv[1], "-w") != 0) {
        printf("Invalid parameter. Please use '-c' or '-w'.\n");
        return 1;
    }

    fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Cannot open file: %s\n", argv[2]);
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        count++;
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == ',') {
            isWord = 0;
        } else if (isWord == 0) {
            isWord = 1;
            wordCount++;
        }
    }

    fclose(fp);

    if (strcmp(argv[1], "-c") == 0) {
        printf("countofcharacters: %d\n", count);
    } else {
        printf("countofwords: %d\n", wordCount);
    }

    return 0;
}