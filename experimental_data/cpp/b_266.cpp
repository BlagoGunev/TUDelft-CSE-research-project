#include <bits/stdc++.h>

using namespace std;

#include<stdio.h>
#include<string.h>

int main()
{
    char s[100];
    int n,i,t,j,l;

    scanf("%d %d", &n, &t);
    getchar();
    fgets(s, sizeof(s), stdin);

    l = strlen(s);

    for(j=0; j<t; j++)
    {

    for(i=0; i<l-1; i++)
    {
        if(s[i]=='B' && s[i+1]=='G')
        {s[i]='G';
        s[i+1]='B';
        i++;}
    }
    }

    puts(s);

return 0;
}