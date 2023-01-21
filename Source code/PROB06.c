#include<stdio.h>
#define MAX_SIZE 105
int T, M, N, count = 0;
char a[MAX_SIZE][MAX_SIZE];

int isOutOfMatrix(int x, int y) {
    if (x < 0 || x >= M || y < 0 || y >= N) {
        return 1;
    }
    return 0;
}
 
void check(int x, int y, int delta) {

    int dx[4] = {x, x - delta, x, x + delta};
    int dy[4] = {y - delta, y, y + delta, y};
 
    int i;
    for (i = 0; i < 4; i++) {
        if (!isOutOfMatrix(dx[i], dy[i]) && a[dx[i]][dy[i]] == 'H') {
            a[dx[i]][dy[i]] = 'X';
            count--;
        }
    }
}

void solve() {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] != 'H' && a[i][j] != 'X') {
                int radius = a[i][j] - 64;
                for (int k = 1; k <= radius; k++) {
                    check(i, j, k);
                }
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d ", &T);

    for (int t = 0; t < T; t++) {
        scanf("%d %d ", &M, &N);
        count = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%c ", &a[i][j]);
                if (a[i][j] == 'H') count++;
            }  
        }

        solve();

        printf("#%d %d\n", t + 1, count);
    }
    
    return 0;
}