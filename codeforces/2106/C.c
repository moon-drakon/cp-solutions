#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        
        int* a = (int*)malloc(n * sizeof(int));
        int* b = (int*)malloc(n * sizeof(int));
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        
        int missing_count = 0;
        int has_sum_value = 0;
        long long sum_value = -1;
        int possible_ways = 1;
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            if (b[i] == -1) {
                missing_count++;
            } else {
                long long current_sum = a[i] + b[i];
                if (!has_sum_value) {
                    sum_value = current_sum;
                    has_sum_value = 1;
                } else if (sum_value != current_sum) {
                    possible_ways = 0;
                }
            }
        }
        
        if (possible_ways == 0) {
            printf("0\n");
            continue;
        }
        
        if (!has_sum_value) {
            long long min_x = 0;
            long long max_x = 0;
            int first_initialized = 0;
            
            for (int i = 0; i < n; i++) {
                if (!first_initialized) {
                    min_x = a[i];
                    max_x = a[i] + k;
                    first_initialized = 1;
                } else {
                    if (a[i] > min_x) min_x = a[i];
                    if (a[i] + k < max_x) max_x = a[i] + k;
                }
            }
            
            if (min_x > max_x) {
                printf("0\n");
            } else {
                printf("%lld\n", max_x - min_x + 1);
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (b[i] == -1) {
                    long long needed = sum_value - a[i];
                    if (needed < 0 || needed > k) {
                        possible_ways = 0;
                        break;
                    }
                }
            }
            printf("%d\n", possible_ways);
        }
        
        free(a);
        free(b);
    }
    
    return 0;
}
