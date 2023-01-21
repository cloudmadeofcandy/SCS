#include<stdio.h>
#include<string.h>

void main() {
    freopen("input.txt", "r", stdin);
    char inp[200];
    char ret[200];
    int N;
    int temp;
    while(1) {
        scanf("%d", &N);
        if (N == 0) {
            break;
        }
        memset(inp, 0, sizeof(inp));
        memset(ret, 0, sizeof(ret));
        scanf("%s", inp);
        
        for (int i = N; i < strlen(inp); i += 2*N) {
            for (int j = 0; j < (N/2); j++) {
                temp = inp[i + j];
                inp[i + j] = inp[N - 1 + i - j];
                inp[N - 1 + i - j] = temp;
            }
        }

        int M = strlen(inp) / N;
        int count = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                ret[count++] = *(inp + i + N*j);
            }
        }
        ret[count] = '\0';

        printf("%s\n", ret);
    }
}