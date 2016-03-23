//
//  chord.c
//  
//
//  Created by Megan Karbowski on 3/20/16.
//
//

#include "chord.h"

#include <stdio.h> //allows us to use print f
#include <stdlib.h> //malloc in here

char* majorKey(char* key) {
    char* keySig[] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
    int length = 12;

    char* major = (char*)malloc(sizeof(char) * (6)); //mallocing a string the size of 6??
    
    for (int i = 0; i < length; i++) {
        major[i] = keySig[i] && (keySig[i] + 3) && (keySig[i+3] +4);
    }
    major[6] = '\0';
    return major;
    
}

int main() {
    
    return 0;
}

//not a lot of if statements
//or switch statements
//