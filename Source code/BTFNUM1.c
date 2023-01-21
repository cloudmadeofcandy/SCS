#include<stdio.h>
#define MAX 100000

int N, M, T, lim1, lim2, count;
int digit[10];

void input() {
    for (int i = 0; i < 10; i++) {
        digit[i] = -1;
    }
    scanf("%d %d ", &N, &M);

    for (int i = 0; i < N; i++) {
        scanf("%d ", &digit[i]);
    }

    scanf("%d %d ", &lim1, &lim2);
}

void print() {
    printf("%d %d %d %d\n", N, M, lim1, lim2);
    for (int i = 0; i < N; i++) {
        printf("%d ", digit[i]);
    }
    printf("\n");
}

void solve(int t) {
    count = 0;
    for (int i = lim1; i <= lim2; ++i) {
        int tempcount = 0;
        int tempno = i;
        while(tempno) {
            int temp = tempno % 10;
            int k = 0;
            while(digit[k] != -1) {
                if (temp == digit[k]) {
                    tempcount++;
                    break;
                }
                k++;
            }
            tempno /= 10;
        }
        if (tempcount >= M) count++;
    }
    printf("#%d %d\n", t+1, count);
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d ", &T);
    for (int t = 0; t < T; t++) {
        input();
        solve(t);
    }
}