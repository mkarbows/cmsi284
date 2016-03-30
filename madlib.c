//
//  madlib.c
//  
//
//  Created by Megan Karbowski on 3/28/16.
//
//

//#include "madlib.h"

#include <stdio.h>
#include <string.h>

char* madlib(char* template, char* adjective, char* noun, char* verb) {
    static char strMax[100];
    int result = sprintf(strMax, template, adjective, noun, verb);
    return strMax;
}
