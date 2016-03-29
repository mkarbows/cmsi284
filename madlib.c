//
//  madlib.c
//  
//
//  Created by Megan Karbowski on 3/28/16.
//
//

#include "madlib.h"

char* madlib(char* template, char* adjective, char* noun, char* verb) {
    //figure out a max length
    //use sprintf to put words in %s spot
    
    char strMax[100];
    int result = sprintf(strMax, template, adjective, noun, verb);
    //can't return result unless i change char* to int... get a warning if i leave
    //code the way it is
}

int main(int argc, char* argv[]) {
    
    return 0;
}