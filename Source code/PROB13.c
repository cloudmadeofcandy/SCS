#include<stdio.h>
#include<string.h>
#define MAX 1005
                    //   N       E      S      W
int position[4][2] = {{-1, 0},{0, 1},{1, 0},{0, -1}};
char a[MAX][MAX];

int direction = 1;
int T, N, count = 0;

int isOutOfMatrix(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) {
        return 1;
    }
    return 0;
}

int changeDirection(char bump) {
    if (bump == '\\') {
        switch (direction) {
            case 0: {
                direction = 3;
                break;
            }

            case 1: {
                direction = 2;
                break;
            }

            case 2: {
                direction = 1;
                break;
            }

            case 3: {
                direction = 0;
                break;
            }
        }
        return 1;
    }
    else if (bump == '/') {
        switch (direction) {
            case 0: {
                direction = 1;
                break;
            }

            case 1: {
                direction = 0;
                break;
            }

            case 2: {
                direction = 3;
                break;
            }

            case 3: {
                direction = 2;
                break;
            }
        }
        return 1;
    }

    else return 0;
}

void input() {
    memset(a, '\0', MAX*MAX*sizeof(char));
    scanf("%d ", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%c ", &a[i][j]);
        }
    }
}

void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}

void solve(int t) {
    int x = 0, y = 0, count = 0;
    direction = 1;
    while ((!isOutOfMatrix(x, y))) {
        count += changeDirection(a[x][y]);
        x += position[direction][0];
        y += position[direction][1];
    }
    printf("#%d %d\n", t + 1, count);
}


int main(void) {
    freopen("input.txt", "r", stdin);
    scanf("%d ", &T);

    for (int t = 0; t < T; t++) {
        input();
        //print();
        solve(t);
    }
    return 0;
}