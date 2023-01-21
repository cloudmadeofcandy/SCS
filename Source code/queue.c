#include <stdio.h>
#include <limits.h>
#include <string.h>
int main() {
    freopen("input.txt", "r", stdin);
    int t;

    scanf("%d", &t);

    for (int k = 0; k < t; k++) {
        int que[1005], index[1005], res[1005], n;
        memset(res, -1, sizeof(res));
        scanf("%d", &n);

        for (int j = 0; j < n; j++) {
            scanf("%d", &que[j]);
        }
        for (int j = 0; j < n; j++) {
            scanf("%d", &index[j]);
        }

        for (int i = 0; i < n; i++) {
            int min = INT_MAX, ind;
            for (int j = 0; j < n; j++) {
                if (que[j] != -1 && min > que[j]) {
                    min = que[j];
                    ind = j;
                }
            }
            int res_ind = index[ind];
            for (int j = 0; j < n; j++) {
                if (res[j] == -1) {
                    if (res_ind == 0) {
                        res[j] = min;
                        break;
                    } else {
                        res_ind--;
                    }
                }
            }
            que[ind] = -1;
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", res[i]);
        }
        printf("\n");
    }
    return 0;
}