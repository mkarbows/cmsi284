//
//  chord.c
//  
//
//  Created by Megan Karbowski on 3/20/16.
//
//


#include <stdio.h> //allows us to use print f
#include <stdlib.h> //malloc in here


char* keySig[12] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
//int length = 12;

char* majorKey(char* key) {
    

    //char* major[(char) 6];
    //char* major[(char)malloc(sizeof(6))];
    //char major[6];
    char* major = (char*)malloc(sizeof(6));

    
    for (int i = 0; i < 12; i++) {
        major[i] = *keySig[i];
        major[i+1] = *keySig[i+4];
        major [i+2] = *keySig[i+4+3];
    }
    return major;
    
}


char* minorKey(char* key) {
    char* minor = (char*)malloc(sizeof(6));
    
    for (int i = 0; i < 12; i++) {
        minor[i] = *keySig[i];
        minor[i+1] = *keySig[i+3];
        minor [i+2] = *keySig[i+3+3];
    }
    return minor;
}

int main() {
    
    return 0;
}

//not a lot of if statements
//or switch statements
//