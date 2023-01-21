#include<stdio.h>
#include<string.h>

char a[3005];

void input() {
    memset(a, '\0', 3005);
    scanf("%s ", a);
}

int isPalindrome(char str[], int len) {
    //printf("%s\n", str);
    int l = 0;
    int h = len - 1;
    while (h > l) {
        if (str[l++] != str[h--]) {
            return 0;
        }
    }
    return 1;
}

void solve() {
    int count = 0;
    int len = strlen(a);
    int lenCopy = len;
    while(len) {
        int numIteration = len - lenCopy;
        char* p = a;
        for (int i = 0; i <= numIteration; i++) {
            if (isPalindrome(p, lenCopy)) count++;
            p++;
            // printf("%s\n", p);
        }
        if (count != 0) break;
        else lenCopy--;
    }
    printf("%d %d\n", lenCopy, count);
}

int main(void) {
    
    //freopen("input.txt", "r", stdin);

    int T = 0;
    scanf("%d ", &T);

    for (int t = 0; t < T; t++) {
        input();
        //printf("%s\n", a);
        solve();
    }
    
    return 0;
}