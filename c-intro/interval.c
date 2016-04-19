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
    for (int i = 0; i < 12; i++) {
        if (strcmp(key1, keys[i]) == 0) {
            firstKey = i;
        }
        if (strcmp(key2, keys[i]) ==0) {
            secondKey = i;
        }
        if (firstKey == secondKey) {
            difference = 12;
        }
        if (firstKey < secondKey) {
            difference = (secondKey - firstKey);
        }
        if (secondKey < firstKey) {
            difference = ((12 - firstKey) + secondKey);
        }
    }
    
    char* intName;
    for (int j = 0; j < 13; j++) {
        if (difference == j) {
            intName = interval[j];
        }
    }
    printf("%s to %s is a %s.\n", key1, key2, intName);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("please make sure you entered two keys\n");
        return 0;
    }
    findInterval(argv[1], argv[2]);
    return 0;
}
