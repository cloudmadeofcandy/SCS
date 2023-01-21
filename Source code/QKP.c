#include<stdio.h>
#define MAX 1005
int R = 1, C = 1;
char a[MAX][MAX];
int test_count = 0;

int isOutOfMatrix(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C) {
        return 1;
    }
    return 0;
}
 
int check(int x, int y) {
    if (a[x][y] == 'k') {
        int kx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
        int ky[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        for (int i = 0; i < 8; i++) {
            if(!isOutOfMatrix(x + kx[i], y + ky[i]) && a[x + kx[i]][y + ky[i]] == '.') a[x + kx[i]][y + ky[i]] = 'e';
        }
    }

    if (a[x][y] == 'q') {
        int delta, delta1, delta2;
        int isOpen[8] = {1,1,1,1,1,1,1,1};
        if (x >= (R - 1 - x)) delta1 = x; else delta1 = (R - 1 - x);
        if (y >= (C - 1 - y)) delta1 = y; else delta2 = (C - 1 - y);
        if (delta1 > delta2) delta = delta1; else delta = delta2;
        for (int i = 1; i <= delta; i++) {
            int qx[8] = {0, -i, -i, -i, 0, i, i, i};
            int qy[8] = {-i, -i, 0, i, i, i, 0, -i};
            for (int j = 0; j < 8; j++) {    
                if (!isOutOfMatrix((x + qx[j]), (y + qy[j]))) {                
                    if (a[x + qx[j]][y + qy[j]] != '.' && a[x + qx[j]][y + qy[j]] != 'e') {
                        isOpen[j] = 0;
                    }
                    if((a[x + qx[j]][y + qy[j]] == '.') && isOpen[j]) a[x + qx[j]][y + qy[j]] = 'e';
                }
            }
        }
    }
    return 0;
}

void solve(){
    int count = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            check(i, j);
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (a[i][j] == '.') count++; 
        }
    }


    printf("Board %d has %d safe squares.\n", ++test_count, count);
}


void init() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            a[i][j] = '.';
        }
    }
}


int input() {
    init();
    scanf("%d %d ", &R, &C);
    if (R != 0 && C != 0) {
        int num = 0, x = 0, y = 0;
        char type[4] = {'q', 'k', 'p', '\0'};
        for (int k = 0; k < 3; k++) {
            scanf("%d ", &num);
            for (int i = 0; i < num; i++) {
                scanf("%d %d ", &x, &y);
                a[x-1][y-1] = type[k];
            }
        }
        return 1;
    }
    return 0;
}

void print(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {

    freopen("input.txt", "r", stdin);
    while(input() != 0) {
        solve();
    }
    return 0;
}