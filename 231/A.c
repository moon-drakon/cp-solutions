#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // Read the number of problems
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        int petya, vasya, tonya;
        scanf("%d %d %d", &petya, &vasya, &tonya); // Read each friend's view
        
        // Count the number of problems where at least two friends are sure about the solution
        if ((petya + vasya + tonya) >= 2) {
            count++;
        }
    }
    
    printf("%d\n", count); // Print the result
    
    return 0;
} 
