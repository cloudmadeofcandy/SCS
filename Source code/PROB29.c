#include <stdio.h>
#include <string.h>
 
char arr[1005][50000];
int spread[60][15];
int T = 0;
int N = 0;
unsigned long long sum = 0;
char *p; // global pointers since local double pointer does NOT work :) wtf?
void input() {
    
    scanf("%d ", &N);
    memset(arr, 0, 1005 * 50000 * sizeof(char));
    memset(spread, 0, 60 * 15 * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%[^\n]%*c", arr[i]);
    }
}
 
 
void print() {
    for (int i = 0; i < N; i++) {
        printf("%s\n", arr[i]);
    }
}
 
int atoi() {
    int ret = 0;
    while (*p >= '0' && *p <= '9') {
        ret = 10 * ret + (*(p++) - '0');
    }
    return ret;
}
 
 
void assignment() {
    int x, y, val;
    y = *(p++) - 'A';
    x = atoi();
    ++p;
    val = atoi();
    spread[x][y] = val;
}
 
void summation() {
    int rep = atoi();
    p++;
 
    for (int i = 0; i < rep; i++) {
        int x1, x2, y1, y2;
        if (*p >= '0' && *p <= '9') {
            sum += (unsigned long long) atoi();
            p++;
        }
        
        else {
            y1 = *(p++) - 'A';
            x1 = atoi();
 
            if (*p == ':') {
                // if p encounters an ":", find x2 and y2 and then sum up the block
                p++;
                y2 = *(p++) - 'A';
                x2 = atoi();

                if (x1 > x2) {
                    int temp = x1;
                    x1 = x2;
                    x2 = temp;
                }

                if (y1 > y2) {
                    int temp = y1;
                    y1 = y2;
                    y2 = temp;
                }

                for (int j = x1; j <= x2; j++) {
                    for (int k = y1; k <= y2; k++) {
                        sum += (unsigned long long) spread[j][k];
                    }
                }
            }
 
            else if (*p == ' ') {
                // if p encounters a space, sum up the particle
                sum += (unsigned long long) spread[x1][y1];
            }
 
            if (*p != 0 && *p != 13) {
            p++;
            }
        }
    }
}
 
void solve(int t) {
    printf("#%d", t);
    for (int i = 0; i < N; i++) {
        sum = 0;
        p = (char*) &arr[i];
        if (*p == '1') {
            p+=2;
            assignment();
        }
        else if (*p == '2') {
            p+=2;
            summation();
            printf(" %llu", sum);
        }
    }
    printf("\n");
}
 
int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d ", &T);
 
    for (int t = 1; t < T + 1; t++) {
        input();
        // print();
        solve(t);
    }
 
    return 0;
} 