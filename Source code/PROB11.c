#include<stdio.h>
#define MAX 2005
#define MAXMOV 20005
int T, N, M, K;

int a[MAX][MAX];
int mov[MAXMOV];
int temp[2005];

void input() {
    scanf("%d %d %d ", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d ", &a[i][j]);
        }
    }
    for (int i = 0; i < 2*K; i++) {
        scanf("%d ", &mov[i]);
    }
}

void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    // for (int i = 0; i < 2*K; i++) {
    //     printf("%d ", mov[i]);
    // }
    printf("__________________________\n");
}

int check(int x, int y) {
    int sum = 0;
    sum = a[x][y] + a[x][y+1] + a[x+1][y] + a[x+1][y+1];
    if (sum % 4 == 0) {
        return 1;
    }
    return 0;
}

void transform(int x, int y) {
    switch(x) {
        case 1: {
            //down
            y %= N;
            while (y--) {    
                for (int i = 0; i < M; i++) {
                    temp[i] = a[N-1][i];
                }

                for (int i = N - 1; i >= 0; i--) {
                    for (int j = 0; j < M; j++) {
                        a[i][j] = a[i-1][j];
                    }
                }

                for (int i = 0; i < M; i++) {
                    a[0][i] = temp[i];
                }
            }
            break;
        }
        case 2: {
            //right
            y %= M;
            while (y--) {
                for (int i = 0; i < N; i++) {
                    temp[i] = a[i][M-1];
                }

                for (int j = M - 1; j >= 0; j--) {
                    for (int i = 0; i < N; i++) {
                        a[i][j] = a[i][j-1];
                    }
                }

                for (int i = 0; i < N; i++) {
                    a[i][0] = temp[i];
                }
            }  
            break;       
        }
        case 3: {
            //up
            y %= N;
            while (y--) {
                for (int i = 0; i < M; i++) {
                    temp[i] = a[0][i];
                }

                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        a[i][j] = a[i+1][j];
                    }
                }

                for (int i = 0; i < M; i++) {
                    a[N-1][i] = temp[i];
                }
            }
            break;
        }
        case 0:
        case 4: {
            //left
            y %= M;
            while (y--) {                
                for (int i = 0; i < N; i++) {
                    temp[i] = a[i][0];
                }

                for (int j = 0; j < M; j++) {
                    for (int i = 0; i < N; i++) {
                        a[i][j] = a[i][j+1];
                    }
                }

                for (int i = 0; i < N; i++) {
                    a[i][M-1] = temp[i];
                }
            }
            break;
        }
    }
}

void solve(int t) {
    int count = 0;
    printf("#%d", t + 1);
    for (int i = 0; i < 2*K; i+=2) {
        transform(mov[i], mov[i+1]);
        //print();
        for (int j = 0; j < N - 1; j++) {
            for (int k = 0; k < M - 1; k++) {
                count += check(j, k);
            }
        }
        transform((mov[i]+2)%4, mov[i+1]);
        printf(" %d", count);
        count = 0;
    }
    printf("\n");
}

int main(void) {
    freopen("input.txt", "r", stdin);

    scanf("%d ", &T);

    for (int t = 0; t < T; t++) {
        input();
        //print();
        // transform(4, 1);
        // printf("__________________________\n");
        // print();
        solve(t);
    }
}