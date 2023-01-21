#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[10005];
char b[10005];
int T;

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

int cpy(char *b, char *a, int len)
{
	memset(b, '\0', len + 1);
	for (int i = 0; i < len; i++)
	{
		b[i] = a[i];
	}
	b[len] = '\0';
	return 0;
}

int main(void)
{
	// freopen("input.txt", "r", stdin);
	scanf("%d ", &T);
	char *position = NULL;
	for (int t = 0; t < T; t++)
	{

		gets(a);
		int len = strlen(a);
		int found = 0;

		for (int i = len; i > 1; i--)
		{
			position = a;
			int numSubstring = len - i + 1;
			for (int j = 0; j < numSubstring; j++)
			{
				cpy(b, position, i);
				if (isPalindrome(b))
				{
					printf("#%d %d %s\n", t + 1, i, b);
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
			printf("#%d -1\n", t + 1);
	}

	return 0;
}