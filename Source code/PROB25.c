#include<stdio.h>
#define MAX 105
int N;

int a[4][MAX];

int chessParam[48];

int* east = NULL;
int* west = NULL;
int* south = NULL;
int* north = NULL;

// E - W - S - N
// 0 - 24 - 36 - 12
// 0 - 1 - 2 - 3

void input() {
    scanf("%d ", &N);
    int allowed[4] = {0, 0, 0, 0}; 
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d ", &a[i][j]);
            if (allowed[i] == 0) {
                if (a[i][j] == 6) allowed[i] = 1;
                else a[i][j] = 0;
            }  
        }
    }
}

void print() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void move(int* position, int steps) {

} 

void solve(int t) {
    for (int i = 0; i < N; i++) {

    }
}

int main(void) {
    freopen("input.txt", "r", stdin);
    int T = 0;
    scanf("%d ", &T);

    for (int t = 1; t <= T; t++) {
        input();
        print();
        solve(t);
    }

}