#include<stdio.h>

char result(int a) {
    if (a % 2 == 1) a -= 1;
    if (a == 0) return 'A';
    if (a == 2) return 'B';
    if (a == 4) return 'C';
    if (a == 6) return 'D';
    if (a == 8) return 'E';
}

int main(void) {
    //freopen("input.txt", "r", stdin);
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 9; y++) {

                if (x < 4 || x > 9 || y < 0 || y > 8) {
                    printf("%d %d : %d\n", x, y, -1);
                    continue;
                }

                if (x == 4) {
                    if (y % 2 == 1) {
                        printf("%d %d : %d\n", x, y, -1);
                        continue;
                    }
                }

                if (x == 9 && (y == 3 || y == 5)) {
                    printf("%d %d : 6 C\n", x, y);
                    continue;
                }

                int distance = x - 3;

                if (y % 2 == 1) distance++;

                char d = result(y);
                
                printf("%d %d : %d %c\n", x, y, distance, d);
                continue;
                    }
                }
}