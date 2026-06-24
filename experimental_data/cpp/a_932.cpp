#include<stdio.h>
#include<string.h>
int main()
{
    char s[1050];
    scanf("%s",s);
    printf("%s",s);
    int l=strlen(s);
    for(int i=l-1; i>=0; i--)
        printf("%c",s[i]);
    printf("\n");
    return 0;
}