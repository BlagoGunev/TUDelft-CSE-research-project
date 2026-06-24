#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
bool cmp(int a,int b)
{
    return a>b;
}
int main(void)
{
    int b,g,n,k;
    while(scanf("%d%d%d",&b,&g,&n)!=EOF)
    {
        k=0;
        for(int i=0;i<=b;i++)
        {
            for(int j=0;j<=g;j++)
            {
                if(i+j==n)
                    k++;
            }
        }
        printf("%d\n",k);
    }
    return 0;
}