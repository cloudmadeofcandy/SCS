#include<stdio.h>

int max(int n, int input[n]) {
    int max = 0, count = 0;
    for (int i = 0; i < n; i++) {
        if (input[i] == 1) count++;
        else {
            if (count > max) max = count;
            count = 0;
        }
    }
    printf("ROADLEN = %d\n", n);
    return max;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    int roadLen, units = 0;
    scanf("%d %d ", &roadLen, &units);
    int a[roadLen];
    int b[roadLen];
    int holes = 0;

    for (int i = 0; i < roadLen; i++) {
        scanf("%d ", &a[i]);
        if (a[i] == 0) holes++;
    }

    int Max = 0;
    for (int j = 0; j < roadLen; j++) {

        for (int i = 0; i < roadLen; i++) {
            b[i] = a[i];
            //printf("%d ", b[i]);
        }

        int temp = units;
        int count = 0;
        int p = j;
        while (temp && p < roadLen) {
            if (b[p] == 1) {
            }
            else {
                b[p] = 1;
                temp--;
            }
            p++;
        }
        int temp2 = max(roadLen, b);
        if (temp2 > Max) Max = temp2;
    }
    
    printf("_______________\n");
    // printf("%d\n", max(15, ));
    printf("%d ", Max); 
}