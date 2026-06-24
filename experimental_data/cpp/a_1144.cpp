#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
char s[105];
int a[105];
int vis[150];
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        int flag=0;
        scanf("%s",s);
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            a[i]=s[i]-96;

        }
        sort(a,a+len);
        for(int i=1;i<len;i++)
        {
            if(a[i]-a[i-1]!=1)
            {
                printf("No\n");
                flag=1;
                break;
            }
        }
        if(flag==0) printf("Yes\n");
    }
    return 0;
}