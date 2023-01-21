#include<stdio.h>
#include<stdlib.h>
#define MAX 1005
int T, N;
int l1 = -1, l2 = -1;
int a[MAX];

void pr(int *arr) {
    for (int i = 0; i < N; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void input() {
    for (int i = 0; i < N; i++) {
        a[i] = 0;
    }
    scanf("%d ", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d ", &a[i]);
    }
}

int comparator(const void* p1, const void* p2) {
    int l = *((int*) p1);
    int r = *((int*) p2);
    return (r - l);
}

void solve() {
    l1 = -1; l2 = -1;
    int size = sizeof(a) / sizeof(a[0]);
    int frequency[N], index = 0;
    for (int i = 0; i < N; i++) {
        frequency[i] = 1;
    } 
    qsort((void*)a, N, sizeof(a[0]), comparator);
    for (int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            if (a[i] == a[j] && a[i] > 0) {
                a[j] = 0;
                frequency[i]++;
            }
        }
    }


    for (int i = 0; i < N; i++) {
        if (l1 == -1 && frequency[i] > 1) {
            l1 = a[i];
            frequency[i] -= 2;
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        if (l2 == -1 && frequency[i] > 1) {
            l2 = a[i];
            frequency[i] -= 2;
            break;
        }
    }

    if (l1 == -1 || l2 == -1) printf("%d\n", -1);
    else printf("%d\n", l1 * l2);
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d ", &T);
    for (int t = 0; t < T; t++) {
        input();
        qsort((void*)a, N, sizeof(a[0]), comparator);
        solve();
    }
}