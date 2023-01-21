#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int M, N, T;

int main() {
    // FILE *fp = freopen("input.txt", "r", stdin);
    scanf("%d ", &T);

    for (int t = 1; t <= T; t++) {
        scanf("%d %d ", &M, &N);
        int rows = 5 * M + 1;
        int cols = 5 * N + 1;
        char temp[rows][cols];

        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                scanf("%c ", &temp[j][k]);
            }
        }

        // for (int j = 0; j < rows; j++) {
        //     for (int k = 0; k < cols; k++) {
        //         printf("%c", temp[j][k]);
        //     }
        //     printf("\n");
        // }

        int res[5] = {0,0,0,0,0};

        for (int i = 1; i < rows; i += 5) {
            for (int j = 1; j < cols; j += 5) {
                for (int k = 0; k < 5; k++) {
                    if (temp[i + k][j] == '.') {
                        res[k]++;
                        break;
                    }
                    if (k == 4) {
                        res[k]++;
                    }
                }
            }
        }

        printf("#%d %d %d %d %d %d\n", t, res[0], res[1], res[2], res[3], res[4]);

    }
    return 0;
}