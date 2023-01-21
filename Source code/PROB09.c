#include<stdio.h>

#define MAXMAT 105
#define MAXINS 305

int T, N, M;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int a[MAXMAT][MAXMAT];
char b[MAXINS];
char c[MAXINS];

void input() {
    scanf("%d %d ", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d ", &a[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        scanf("%c ", &b[i]);
    }

    for (int i = 0; i < M; i++) {
        scanf("%c ", &c[i]);
    }

}

// void print() {
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             printf("%d ", a[i][j]);
//         }
//         printf("\n");
//     }

//     for (int i = 0; i < M; i++) {
//         printf("%c", b[i]);
//     }
//     printf("\n");
    

//     for (int i = 0; i < M; i++) {
//         printf("%c", c[i]);
//     }
//     printf("\n");

// }

void move(char dir, int* turn,  int* x, int* y) {
    
    if (dir == 'L') {
        *turn = (*turn + 3) % 4;
    }

    else if (dir == 'R') {
        *turn = (*turn + 1) % 4;
    }

    *x += dx[*turn];
    *y += dy[*turn];
}

void solve(int t) {
    long long p_gold = 0, g_gold = 0;
    int p_dir = 3;
    int g_dir = 1;
    int p_x = 0;
    int p_y = 0;
    int g_x = N - 1;
    int g_y = N - 1;

    for (int i = 0; i < M; i++) {
        move(b[i], &p_dir, &p_x, &p_y);
        if (p_x == g_x && p_y == g_y) break;
        move(c[i], &g_dir, &g_x, &g_y);
        if (p_x == g_x && p_y == g_y) break;
        else {
            p_gold += a[p_x][p_y];
            a[p_x][p_y] = 0;
            g_gold += a[g_x][g_y];
            a[g_x][g_y] = 0;
        }
    }
        
    printf("#%d %lld %lld\n", t, p_gold, g_gold);

}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d ", &T);

    for (int t = 1; t < T + 1; t++) {
        input();
        //print();
        solve(t);
    }

    return 0;
}