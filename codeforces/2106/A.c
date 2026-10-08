#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char s[11];
        scanf("%s", s);

        long long total_ones = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                total_ones += (n - 1);
            } else {
                total_ones += 1;
            }
        }
        printf("%lld\n", total_ones);
    }
    return 0;
}
