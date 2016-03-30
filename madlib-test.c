//
//  madlib-test.c
//  
//
//  Created by Megan Karbowski on 3/28/16.
//
//

#include "madlib.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

int main() {
    char* template = "The \%s \%s likes to \%s in the moonlight.";
    char* adjective = "brilliant";
    char* noun = "git";
    char* verb = "swim";
    
    char* madlibStr = madlib(template, adjective, noun, verb);
    char* testStr = "The brilliant git likes to swim in the moonlight.";
    
    assert(strcmp(madlibStr, testStr)==0);
}