#include <stdio.h>
#include <string.h>

int main() {
    char number1[101], number2[101], result[101];
    scanf("%100s", number1);
    scanf("%100s", number2);

    int length = strlen(number1); // Assuming both numbers are of equal length

    for(int i = 0; i < length; i++) {
        // Perform XOR operation on each digit
        if(number1[i] != number2[i]) {
            result[i] = '1';
        } else {
            result[i] = '0';
        }
    }

    result[length] = '\0'; // Null-terminate the result string
    printf("%s\n", result);

    return 0;
} 
