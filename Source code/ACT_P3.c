#include<stdio.h>
#include <string.h>
#define SIZE 5
#define MAX 30
int m;
int a[SIZE][SIZE];
int b[2*MAX];

void input() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            a[i][j] = 0;
        }
    }
	
	for (int i = 0; i < 2 * MAX; i+=2) {
        b[i] = 0;
        b[i+1] = 0;
    }
    
    scanf("%d ", &m);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d ", &a[i][j]);
        }
    }

    for (int i = 0; i < 2 * m; i+=2) {
        scanf("%d %d ", &b[i], &b[i+1]);
    }

}

void print() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void ROL(int start, int end) {
    start--;
    end--;
    int temp = a[0][start];
    for (int i = start; i < end; i++) {
        a[0][i] = a[0][i + 1];
    }
    a[0][end] = temp;
}

void ROR(int start, int end) {
    start--;
    end--;
    int temp = a[0][end];
    for (int i = end; i > start; i--) {
        a[0][i] = a[0][i - 1];
    }
    a[0][start] = temp;
}

void solve(int t) {
    for (int i = 0; i < 2 * m; i += 2) {
        if (b[i] > b[i + 1]) ROR(b[i + 1], b[i]);
        if (b[i] < b[i + 1]) ROL(b[i], b[i + 1]);
    }
    printf("Case #%d:\n", t + 1);
    print();
}

int main(void) {
    freopen("input.txt", "r", stdin);
    int T = 0;
    scanf("%d ", &T);
    for (int t = 0; t < T; t++) {
        input();
        solve(t);
    }
}