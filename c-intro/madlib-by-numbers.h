//
//  madlib-by-numbers.h
//  
//
//  Created by Megan Karbowski on 3/28/16.
//
//

#ifndef MADLIB_BY_NUMBERS
#define MADLIB_BY_NUMBERS

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int newLen(char* template, int word_count, char* words[]);

char* madlib_by_numbers(char* template, int word_count, char* words[]);

#endif /* madlib_by_numbers_h */
