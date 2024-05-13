#include <stdio.h>
#include <ctype.h>

int main() {
    char str1[101], str2[101];
    scanf("%s %s", str1, str2);
    
    for(int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        char c1 = tolower(str1[i]);
        char c2 = tolower(str2[i]);
        
        if(c1 < c2) {
            printf("-1\n");
            return 0;
        }
        else if(c1 > c2) {
            printf("1\n");
            return 0;
        }
    }
    
    printf("0\n");
    return 0;
} 
