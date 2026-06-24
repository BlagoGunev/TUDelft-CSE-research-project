#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
char s[2][maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",s[0]);
        scanf("%s",s[1]);
        int now=1;
        for(int i = 0;i < n;++i)
        {
            if(now==1)
            {
                if(s[0][i]=='1'||s[0][i]=='2')
                now=1;
                else if(s[1][i]=='1'||s[1][i]=='2'){
                    now=1;
                    break;
                }
                else
                now=2;
            }
            else
            {
                if(s[1][i]=='1'||s[1][i]=='2')
                now=2;
                else if(s[0][i]=='1'||s[0][i]=='2')
                {
                    now=1;
                    break;
                }
                else
                now=1;
            }
        }
        if(now==2)
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}