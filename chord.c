//
//  chord.c
//  
//
//  Created by Megan Karbowski on 3/20/16.
//
//


#include <stdio.h> //allows us to use print f
#include <stdlib.h> //malloc in here
#include <string.h>

char* keySig[] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};

void majorKeys(char* key) {
    
    char* originalKey = key;
    char* secondKey;
    char* thirdKey;
        
    for (int i = 0; i < 11; i++) {
        if (strcmp(originalKey, keySig[i]) == 0) {
            secondKey = keySig[((i+4)%12)];
            thirdKey = keySig[((i+7)%12)];
            break;
        }
    }
    printf("%s: %s %s %s\n", originalKey, originalKey, secondKey, thirdKey);
}

void minorKeys(char* key) {
    
    char* originalKey = key;
    char* secondKey;
    char* thirdKey;
        
    for (int i = 0; i < 11; i++) {
        if (strcmp(key, keySig[i]) == 0) {
            secondKey = keySig[(i+3)%12];
            thirdKey = keySig[(i+7)%12];
            break;
        }
    }
    printf("%sm: %s %s %s\n", originalKey, originalKey, secondKey, thirdKey);
}

void dom7(char* key) {
    
    char* originalKey = key;
    char* secondKey;
    char* thirdKey;
    char* fourthKey;
        
    for (int i = 0; i < 11; i++) {
        if (strcmp(key, keySig[i]) == 0) {
            secondKey = keySig[((i+4)%12)];
            thirdKey = keySig[((i+7)%12)];
            fourthKey = keySig[((i+10)%12)];
            break;
        }
    }
    printf("%s7: %s %s %s %s\n", originalKey, originalKey, secondKey, thirdKey, fourthKey);
}

void dim7(char* key) {
    
    char* originalKey = key;
    char* secondKey;
    char* thirdKey;
    char* fourthKey;
        
    for (int i = 0; i < 11; i++) {
        if (strcmp(key, keySig[i]) == 0) {
            secondKey = keySig[((i+3)%12)];
            thirdKey = keySig[((i+6)%12)];
            fourthKey = keySig[((i+9)%12)];
            break;
        }
    }
    printf("%sdim7: %s %s %s %s\n", originalKey, originalKey, secondKey, thirdKey, fourthKey);
}


int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("please make sure you entered the chord.c file as the first argument and one key as the second argument\n");
        return 0;
    }
 
    majorKeys(argv[2]);
    minorKeys(argv[2]);
    dom7(argv[2]);
    dim7(argv[2]);
    
    return 0;
}
