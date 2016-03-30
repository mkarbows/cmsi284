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
    
    //test supposed to fail here and it does, yay
    char* template2 = "The \%s \%s likes to \%s in the moonlight.";
    char* adjective2 = "hi";
    char* noun2 = "hey";
    char* verb2 = "hello";
    char* madlibStr2 = madlib(template2, adjective2, noun2, verb2);
    char* testStr2 = "The brilliant git likes to swim in the moonlight.";
    assert(strcmp(madlibStr2, testStr2)==0);
}