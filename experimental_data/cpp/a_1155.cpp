#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,ok;
    char str[300005];
    scanf("%d%s",&n,&str);
    ok = 0;
    for (int i = 1; i < n; i++)
    {
        if (str[i] < str[i - 1])
        {
            ok = 1;
            printf("YES\n%d %d\n",i,i + 1);
            break;
        }
    }
    if (!ok)
    {
        printf("NO\n");
    }
    return 0;
}