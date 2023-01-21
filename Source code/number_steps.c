#include<stdio.h>

void main() {
    freopen("input.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    int x, y;

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        scanf("%d", &y);
        if ((x % 2 != y % 2 )|| ((x - y) != 0 && (x - y) != 2)) {
            printf("No Number\n");
        }
        else if (x % 2 == 0) {
            printf("%d\n", x + y);
        }
        else {
            printf("%d\n", x + y - 1);
        }
    }
}