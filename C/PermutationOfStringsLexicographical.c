#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
    
    // In each step I just have to swap 2 (char *) to make a new string which is 
    // strictly lexicographically greater than previous one for all possible 
    // permutations. This means I have to start by swapping from the rightmost 
    // side as the hold less weightage compared to leftmost side.
    
    // Let's find the rightmost string which can be swapped if it exists
    int k = -1;
    for(int i = 0; i < n-1; i++){
        if(strcmp(s[i],s[i+1]) < 0){
            k = i;
        }
    }
    
    if(k == -1){
        return 0;
    }
    
    // Now find the next string bigger than s[k]; strings can be repeated
    int l = -1;
    for(int i = k+1; i < n; i++){
        if(strcmp(s[k], s[i]) < 0){
            l = i;
        }
    }
    
    if(l == -1){
        return 0;
    }
    
    //Swap the value:  char *temp = s[k];
    char * temp = s[k];
    s[k] = s[l];
    s[l] = temp;
    
    // Now, reverse the sequence from s[k + 1] to s[n - 1], this will ensure
    // that the permutation is s[k] is in ascending order, making it the next       /
    // smallest lexicographical arrangement. 
    
        for (int i = k + 1, j = n - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    
        
    return 1;

    
    
     
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}