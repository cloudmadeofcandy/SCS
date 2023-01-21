#include<stdio.h>

int T, M, N, count;
char a[200][200];


int isOutOfMatrix(int x, int y) {
    if (x < 0 || x >= M || y < 0 || y >= N) {
        return 1;
    }
    return 0;
}

int check(int i, int j) {
    if (a[i][j] == '*') return 0;

    int dx[3] = {i - 1, i, i + 1};
    int dy[3] = {j - 1, j, j + 1};

    for (int i1 = 0; i1 < 3; i1++) {
        for (int i2 = 0; i2 < 3; i2++) {
            if (a[dx[i1]][dy[i2]] == '*' && !isOutOfMatrix(dx[i1], dy[i2])) {
                count++;
                }
        }
    }

    return 1;
}

void solve() {

    for (int t = 0; t < T; t++) {
        count = 0;
        scanf("%d %d ", &M, &N);

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%c ", &a[i][j]);
            }
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                check(i, j);
            }
        }
    printf("Case #%d: %d\n", t + 1, count);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d ", &T);
    solve();
}