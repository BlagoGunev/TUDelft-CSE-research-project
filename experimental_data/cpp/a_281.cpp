#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<set>
#include<string.h>
#include<math.h>
int n,m,t;
int main()
{
    char str[10005];
    scanf("%s",str);
    if(str[0]>='a' && str[0]<='z')
        str[0]-=('a'-'A');
    printf("%s\n",str);
	scanf(" ");
}