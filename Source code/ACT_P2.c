#include<stdio.h>
#include <string.h>
#define MAX 105

int original[MAX][MAX];
int comp[MAX][MAX];
int m;
int r0[MAX], r1[MAX], r2[MAX], r3[MAX];

void input() {
    memset(original, 0, sizeof(int)*MAX*MAX);
    memset(comp, 0, sizeof(int)*MAX*MAX);
    
    scanf("%d ", &m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d ", &original[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d ", &comp[i][j]);
        }
    }
}

int compare(int r[m]) {
    for (int i = 0; i < m; i++) {
        if (r[i] != comp[0][i]) return 0;
    }
    return 1;
}

void solve(int t) {
    memset(r0, 0, sizeof(int)*MAX);
    memset(r1, 0, sizeof(int)*MAX);
    memset(r2, 0, sizeof(int)*MAX);
    memset(r3, 0, sizeof(int)*MAX);

    for (int i = 0; i < m; i++) {
        r0[i] = original[0][i];
        r1[i] = original[m - 1 - i][0];
        r2[i] = original[m - 1][m - 1 - i];
        r3[i] = original[i][m - 1];
    }

    int d = 0;

    if (compare(r0)) d = 0;
    if (compare(r1)) d = 3;
    if (compare(r2)) d = 2;
    if (compare(r3)) d = 1;

    printf("#%d %d\n", t + 1, d);
}


void print() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", original[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", comp[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n\n\n");

    for (int j = 0; j < m; j++) {
        printf("%d ", r0[j]);
    }
    printf("\n");

    for (int j = 0; j < m; j++) {
        printf("%d ", r1[j]);
    }
    printf("\n");

    for (int j = 0; j < m; j++) {
        printf("%d ", r2[j]);
    }
    printf("\n");

    for (int j = 0; j < m; j++) {
        printf("%d ", r3[j]);
    }
    printf("\n");
}

int main(void) {
    // freopen("input.txt", "r", stdin);
    int T = 0;
    scanf("%d ", &T);
    for (int t = 0; t < T; t++) {
        input();
        solve(t);
        // print();
    }
}