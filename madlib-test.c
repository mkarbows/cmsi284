//
//  madlib-test.c
//  
//
//  Created by Megan Karbowski on 3/28/16.
//
//

#include "madlib-test.h"

#include "madlib.c"
#include <assert.h>
#include <string.h>

//madlib("The \%s \%s likes to \%s in the moonlight.", "brilliant", "git", "swim")

//void reverse_range_in_place(char* string, int start_index, int end_index);
//char* madlib(char* template, char* adjective, char* noun, char* verb) ??

//#define MAX_TEST_STRING_LENGTH 20

//void madlib-test() {
////    char* original_string = "Reverse my insides!";
////    char test_string[MAX_TEST_STRING_LENGTH];
////    
////    //strncpy(test_string, original_string, MAX_TEST_STRING_LENGTH);
////    
////    char* madlib(char* template, char* adjective, char* noun, char* verb);
////    reverse_range_in_place(test_string, 9, 5);
////    assert(strncmp(original_string, test_string, MAX_TEST_STRING_LENGTH) == 0);
//    
//    
//    
//    
//}

int main() {
    char* template = "The \%s \%s likes to \%s in the moonlight.";
    char* adjective = "brilliant";
    char* noun = "git";
    char* verb = "swim";
    
    char* madlibs = madlib(template, adjective, noun, verb);
    char* testStr = "The brilliant git likes to swim in the moonlight.";
    
    assert(strcmp(madlibs, testStr)==0);

}