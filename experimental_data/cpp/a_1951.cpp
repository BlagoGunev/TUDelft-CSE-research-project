#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3fll
#define debug(x) cerr<<#x<<"="<<x<<endl
using namespace std;
using ll=long long;
using ld=long double;
using pli=pair<ll,int>;
using pi=pair<int,int>;
template<typename A>
using vc=vector<A>;
inline int read()
{
    int s=0,w=1;char ch;
    while((ch=getchar())>'9'||ch<'0') if(ch=='-') w=-1;
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    return s*w;
}
char s[200005];
int main()
{
    int T=read();
    while(T--)
    {
        int n=read(),c=0;
        int mi=n+1,ma=0;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) if(s[i]=='1')
        {
            c++;
            mi=min(mi,i);
            ma=max(ma,i);
        }
        if(c&1) printf("NO\n");
        else if(c!=2||mi!=ma-1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}