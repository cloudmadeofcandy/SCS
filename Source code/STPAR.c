#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[1005];
int arranged[1005];
int queue[1005];
int n = 1;

int comparator(const void* i, const void* j) {
    return *((int*)i) - *((int*)j);
}

void print() {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arranged[i]);
    }
}

void solve() {

};

int main() {
    freopen("input.txt", "r", stdin);

    while (1) {
        memset(queue, 0, 1005 * 4);
        memset(arr, 0, 1005 * 4);
        memset(arranged, 0, 1005 * 4);
        scanf("%d\n", &n);
        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            scanf("%d ", &arr[i]);
            arranged[i] = arr[i];
        }

        qsort(arranged, n, sizeof(int), comparator);
        print();
        //solve();
    }
    return 0;
}