#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 1000005
#define maxm 200005
#define INF 1234567890
#define eps 1e-15
#define p 1000000007
const double pi=acos(-1);
template<class T>inline bool read(T &x)
{
    x=0;register char c=getchar();register bool f=0;
    while(!isdigit(c)){if(c==EOF)return false;f^=c=='-',c=getchar();}
    while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
    if(f)x=-x;
    return true;
}
template<class T>inline void print(T x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10^48);
}
template<class T>inline T mind(T a,T b){if(b<a)return b;return a;}
template<class T>inline void print(T x,char c){print(x),putchar(c);}
template<class T,class ...S>inline bool read(T &x,S &...y){return read(x)&&read(y...);}
ll t,n,ans,res[maxn];
int main()
{
    //freopen("test.in","r",stdin);
    read(t);
    while(t--)
    {
        read(n);
        ans=0;
        for(ll i=1,j;i<=n;i=j+1)
        {
            j=n/(n/i);
            ans++;
            res[ans]=n/i;
        }
        print(ans+1,'\n');
        print(0,' ');
        for(ll i=ans;i>1;i--)
            print(res[i],' ');
        print(res[1],'\n');
    }
    return 0;
}