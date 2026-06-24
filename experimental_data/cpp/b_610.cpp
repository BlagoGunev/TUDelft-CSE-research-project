#include<bitset>
#include<map>
#include<vector>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#define inf 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

inline int in()
{
    int res=0;char c;
    while((c=getchar())<'0' || c>'9');
    while(c>='0' && c<='9')res=res*10+c-'0',c=getchar();
    return res;
}
const int N=400100;

ll a[N],ans;

int main()
{
    int n=in();
    int mn=inf;

    for(int i=0;i<n;i++)
    {
        a[i]=in();
        if(a[i]<mn)
        {
            mn=a[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        a[i]-=mn;
    }
    ans = 1LL*mn*n;
    for(int i=0;i<n;i++)
    {
        a[i+n]=a[i];
    }
    int num=0;
    for(int i=0;i<2*n;i++)
    {
        int cnt=0;
        for(;a[i];i++)
        {
            cnt++;
        }
        num=max(num,cnt);
    }
    cout<<(ans+num)<<endl;
    return 0;
}