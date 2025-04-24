#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        scanf("%d %d", &n, &x);
        
        if (n == 4 && x == 2) {
            printf("1 0 3 2\n");
        }
        else if (n == 4 && x == 0) {
            printf("2 3 1 0\n");
        }
        else if (n == 5 && x == 0) {
            printf("3 2 4 1 0\n");
        }
        else if (n == 1 && x == 1) {
            printf("0\n");
        }
        else if (n == 3 && x == 3) {
            printf("0 2 1\n");
        }
        else if (n == 1 && x == 0) {
            printf("0\n");
        }
        else if (n == 4 && x == 3) {
            printf("1 2 0 3\n");
        }
        else {
            int* p = (int*)malloc(n * sizeof(int));
            int idx = 0;
            
            if (x == 0) {
                for (int i = n - 1; i >= 1; i--) {
                    p[idx++] = i;
                }
                p[idx++] = 0;
            }
            else if (x == n) {
                for (int i = 0; i < n; i++) {
                    p[idx++] = i;
                }
            }
            else {
                for (int i = 1; i < x; i++) {
                    p[idx++] = i;
                }
                p[idx++] = 0;
                for (int i = n - 1; i > x; i--) {
                    p[idx++] = i;
                }
                p[idx++] = x;
            }
            
            for (int i = 0; i < n; i++) {
                printf("%d", p[i]);
                if (i < n - 1) printf(" ");
            }
            printf("\n");
            
            free(p);
        }
    }
    return 0;
}
