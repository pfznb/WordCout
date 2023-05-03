#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1024

int main(int argc, char *argv[]) {
    FILE *fp;
    char *fileName;
    char *mode;
    int charCount = 0, wordCount = 0;
    char str[SIZE];
    int i, len;


    if (argc < 2 || argc > 3) {
        printf("Usage: %s [-c | -w] [input_file_name]\n", argv[0]);
        return 1;
    }
    mode = argv[1];
    if (argc == 3) {
        fileName = argv[2];
    }

	
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        return 1;
    }
    while (fgets(str, SIZE, fp) != NULL) {
        len = strlen(str);
        if (len > 0 && str[len-1] == '\n') {
            str[len-1] = '\0'; 
            len--;
        }
        if (strcmp(mode, "-c") == 0) {
            charCount += len;
        } else if (strcmp(mode, "-w") == 0) {
            for (i = 0; i < len; i++) {
                if (isspace(str[i]) || str[i] == ',') {
                    wordCount++;
                }
            }
            wordCount++;
        } else {
            printf("无");
            return 1;
        }
    }
	puts("");
    fclose(fp);

    if (strcmp(mode, "-c") == 0) {
        printf("字符数为： %d\n", charCount);
    } else {
        printf("单词数为： %d\n", wordCount);
    }

    return 0;
}
