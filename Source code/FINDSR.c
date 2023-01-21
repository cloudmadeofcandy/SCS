#include<stdio.h>
#include<string.h>

char a[100005];

int input() {
    scanf("%s", a);
    return strcmp(a, "*");
}

void solve() {
    int len = strlen(a);
    int count = 0;
    for (int i = 1; i <= len; i++) {
        
    }
}

int main(void) {
    freopen("input.txt", "r", stdin);
    while(input()) {
        printf("%s\n", a);
        solve();
    }
    return 0;
}