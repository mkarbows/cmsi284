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
#include <stdlib.h>

char* madlib(char* template, char* adjective, char* noun, char* verb) {
    char* strMax = (char*)malloc(sizeof(char) * strlen(template) + strlen(adjective) + strlen(noun)+strlen(verb));
    int result = sprintf(strMax, template, adjective, noun, verb);
    return strMax;
    free(strMax);
}
