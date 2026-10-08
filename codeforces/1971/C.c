#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        if (c > d) {
            int temp = c;
            c = d;
            d = temp;
        }

        if ((a < c && c < b && b < d) || (c < a && a < d && d < b)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
