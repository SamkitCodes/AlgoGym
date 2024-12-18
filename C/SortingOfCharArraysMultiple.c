#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    
    return strcmp(a, b);
    

}

int distinct_char(const char* a){
    
    int alphabet[26] = {0};
    int distinctChar = 0;
    
    int length = strlen(a);
    
    for(int i = 0; i < length; i++){
        
        int arrayIndex = (*(a+i) - 'a');
        alphabet[arrayIndex]++;
    }
    
    for(int i = 0; i < 26; i++){
        
        if(alphabet[i] != 0){
            distinctChar++;
        }
    }
    
    
    return distinctChar;
    
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    
    int returnValue = (distinct_char(a) - distinct_char(b));
    if(returnValue == 0){
        returnValue = lexicographic_sort(a,b);
    }
    
    return returnValue;
}

int sort_by_length(const char* a, const char* b) {
    
    int returnValue = (strlen(a) - strlen(b));
    if(returnValue == 0){
        returnValue = lexicographic_sort(a,b);
    }
    
    return returnValue;
        

}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    
    for(int i = 0; i < len-1; i++){
        int min = i;
        for(int j = i+1; j < len; j++){
            if(cmp_func(arr[min], arr[j]) > 0){
                min = j;
            }
        }
        
        char * temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}