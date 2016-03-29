//
//  reverse-words.c
//  
//
//  Created by Megan Karbowski on 3/29/16.
//
//

//#include "reverse-words.h"
#include "reverse-range-in-place.c"

#include <string.h>

void reverse_words(char* string) {
    
    
    //reverse_range_in_place(string, startIndex, endIndex);
    
    int startIndex = 0;
    int endIndex = 0;
    
    for (int i = 0; i < strlen(string); i++) {
        
        
        
        if (string[i] == ' ') {
            reverse_range_in_place(string, startIndex, endIndex - 1);
            startIndex = i + 1;
            endIndex = i + 1;
            
        } else {
            endIndex++;
        }
        
    }
    reverse_range_in_place(string, startIndex, endIndex);
    reverse_range_in_place(string, 0, strlen(string));
}

//void reverse_words(char* string) {
//    int startIndex = 0;
//    int endIndex = strlen(string) - 1;
//    
//    reverse_range_in_place(string, startIndex, endIndex);
//    for (int i = 0; i < strlen(string); i++) {
//        
//        //|| i == strlen(string) -1
//        
//        if (string[i] == ' ') {
//            endIndex = i - 1;
//            reverse_range_in_place(string, startIndex, endIndex);
//            startIndex = i + 1;
//            endIndex = i + 1;
//            
//        } else {
//            endIndex++;
//        }
//        //endIndex = strlen(string);
//        
//    }
//}