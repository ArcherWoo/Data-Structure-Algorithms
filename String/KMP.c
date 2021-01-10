#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void GetNext(char *p, int *next)
{
	int i = -1;
	int j = 0;
	int pLen = strlen(p);
	next[0] = i;

	while(j < pLen -1)
	{
		if (i == -1 || p[i] == p[j])
		{
			i++;
			j++;
			next[j] = i;
			/* optimize version
			if (p[i] != p[j])
			{
				next[j] = i;
			}
			else
			{
				next[j] = next[i];
			}
			*/
		}
		else
		{
			i = next[i];
		}
	}
}

int kmp(char *s, char *p)
{
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	int next[100];
	GetNext(p, next);

	while(i < sLen && j < pLen)
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == pLen)
	{
		return i - j;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", kmp("hello world", "world"));
	return 0;
}
