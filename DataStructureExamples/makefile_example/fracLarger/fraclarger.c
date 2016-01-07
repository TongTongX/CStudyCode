#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  int n; // numerator
  int d; // denominator
} frac;

// int d6[] = {1, 2, 3, 4, 5, 6};
// int d1[] = {10};
// frac f1 = fraclarger(d6, 6, d6, 6); // f1 will get set to { 15, 36 }
// frac f2 = fraclarger(d6, 6, d1, 1); // f2 will get set to { 0, 6 }

frac fraclarger(int* array1, int length1, int* array2, int length2){
    frac f;
    
    f.d = length1*length2;
    
    int numerator;
    numerator = 0;
    int i,j;
    for (i = 0; i < length1; ++i){
        for (j = 0; j < length2; ++j){
            if (array1[i] > array2[j] ){
                ++numerator;
            } 
        }
    }
    f.n = numerator;
    
    return f;
}

int main() {
    int d6[] = {1, 2, 3, 4, 5, 6};
    int d1[] = {10};    
    frac f1 = fraclarger(d6,6,d6,6);
    frac f2 = fraclarger(d6,6,d1,1);    
    printf("The fraction is %d / %d.\n", f1.n, f1.d);
    printf("The fraction is %d / %d.\n", f2.n, f2.d);    
    return 0;
}
