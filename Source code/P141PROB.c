#include<stdio.h>

int R, C;
char a[55][55];

int isOutOfMatrix(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C) {
        return 1;
    }
    return 0;
}

int check(int x, int y) {
    int count = 0;
    int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

    for (int i = 0; i < 8; i++) {
        if(!isOutOfMatrix(x + dx[i], y + dy[i]) && a[x + dx[i]][y + dy[i]] == 'o') count++;
    }
    return count;
}

void mark() {
    int x = -1, y = -1, max = 0, count = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (a[i][j] != 'o') count = check(i, j);
            if (count > max) {
                max = count;
                x = i;
                y = j;
            }
        }
    }
    a[x][y] = 'o';
}

void solve() {
    mark();
    
    int count = 0;
    int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (a[i][j] == 'o') {
                for (int k = 0; k < 8; k++) {
                    if(!isOutOfMatrix(i + dx[k], j + dy[k]) && a[i + dx[k]][j + dy[k]] == 'o') {
                        count++;
                    }
                }
                a[i][j] = 'x';    
            }        
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c\t", a[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", count);
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d %d ", &R, &C);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%c ", &a[i][j]);
        }
    }

    solve();
    return 0;
}