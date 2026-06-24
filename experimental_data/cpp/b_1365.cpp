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
int a[505],b[505];
int main()
{
    int T=read();
    while (T--)
    {
        n=read();
        for (int i=1;i<=n;i++) a[i]=read();
        for (int i=1;i<=n;i++) b[i]=read();
        int flag=1,cnt1=0,cnt2=0;
        for (int i=1;i<n;i++)
        {
            if (a[i]>a[i+1]) flag=0;
        }
        for (int i=1;i<=n;i++) if (b[i]) cnt1=1;else cnt2=1;
        if (flag || (cnt1&&cnt2)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}