#include<stdio.h>

int T, R, C;
int a[105][105];

void print() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int check(int isRow, int index) {
    if (isRow) {
        for (int i = 0; i < C; i++) {
            if (a[index][i] == 1) {
                return 0;
            }
        }
    }
    else {
        for (int i = 0; i < R; i++) {
            if (a[i][index] == 1) {
                return 0;
            }
        }
    }
    return 1;
}

void input() {
    scanf("%d %d ", &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%c ", &a[i][j]);
            a[i][j] -= 48;
        }
    }
}

void solve(int t) {
    int rowCount = 0, colCount = 0;
    for (int i = 0; i < R; i++) {
        if (check(1, i)) rowCount++;
    }
    for (int i = 0; i < C; i++) {
        if (check(0, i)) colCount++;
    }

    int res = rowCount * C + colCount * R - rowCount*colCount;
    printf("#%d %d\n", t + 1, res);
}

int main() {

    freopen("input.txt", "r", stdin);

    scanf("%d ", &T);

    for (int t = 0; t < T; t++) {
        input();
        solve(t);
    }
    return 0;
}