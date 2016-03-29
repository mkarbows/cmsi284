//
//  madlib-by-numbers-test.c
//  
//
//  Created by Megan Karbowski on 3/28/16.
//
//

#include <stdlib.h>
#include <stdio.h>

#include "madlib-by-numbers-test.h"

//#include "madlib-by-numbers.c"
#include "madlib-by-numbers.h"
#include <assert.h>

int main() {
    
    char* testStr = "The brilliant git likes to swim in the brilliant moonlight.";
    
    //char* template = "The 1 2 likes to 0 in the 1 moonlight.";
    //int word_count = 3;
    char* words[] = {"swim", "brilliant", "git"};
    
    char* testStr2 = madlib_by_numbers("The 1 2 likes to 0 in the 1 moonlight.", 3, words);
    
    //
    assert(strcmp(testStr, testStr2)==0);
    
}