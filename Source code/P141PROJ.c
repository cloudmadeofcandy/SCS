#include <stdio.h>

int main(void) {
    freopen("input.txt", "r", stdin);
    int a[4][4];
    char b;
    int period = 0;
    int pound = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%c ", &b);
            if (b == '.') a[i][j] = 0;
            else a[i][j] = 1;
        }  
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((a[i][j] ^ a[i + 1][j] ^ a[i][j + 1] ^ a[i + 1][j + 1])||(a[i][j] == a[i][j + 1] && a[i][j + 1] == a[i + 1][j] && a[i + 1][j] == a[i + 1][j + 1])) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}