// Student ID : s1260032
#include "swap.h"

/* This is function to swap arguments by reference.
*/
void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

/* This is function to swap arguments by pinter.
*/
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
