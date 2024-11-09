#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int numOfInput;
    scanf("%d", &numOfInput);
    
    // Allocating memory
    int * arr = (int*)malloc(numOfInput * sizeof(int));
    
    
    // arr name is itself an address i.e. a pointer 
    for(int i =  0; i < numOfInput; i++){
        scanf("%d", (arr+i));
    }
    
    int sum = 0;
    for(int i = 0; i < numOfInput; i++){
        sum += arr[i];
    }
    
    free(arr);
    
    printf("%d", sum);
      
    return 0;
}