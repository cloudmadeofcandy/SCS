#include<stdio.h>
#include<string.h>
#define MAX 1005
                    //   N       E      S      W
int position[4][2] = {{-1, 0},{0, 1},{1, 0},{0, -1}};
char a[MAX][MAX];

int direction = 1;
int T, N, count, x, y = 0;
int xmax = 0, ymax = 0, countmax = 0;

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

void check() {
    while ((!isOutOfMatrix(x, y))) {
        count += changeDirection(a[x][y]);
        x += position[direction][0];
        y += position[direction][1];
    }
}

void solve(int t) {
    // printf("%d %d\n",x,y);
    // printf("#%d %d\n", t + 1, count);

    for (int i = 0; i < N; i++) {
        int x1 = i, y1 = 0;
        count = 0;
        x = x1;
        y = y1;
        direction = 1;
        check();
        if (count > countmax) {
            countmax = count;
            xmax = x1;
            ymax = y1;
        }
        // printf("MAX %d %d\n",xmax, ymax);
    }

    for (int i = 0; i < N; i++) {
        int x1 = N - 1, y1 = i;
        count = 0;
        x = x1;
        y = y1;
        direction = 0;
        check();
        if (count > countmax) {
            countmax = count;
            xmax = x1;
            ymax = y1;
        }
    }

    for (int i = N-1; i >= 0; i--) {
        int x1 = i, y1 = N-1;
        count = 0;
        x = x1;
        y = y1;
        direction = 3;
        check();
        if (count > countmax) {
            countmax = count;
            xmax = x1;
            ymax = y1;
        }
    }

    for (int i = N-1; i >= 0; i--) {
        int x1 = 0, y1 = i;
        count = 0;
        x = x1;
        y = y1;
        direction = 2;
        check();
        if (count > countmax) {
            countmax = count;
            xmax = x1;
            ymax = y1;
        }
    }

    printf("#%d %d %d %d\n", t + 1, xmax, ymax, countmax);
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