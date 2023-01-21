#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1005

int T, N;
char a[MAX][MAX];
char b[MAX];
char c[MAX];


int input() {
    scanf("%d ", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%c ", &a[i][j]);
        }
    }
}

void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", a[i][j]);
        }
        printf("\n");
    }
}

int cpy(char *b, char *a, int len)
{
	memset(b, '\0', MAX);
	for (int i = 0; i < len; i++)
	{
		b[i] = a[i];
	}
	b[len] = '\0';
	return 0;
}

int isPalindrome(char *str)
{
	int i, len, temp = 1;
	len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] != str[len - i - 1])
		{
			temp = 0;
			break;
		}
	}
	return temp;
}

char* palindromeCheck(char *str) {
    char *position = NULL;
    int len = strlen(str);
    int found = 0;

    for (int i = len; i > 1; i--)
    {
        position = str;
        int numSubstring = len - i + 1;
        for (int j = 0; j < numSubstring; j++)
        {
            cpy(c, position, i);
            if (isPalindrome(c))
            {
                found = 1;
                break;
            }
            else
                position++;
        }
        if (found == 1)
            break;
    }
    if (found == 0)
        return NULL;
    else return c;
}

char* fetchHorizontal(int index) {
    memset(b, '\0', MAX);
    for (int i = 0; i < N; i++) {
        b[i] = a[index][i];
    }
    return b;
}

char* fetchVertical(int index) {
    memset(b, '\0', MAX);
    for (int i = 0; i < N; i++) {
        b[i] = a[i][index];
    }
    return b;
}

void solve(int t) {
    int index = -1;
    int len = -1;
    int isVertical = 0;
    char d[MAX];
    for (int i = 0; i < N; i++) {
        fetchHorizontal(i);
        char* ans = palindromeCheck(b);
        if (c != NULL) {
            int lenC = strlen(c);
            if (lenC > len) {
                len = lenC;
                index = i;
                cpy(d, c, strlen(c));
                // printf("%d\n", len);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        fetchVertical(i);
        char* ans = palindromeCheck(b);
        if (c != NULL) {
            int lenC = strlen(c);
            if (lenC > len) {
                len = lenC;
                index = i;
                isVertical = 1;
                cpy(d, c, strlen(c));
            }
        }
    }
    
    if (len == -1) {
        printf("#%d -1\n", t + 1);
    }
    else {
        if (isVertical) {
            printf("#%d %d %s\n", t + 1, len, d);
        }
        else 
            printf("#%d %d %s\n", t + 1, len, d);
    }
}


int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d ", &T);
    for (int t = 0; t < T; t++) {
        input();
        solve(t);
    }
    // char d[] = "AABB";
    // char* c = palindromeCheck(d);
    // printf("%s\n", c);
    
    return 0;
}