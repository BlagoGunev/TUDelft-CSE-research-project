#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
int n,m;
char a[60][60];
int main()
{
    int i,j,k,q=100,w=100,e=-100,r=-100;
    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++)scanf("%s",a[i]);
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            if (a[i][j]=='*')
            {
                q=min(q,i);
                w=min(w,j);
                e=max(e,i);
                r=max(r,j);
            }
        }
    }
    for (i=q;i<=e;i++)
    {
        for (j=w;j<=r;j++)
        {
            putchar(a[i][j]);
        }
        puts("");
    }
    return 0;
}