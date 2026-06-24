#include <bits/stdc++.h>
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define in inline
#define re register
using namespace std;
typedef long long ll;
typedef double db;
in int read()
{
    int ans=0,f=1;char c=getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=-1;
    for (;isdigit(c);c=getchar()) ans=(ans<<3)+(ans<<1)+(c^48);
    return ans*f;
}
in int cmin(int &a,int b) {return a=min(a,b);}
in int cmax(int &a,int b) {return a=max(a,b);}
int n;
int pos[200005];
int cnt[200005];
int main()
{
    n=read();
    for (int i=1;i<=n;i++)
    {
        pos[read()]=i;
    }
    for (int i=1;i<=n;i++)
    {
        cnt[(i-pos[read()]+n)%n]++;
    }
    int maxx=0;
    for (int i=0;i<n;i++) cmax(maxx,cnt[i]);
    cout<<maxx<<endl;
    return 0;
}