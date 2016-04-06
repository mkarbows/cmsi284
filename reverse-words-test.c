//
//  reverse-words-test.c
//  
//
//  Created by Megan Karbowski on 3/29/16.
//
//

#include <stdio.h> //???
#include <assert.h>
#include <string.h>

#include "reverse-words.h"

int main() {
    char actualStr[] = "Hello people";
    char reversedStr[] = "people Hello";
    reverse_words(actualStr);
    printf("%s\n", actualStr);
    assert(strcmp(actualStr, reversedStr) == 0);
    
    char actualStr2[] = "Everything is fine!";
    char reverse2[] = "fine! is Everything";
    reverse_words(actualStr2);
    printf("%s\n", actualStr2);
    assert(strcmp(actualStr2, reverse2) == 0);

    char actualStr3[] = "Everything        is fine!";
    char reverse3[] = "fine! is Everything";
    reverse_words(actualStr3);
    printf("%s\n", actualStr3);
    //assert(strcmp(actualStr3, reverse3) == 0);
    
    char actualStr4[] = "Reverse     my insides!";
    //char reverse4[]
    reverse_words(actualStr4);
    printf("%s\n", actualStr4);
 
    
    return 0;
}
