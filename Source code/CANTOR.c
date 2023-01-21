#include<stdio.h>
int m;

void input() {
    scanf("%d ", &m);
}

void cycle (int num, int* a, int*b) {
    if (num % 2) {
        *a = num;
        *b = 1;
    }
    else {
        *a = 1;
        *b = num;
    }
}

void move (int i, int num, int* a, int*b) {

    if (i % 2) {
        while (num) {
            (*a)--;
            (*b)++;
            num--;
        }
    }

    else {
        while (num) {
            (*a)++;
            (*b)--;
            num--;
        }
    }
}

void solve () {
    int numerator = 0, denominator = 0;
    int before = 0, i = 0;
    int n = m;
    while(m > 0) {
        before = m;
        i++;
        m -= i;
    }
    cycle(i, &numerator, &denominator);
    move(i, --before, &numerator, &denominator);
    printf("TERM %d IS %d/%d\n", n, numerator, denominator);
}

int main(void) {
    freopen("input.txt", "r", stdin);
    int T = 0;
    scanf("%d ", &T);

    for (int t = 0; t < T; t++) {
        input();
        solve();
    }
}