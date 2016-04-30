//#include "madlib-by-numbers.h"

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int newLen(char* template, int word_count, char* words[]) {
    int count = 0;
    int stringlen = strlen(template);
    int digit;
    for (int i = 0; i < stringlen; i++) {
        if (isdigit(template[i]) && !(template[i] - '0' > word_count - 1 )) {
            digit = (template[i] - '0');
            count = count + strlen(words[digit]);
        } else {
            count++;
        }
    }
    return count;
}

char* madlib_by_numbers(char* template, int word_count, char* words[]) {
    
    int length = newLen(template, word_count, words);
    char* concatStr = calloc(length + 1, 1);
    int digit;
    int wordlen;
    int pointer = 0;
    
    for (int i = 0; i < strlen(template); i++) {
        if (isdigit(template[i]) && !(template[i] - '0' > word_count - 1)) {
            digit = (template[i] - '0');
            wordlen = strlen(words[digit]);
            strcat(&concatStr[pointer], words[digit]);
            pointer = pointer + wordlen;
        } else {
            concatStr[pointer] = template[i];
            pointer++;
        }
    }
    //printf("%s\n", concatStr);
    return concatStr;
}
