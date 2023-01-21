#include<stdio.h>
#include<string.h>

#define MAX 1005

int N = 0;
int a[MAX];
int b[MAX];

void input() {
    scanf("%d ", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d ", &a[i]);
    }

    for (int i = 0; i < N; i++) {
        scanf("%d ", &b[i]);
    }
}

void print() {
    for (int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}

int isOutOfVector(int x) {
    if (x < 0 || x >= N) {
        return 1;
    }
    return 0;
}

void solve(int t) {
    int point = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != b[j]) {
                continue;
            }
            int left = j - 1;
            int right = j + 1;

            while (!isOutOfVector(left)) {
                if (b[left] > 0) break;
                else left--;
            }

            while (!isOutOfVector(right)) {
                if (b[right] > 0) break;
                else right++;
            }
            
            print();
            printf("j: %d\n", j);
            printf("left: %d\n", left);
            printf("right: %d\n", right);

            if (isOutOfVector(left) && isOutOfVector(right)) {
                printf("No neighbors\n");
                printf("---------------\n");
                point = point + a[j];
                b[j] = -1;
                continue; 
            }

            if (isOutOfVector(left)) {
                printf("Right neighbor\n");
                printf("---------------\n");
                point = point + a[right];
                b[j] = -1;
                continue;
            }

            if (isOutOfVector(right)) {
                printf("Left neighbor\n");
                printf("---------------\n");
                point = point + a[left];
                b[j] = -1;
                continue;
            }

            if (!isOutOfVector(left) && !isOutOfVector(right)) {
                printf("Both neighbors\n");
                printf("---------------\n");
                point = point + a[left] * a[right];
                b[j] = -1;
                continue;
            }
        }
    }
    printf("#%d %d\n", t + 1, point);
    printf("+++++++++++++++++++++++\n");
}

int main(void) {
    freopen("input.txt", "r", stdin);
    int T = 0;
    scanf("%d ", &T);

    for (int t = 0; t < T; t++) {
        input();
        //print();
        solve(t);
    }
}