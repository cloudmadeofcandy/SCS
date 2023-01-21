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

int check(char* word, char* dict) {
    char* p = word;
    char* q = dict;
    int len_word = strlen(word);
    int len_dict = strlen(dict);

    if (strcmp(word, dict) == 0) {
        return 0;
    }

    

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

int main() {
    printf("%d\n", check("helpo", "hello"));
    return 0; 
}