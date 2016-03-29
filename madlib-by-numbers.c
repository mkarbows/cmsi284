//
//  madlib-by-numbers.c
//  
//
//  Created by Megan Karbowski on 3/28/16.
//
//

#include "madlib-by-numbers.h"

#include <string.h>
#include <stdlib.h>

//madlib_by_numbers("The 1 2 likes to 0 in the 1 moonlight.", "swim", "brilliant", "git")
//
//"The brilliant git likes to swim in the brilliant moonlight."

char* madlib_by_numbers(char* template, int word_count, char* words[]) {
    char* wordArray[sizeof((char*) words)];
    
    int size = (strlen(template) + (sizeof((char*) words)));
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += strlen(template[i] + words[i]);
    }
    
    char* concatStr = (char*)malloc(sizeof(char) * (total + 1));
    
    if (word_count != sizeof((char*) words)) {
        printf("please enter the same amount of words as your word count");
    }
    
    int numArray[10];
    
    for (int i = 0; i < strlen(template); i++) {
        if (isdigit(template[i])) {
            numArray[i] = atoi(&template[i]);
        }
    }
    
    for (int i = 0; i < strlen(template); i++) {
        strncat(concatStr, words[numArray[i]], strlen(words[numArray[i]]));
    }
    
}