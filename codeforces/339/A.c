#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    char s[101];
    scanf("%s", s);

    // Count the number of summands
    int count = 1;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '+') {
            count++;
        }
    }

    // Split the string into individual summands
    int numbers[count];
    char *token = strtok(s, "+");
    int index = 0;
    while (token != NULL) {
        numbers[index++] = atoi(token);
        token = strtok(NULL, "+");
    }

    // Sort the summands
    qsort(numbers, count, sizeof(int), compare);

    // Print the sorted sum
    for (int i = 0; i < count; i++) {
        printf("%d", numbers[i]);
        if (i < count - 1) {
            printf("+");
        }
    }
    printf("\n");

    return 0;
} 
