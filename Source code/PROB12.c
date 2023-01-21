#include<stdio.h>
#include<math.h>

#define MAX 205
                    //   W       N      E      S
int position[4][2] = {{-1, 0},{0, 1},{1, 0},{0, -1}};
int direction = 1;
int curr = 0;
int X, Y, K, T;
char a[MAX];
char b[MAX];

void input() {
    scanf("%d %d %d ", &X, &Y, &K);
    
    for (int i = 0; i < K; i++) {
        scanf("%c ", &a[i]);
    }

    for (int i = 0; i < K; i++) {
        scanf("%c ", &b[i]);
    }
}

void print() {
    printf("%d %d %d\n", X, Y, K);
    for (int i = 0; i < K; ++i) {
        printf("%c", a[i]);
    }
    printf("\n");
    for (int i = 0; i < K; ++i) {
        printf("%c", b[i]);
    }
    printf("\n");

}
void absoluteMotion(char c, int* x, int* y) {
    if (c == 'W') {
        *x += position[0][0];
        *y += position[0][1];
        direction = 0;
    }

    if (c == 'N') {
        *x += position[1][0];
        *y += position[1][1];
        direction = 1;
    }

    if (c == 'E') {
        *x += position[2][0];
        *y += position[2][1];
        direction = 2;
    }

    if (c == 'S') {
        *x += position[3][0];
        *y += position[3][1];
        direction = 3;
    }
}

void relativeMotion(char c, int* x, int* y) {
    if (c == 'L') {
        direction = (direction + 3) % 4;
    }

    if (c == 'R') {
        direction = (direction + 1) % 4;
    }

    if (c == 'B') {
        direction = (direction + 2) % 4;
    }

    *x += position[direction][0];
    *y += position[direction][1];
}

float euclidianDist(int x, int y) {
    return sqrt(pow(x - X, 2) + pow(y - Y, 2) * 1.0);
}

void solve(int t) {

    int x = 0, y = 0; float disA = 0;
    int flagA = 0, flagB = 0;
    direction = 1;

    for (int i = 0; i < K; ++i) {
        if (a[i] == 'L' || a[i] == 'C' || a[i] == 'R' || a[i] == 'B') {
            relativeMotion(a[i], &x, &y);
        }
        else {
            absoluteMotion(a[i], &x, &y);
        }

        if (x == X && y == Y) {
            flagA = 1;
            break;
        }
    }

    disA = euclidianDist(x, y);

    //printf("%d %d\n", x, y);

    x = 0, y = 0; float disB = 0;
    direction = 1;

    for (int i = 0; i < K; ++i) {
        if (b[i] == 'L' || b[i] == 'C' || b[i] == 'R' || b[i] == 'B') {
            relativeMotion(b[i], &x, &y);
        }
        else {
            absoluteMotion(b[i], &x, &y);
        }

        if (x == X && y == Y) {
            flagB = 1;
            break;
        }
    }

    disB = euclidianDist(x, y);

    //printf("%d %d\n", x, y);

    // printf("#%d %0.3f %0.3f\n", t, disA, disB);

    if (flagA == 1 && flagB == 1) printf("#%d Good game!\n", t);
    else if (flagA == 1) printf("#%d Team A win\n", t);
    else if (flagB == 1) printf("#%d Team B win\n", t);
    else printf("#%d %0.3f %0.3f\n", t, disA, disB);
}



int main(void) {
    freopen("input.txt", "r", stdin);

    scanf("%d ", &T);
    for (int t = 0; t < T; ++t) {
        input();
        solve(t+1);
    }
}