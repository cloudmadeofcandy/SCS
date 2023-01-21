#include <stdio.h>
long N;

void input() {
    scanf("%ld ", &N);
}


void solve() {
    long count = 0;
    for (long i = 1; i <= N; i++) {
        long y = (long) N / i;
        count += (long) i * y;
    }
    printf("%ld\n", count % 1000007);
}

int main()
{
    freopen("input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    
    for (int i = 1; i <= T; i++) {
        input();
        solve();
    }
    return 0;
}