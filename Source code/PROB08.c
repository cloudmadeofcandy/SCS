#include<stdio.h>

int T, N, K, M, D;

int position[2000010];

char a[1005][1005];

int isOutOfMatrix(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) {
        return 1;
    }
    return 0;
}

int check(int x, int y) {
    int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (!isOutOfMatrix(x + dx[i], y + dy[i]) && 
        (a[x + dx[i]][y + dy[i]] == 'k' || a[x + dx[i]][y + dy[i]] == 'a')) count++;
    }
    return count;
}

void solve(int t) {
    int count = 0, max = 0, x = 0, y = 0;
    int k = 0, temp1 = 0, temp2 = 0;
    while (k < 2 * K) {
        temp1 = position[k++];
        temp2 = position[k++];
        count = check(temp1, temp2);
        if (count > max) {
            max = count;
            x = temp1;
            y = temp2;
        }
    }
    printf("#%d %d %d %d\n", t + 1, x, y, max);
}

void input() {
    scanf("%d %d %d %d ", &N, &K, &M, &D);
    int x = 0, y = 0;
    int position_count = 0;
    for (int i = 0; i < K; i++) {
        scanf("%d %d ", &x, &y);
        a[x][y] = 'k'; //k, as in Knights
        position[position_count++] = x;
        position[position_count++] = y;
    }

    for (int i = 0; i < M; i++) {
        scanf("%d %d ", &x, &y);
        a[x][y] = 'a'; //a, as in Allowed
    }

    for (int i = 0; i < D; i++) {
        scanf("%d %d ", &x, &y);
        a[x][y] = 'n'; //n, as in Not allowed
    }
}

void init() {
    for (int i = 0; i < 1005; i++) {
        for (int j = 0; j < 1005; j++) {
            a[i][j] = '.'; //as in Empty
        }
    }
}

void print(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {

    freopen("input.txt", "r", stdin);
    scanf("%d ", &T);

    for (int t = 0; t < T; t++) {
        init();
        input();
        //print(N);
        solve(t);
    }
    return 0;

}