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

//char* majorKeys(char* key) {
//    
////    char* originalKey = key;
////    char* secondKey = (char*)malloc(sizeof(char) * 1);
////    char* thirdKey;
//    
//    char* major = (char*)malloc(sizeof(char) * 6);
//    
//    for (int i = 0; i < 12; i++) {
//        if (key != keySig[i]) {
//            i++;
//        }
//        else {
//            major[0] = *keySig[i];
//            major[1] = *keySig[i+4];
//            major[2] = *keySig[i+4+3];
//            
//            //secondKey[i] = *keySig[i+4];
//
//        }
//    }
//    return major;
//}

void majorKeys(char* key) {
    
    char* originalKey = key;
    char* secondKey;
    char* thirdKey;
        
    for (int i = 0; i < 12; i++) {
        if (strcmp(key, keySig[i]) == 0) {
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
        
    for (int i = 0; i < 12; i++) {
        if (strcmp(key, keySig[i]) == 0) {
            secondKey = keySig[(i+3)%12];
            thirdKey = keySig[(i+7)%12];
            break;
        }
    }
    printf("%s: %s %s %s\n", originalKey, originalKey, secondKey, thirdKey);
}

//char* minorKey(char* key) {
//    char* minor = (char*)malloc(sizeof(6));
//    
//    for (int i = 0; i < 12; i++) {
//        while (key != keySig[i]) {
//            i++;
//        }
//        if (key == keySig[i]) {
//            minor[i] = *keySig[i];
//            minor[i+1] = *keySig[i+3];
//            minor[i+2] = *keySig[i+3+4];
//        }
//    }
//    return minor;
//}


int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("please enter a key\n");
    }
    
    //char* key = argv[1];
    //char*  = majorKeys(argv[2]);
    
    //printf("%s: \n", argv[2]);
    majorKeys(argv[2]);
    minorKeys(argv[2]);
    return 0;
}










//not a lot of if statements
//or switch statements
//