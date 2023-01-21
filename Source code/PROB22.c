#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* cpy(char *dest, char *orig, int len) {
    memset(dest, 0, strlen(dest));
    for (int i = 0; i < len; i++) {
        *(dest + i) = *(orig + i);
    }
    return dest;
}

int search(char* ee, char* er, int mode) {
    if (mode == 0) {       
        int len_ee = strlen(ee);
        int len_er = strlen(er);
        char temp[105];
        char* p = er;
        while (p != (er + len_er - len_ee)) {
            cpy(temp, p, len_ee);
            if (strcmp(temp, ee) == 0) return (p - er);
            p++;
        }
        return -1;
    }

    if (mode == 1) {       
        int len_ee = strlen(ee);
        int len_er = strlen(er);
        char temp[105];
        char* p = (er + len_er - len_ee);
        while (p != er) {
            cpy(temp, p, len_ee);
            if (strcmp(temp, ee) == 0) return (p - er);
            p--;
        }
        return -1;
    }
}

int main(void) {
    int T = 0; 
    char P[25];
    char S[105];
    
    freopen("input.txt", "r", stdin);
    
    scanf("%d ", &T);
    
    for (int t = 0; t < T; t++) {    
        scanf("%s", P);
        scanf("%s", S);
        int mode = 0;
        char start[25];
        char end[25];

        // printf("%s\n%s\n", P, S);
        char* p = P;
        char* q = start;

        for (p = P; *p != 0; p++) {
            if (*p == '.') {
                if (*(p + 1) == '*') {
                    mode = 2;
                    p += 2;
                    break;
                }

                // if (*(p + 1) != 0) {
                mode = 1;
                p++;
                break;
                // }
                // mode = 0;
                // break;
            }
            *q = *p;
            q++;
        }

        *q = '\0';
        q = end;

        for (p; *p != 0 && mode != 0; p++) {
            *q = *p;
            q++;
        }
        *q = '\0';
        // printf("%s\n%s\n", (start), (end));

        // printf("mode%d&%d&%d\n", mode, strlen(start), strlen(end));

        int len_start = strlen(start);
        int len_end = strlen(end);
        int len_S = strlen(S);

        switch(mode) {
            case 2: {
                if (len_start == 0 && len_end == 0) printf("%d\n", strlen(S));

                else if (len_start == 0) {
                    int pos = search(end, S, 1);
                    if (pos >= 0) {
                        printf("%d\n", pos + strlen(end));
                    }
                    else printf("-1\n");
                }

                else if (len_end == 0) {
                    int pos = search(start, S, 1);
                    if (pos >= 0) {
                        printf("%d\n", len_S  - pos);
                    }
                    else printf("-1\n");
                }

                else {
                    int start_pos = search(start, S, 0);
                    int end_pos = search(end, S, 1);
                    if (start_pos >= 0 && end_pos >= 0) {
                        printf("%d\n", end_pos - start_pos + len_end);
                    }
                    else printf("-1\n");

                }
                break;
            }

            case 1: {
                if (len_start == 0 && len_end == 0) printf("%d\n", 1);

                else if (len_start == 0) {
                    int pos = search(end, S, 0);
                    if (pos >= 0) {
                        printf("%d\n", 1 + len_end);
                    }
                    else printf("-1\n");
                }

                else if (len_end == 0) {
                    int pos = search(start, S, 0);
                    if (pos >= 0) {
                        printf("%d\n", 1 + len_start);
                    }
                    else printf("-1\n");
                }

                else {
                    int start_pos = search(start, S, 0);
                    int end_pos = search(end, S, 1);
                    if (start_pos >= 0 && end_pos >= 0) {
                        printf("%d\n", len_end + len_start + 1);
                    }
                    else printf("-1\n");
                }
                break;
            }

            case 0: {
                int pos = search(start, S, 0);
                if (pos >= 0) {
                    printf("%d\n", len_start);
                }
                    
                else printf("%d\n", -1);
            }
        }
    }

    return 0;
}