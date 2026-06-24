#pragma GCC optimize(2)
#include<algorithm>
#include<iostream>
#include<string.h>
#include<sstream>
#include<stdio.h>
#include<iomanip>
#include<math.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define  mem(a,b) memset(a,b,sizeof(a))
#define mo 1000000007
#define inf 0x3f3f3f3f
#define pi 3.14159265358979323846
#define e 2.71828182845904523536

typedef long long ll;
using namespace std;

struct node
{
    int x,id;
}a[1005];

bool cmp(const node &a,const node &b)
{
    return a.x<b.x;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i].x),a[i].id=i;
        sort(a+1,a+n+1,cmp);
        ll ans=0;
        if(n==2||m<n)
        {
            printf("-1\n");
            continue;
        }
        for(int i=1;i<=n;i++)
            ans+=2*a[i].x;
        ans+=(m-n)*(a[1].x+a[2].x);
        cout<<ans<<endl;
        if(m>=2*n-3)
        {
            for(int i=1;i<=m-2*n+4;i++)
                printf("%d %d\n",a[1].id,a[2].id);
            for(int i=3;i<=n;i++)
            {
                printf("%d %d\n",a[1].id,a[i].id);
                printf("%d %d\n",a[2].id,a[i].id);
            }
        }
        else
        {
            for(int i=n;i>n-(m-n);i--)
            {
                printf("%d %d\n",a[1].id,a[i].id);
                printf("%d %d\n",a[2].id,a[i].id);
            }
            for(int i=1;i<2*n-m;i++)
                printf("%d %d\n",a[i].id,a[i+1].id);
            printf("%d %d\n",a[1].id,a[2*n-m].id);

        }
    }
    return 0;
}