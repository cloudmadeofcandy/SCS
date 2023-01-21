#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int T, H, W, M, N, sum, max;

int solve(int* input, int i, int j, int H, int W, int M, int N) {
    int temp = 0;
    for (int q = 0; q < H; q++) {
        for (int a = 0; a < W; a++) {
            if ((q == 0 || a == 0 || q == H - 1 || a == W - 1)&&(*(input + (q + i) * N + a + j) % 2 == 0)) {
                temp += *(input + (q + i) * N + a + j);
            }
            // if ((q == 0 || a == 0 || q == H - 1 || a == W - 1)) {
            //     //temp += *(input + (q + i) * N + a + j);
            //     printf("%d ", *(input + (q + i) * N + a + j));
            // }
        }
        //printf("\n");
    }
    return temp;
}

void main() {
    freopen("input.txt", "r", stdin);
    scanf("%d ", &T);
    sum = 0; max = 0;

    for (int t = 0; t < T; t++) {
        scanf("%d %d %d %d ", &H, &W, &M, &N);
        int input[M][N];

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d ", &input[i][j]);
            }
        }

        sum = 0, max = 0;

        for (int i = 0; i < M - H + 1; i++) {
            for (int j = 0; j < N - W + 1; j++) {
                sum = solve(input, i, j, H, W, M, N);
                if (sum > max) max = sum;
            }
        }
        
        printf("#%d %d\n", t + 1, max);
        
    }
}