#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;

LL n,f[99];

void init()
{
    f[0] = 1;
    f[1] = 2;
    for(int i=2; i<=92; i++)
        f[i] = f[i-1]+f[i-2];
}


int main()
{
    init();
    while(~scanf("%lld",&n))
    {
        int ans;
        for(int i=0; i<93; i++)
            if(f[i] == n)
            {
                ans = i;
                break;
            }
            else if(f[i] > n)
            {
                ans = i-1;
                break;
            }
        printf("%d\n",ans);
    }

    return 0;
}