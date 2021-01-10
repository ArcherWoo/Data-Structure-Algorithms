#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int BF(char *s, char *p)
{
	int i = 0;
	int j = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);

	while(i < sLen && j < pLen)
	{
		if (s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0; 
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
	printf("%d\n", BF("hello world", "world"));
	return 0;
}
