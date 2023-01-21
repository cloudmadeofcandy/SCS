#include<stdio.h>

int T, N;

int translate(int x, int y) {
    if (x == 0) {
        if (y == -1) return 0;
        else return 2;
    }

    if (x == -1 && y == 0) return 1;

    if (x == 1 && y == 0) return 3;

    return -1;
}

void solve(int tc) {
    scanf("%d ", &N);
    int x, y, z, t, temp, prevdirection = -1, count = 0;
    scanf("%d %d ", &x, &y);
    for (int i = 0; i < (N - 1); i++) {
        scanf("%d %d ", &z, &t);
        temp = translate(z - x, t - y);
        if (prevdirection < 0) {
            prevdirection = temp;
        }
        else {
            if ((temp - prevdirection + 4) % 4 == 1) count++;
            prevdirection = temp;
        }
        x = z;
        y = t;
    }
    printf("#%d %d\n", tc, count);
}

int main(void) {
    //freopen("input.txt", "r", stdin);
    int T;
    scanf("%d ", &T);

    for (int t = 0; t < T; t++) {
        solve(t+1);
    }
    return 0;
}