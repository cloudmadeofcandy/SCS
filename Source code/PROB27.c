#include<stdio.h>
#include<string.h>

char dict[1005][20];
char word[105][20];

int N, M;

void input() {
    memset(dict, 0, 1005*20);
    memset(word, 0, 105*20);

    scanf("%d ", &N);
    scanf("%d ", &M);

    for (int i = 0; i < N; i++) {
        scanf("%s", dict[i]);
    }

    for (int i = 0; i < M; i++) {
        scanf("%s", word[i]);
    }
    
}

void print() {
    for (int i = 0; i < N; i++) {
        printf("%s\n", dict[i]);
    }
    printf("_______________\n");
        for (int i = 0; i < M; i++) {
        printf("%s\n", word[i]);
    }
}

int check(char* word, char* dict) {

    if (strcmp(word, dict) == 0) {
        return 0;
    }

    char* p = word;
    char* q = dict;
    int len_word = strlen(word);
    int len_dict = strlen(dict);

    if (len_word - len_dict == -1) {
        // truong hop go thieu ky tu cuoi
        while (*p != 0) {
            if (*p != *q) return -1;
            p++;
            q++;
        }
        return 1;
    }

    if (len_word == len_dict) {
        // truong hop go sai ky tu cuoi
        while (*(p + 1) != 0) {
            if (*p != *q) return -1;
            p++;
            q++;
        }
        return 2;
    }

    if (len_word - len_dict == 1) {
        // truong hop go thua ky tu cuoi
        while (*q != 0) {
            if (*p != *q) return -1;
            p++;
            q++;
        }
        return 3;
    }

    return -1;
}

void solve(int t) {
    printf("#%d", t);
    for (int i = 0; i < M; i++) {
        //word
        int result = 4;
        for (int j = 0; j < N; j++) {
            //dict
            int res = check(word[i], dict[j]);
            //printf("%s %s %d\n", word[i], dict[j], res);
            if (res == 0) {
                result = 0;
                break;
            }

            else if (res > 0 && result == 4) {
                result = res;
            }

            else if (res > 0 && result != 4) {
                result = 5;
                break;
            }
        }
        printf(" %d", result);
    }

    printf("\n");
}

int main () {
    freopen("input.txt", "r", stdin);
    int T = 0;
    scanf("%d ", &T);
    for (int t = 1; t <= T; ++t) {
        input();
        print();
        //solve(t);
    }
}