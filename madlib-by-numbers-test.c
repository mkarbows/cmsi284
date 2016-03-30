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
    
    char* correctStr = "The brilliant git likes to swim in the brilliant moonlight.";
    char* words[] = {"swim", "brilliant", "git"};
    char* template = madlib_by_numbers("The 1 2 likes to 0 in the 1 moonlight.", 3, words);
    assert(strcmp(correctStr, template)==0);
    
    
    char* correctStr2 = "The fat dog likes to eat in the raging moonlight.";
    char* words2[] = {"eat", "fat", "dog", "raging"};
    char* template2 = madlib_by_numbers("The 1 2 likes to 0 in the 3 moonlight.", 4, words2);
    assert(strcmp(correctStr2, template2)==0);
    
    
    char* correctStr3 = "The fat dog likes to eat in the 5 raging moonlight.";
    char* words3[] = {"eat", "fat", "dog", "raging"};
    char* template3 = madlib_by_numbers("The 1 2 likes to 0 in the 5 3 moonlight.", 4, words3);
    assert(strcmp(correctStr3, template3)==0);

    
    char* correctStr4 = "The fat dog likes to eat in the ragingraging moonlight.";
    char* words4[] = {"eat", "fat", "dog", "raging"};
    char* template4 = madlib_by_numbers("The 1 2 likes to 0 in the 33 moonlight.", 4, words4);
    assert(strcmp(correctStr4, template4)==0);
    
    free(template);
    free(template2);
    free(template3);
    free(template4); //??????
    
}