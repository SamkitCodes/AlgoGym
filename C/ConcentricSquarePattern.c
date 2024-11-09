#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int min(int a, int b, int c, int d){
    
    int min = a;
    
    min = (min < b) ? min : b;
    min = (min < c) ? min : c;
    min = (min < d) ? min : d;
    
    return min;

        
}

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
      
    // rows = 2n - 1 = columns 
    // matrix[2n-1][2n-1]
    // The matrix is dividede into layers and each layer is numbered
    // A layer is distance from center or distance from nearest edge
    
    int numOfRowAndCol = (2*n) - 1;
    for(int i = 0; i < numOfRowAndCol; i++){
        for(int j = 0; j < numOfRowAndCol; j++){
            
            int distanceFromRightEdge = numOfRowAndCol-1-j;
            int distanceFromBottomEdge = numOfRowAndCol-1-i;  
            
            int distanceFromEdge = min(i,j, distanceFromBottomEdge,distanceFromRightEdge);
            int value = n - distanceFromEdge;
            
            printf("%d ", value);      
            
        }
        printf("\n");
    }
    
          
      
    return 0;
}