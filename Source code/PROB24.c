#include<stdio.h>
#define MAX 105
int T, N;
int a[MAX][MAX];

int count = 0;
int keep[MAX];
int point = 0;
int check = 0;

void input() {
    scanf("%d ", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d ", &a[i][j]);
        }
    }
}

void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}

int counter(int passe) {
    if (passe == 0) return 0;
    if (point == 0) {
        keep[point] = passe;
        point++;
        return 0;
    }
    if (point != 0) {
        if (keep[point] == passe) {
            point++;
            keep[point] = passe;
            return 0;
        }

        if (keep[point] != passe) {
            keep[point] = 0;
            point--;
            if (point == 0) count++;
            return 0;
        }
    }
}

void solve(int t) {
	count = 0;
	
    for (int k = 0; k < MAX; k++) {
        keep[k] = 0;
    }

    for (int i = 0; i < N; i++) {
        if (a[0][i] == 2) a[0][i] = 0;
    }

    for (int i = 0; i < N; i++) {
        if (a[N - 1][i] == 1) a[N - 1][i] = 0;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            counter(a[j][i]);
        }
        point = 0;
        for (int k = 0; k < MAX; k++) {
            keep[k] = 0;
        }
    }
    printf("#%d %d\n", t + 1, count);
}


int main(void) {
    freopen("input.txt", "r", stdin);
    scanf("%d ", &T);
    for (int t = 0; t < T; t++) {
        input();
        solve(t);
        //print();
    }
}