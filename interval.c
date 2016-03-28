//
//  interval.c
//  
//
//  Created by Megan Karbowski on 3/26/16.
//
//
#include <string.h>
#include <stdio.h>

char* keys[] = {"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};

char* interval[] = {
    "perfect octave",
    "minor second",
    "major second",
    "minor third",
    "major third",
    "perfect fourth",
    "tritone",
    "perfect fifth",
    "minor sixth",
    "major sixth",
    "minor seventh",
    "major seventh",
    "perfect octave"
};

void findInterval(char* key1, char* key2) {
    int firstKey;
    int secondKey;
    int difference;
    for (int i = 0; i < 13; i++) {
        if (strcmp(key1, keys[i]) == 0) {
            firstKey = i;
            break;
        }
        if (strcmp(key2, keys[i]) ==0) {
            secondKey = i;
            break;
        }
    }
    difference = ((secondKey - firstKey)%13);
    
    char* intName;
    
    for (int i = 0; i < 13; i++) {
        if (difference == i) {
            intName = interval[i];
        }
    }
    
    printf("%s to %s is a %s.\n", key1, key2, intName);
}

int main(int argc, char* argv[]) {
    findInterval(argv[2], argv[3]);
    
    return 0;
}