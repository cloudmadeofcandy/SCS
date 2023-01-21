#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int reverseNum(int n) {
    int remainder = 0, reversed = 0;
    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }
    return reversed;
}

int main(int argc, char* argv[]) {
    //freopen("input.txt", "r", stdin);
    int T, a, b;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d", &a);
        scanf("%d", &b);
        printf("%d\n", reverseNum(reverseNum(a) + reverseNum(b)));
    }
    return 0;
}