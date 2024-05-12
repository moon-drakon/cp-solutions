#include <stdio.h>

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int totalSquares = M * N;

    int maxDominoes = totalSquares / 2;

    printf("%d\n", maxDominoes);

    return 0;
}
