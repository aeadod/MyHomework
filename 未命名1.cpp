
#include <stdio.h>
#include <string.h>
 
#define MAX 20

 
int isithuiwen(char *s)
{
	int n=strlen(s);
	int i, j,count=0;
	for (i = 0, j = n - 1; i < n, j >= 0; i++, j--)
	{
		if (*(s + i) == *(s + j))
		{
			count++;
		}
	}
	if (count == n)
		return 1;
    else
        return 0;
}

int main()
{
    char s[MAX];
 
    scanf("%s", s);
    if ( isithuiwen(s)==1 )
        printf("Yes\n");
    else
        printf("No\n");
    printf("%s\n", s);
 
    return 0;
}



