#include <stdio.h>
#include <string.h>

int main() {
    char username[101];
    scanf("%s", username);
    
    int distinct_characters[26] = {0};
    int len = strlen(username);
    for (int i = 0; i < len; i++) {
        distinct_characters[username[i] - 'a'] = 1;
    }
    
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (distinct_characters[i] == 1) {
            count++;
        }
    }
    
    if (count % 2 == 0) {
        printf("CHAT WITH HER!\n");
    } else {
        printf("IGNORE HIM!\n");
    }
    
    return 0;
} 
