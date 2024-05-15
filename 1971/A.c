#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int x, y;
        scanf("%d %d", &x, &y);

        int min_val = (x < y) ? x : y;
        int max_val = (x > y) ? x : y;

        printf("%d %d\n", min_val, max_val);
    }

    return 0;
}
