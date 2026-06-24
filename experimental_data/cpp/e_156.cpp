#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int INF=3e5+5;
const int INFM=5e6+5;
const int Mod3[]={0,223092870,58642669,600662303,33984931,8633};
const int Mod2[]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int n,a[INF],d[INF],P[INF],c[INF],num[INF];
int g[INF],p[INF],res[INF],powba[INF],m;
signed ff[INFM],F[INFM];
string s1[INF];
bool prime[INF];int Prime[INF];
int calc(char x,int t) {
    if (x=='?') return t;
    else if (x>='0' && x<='9') return x-'0';
    else if (x>='A' && x<='F') return x-'A'+10;
    else {assert(0);return -1;}
}
signed main()
{
    // freopen("data.in","r",stdin);
    // freopen("test.out","w",stdout);
    memset(prime,1,sizeof prime);
    prime[0]=prime[1]=0;
    for (int i=2;i<=100;i++) {
        if (prime[i]) Prime[++Prime[0]]=i;
        for (int j=1;j<=Prime[0] && Prime[j]*i<=100;j++) {
            prime[Prime[j]*i]=0;
            if (!(i%Prime[j])) break;
        }
    }
    // for (int i=1;i<=Prime[0];i++)
    //     cout<<Prime[i]<<",";
    // cout<<"\n";
    // 1~Prime[0] 
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n; int B=5;
    for (int i=0;i<n;i++) cin>>a[i];
    cin>>m;
    for (int i=1;i<=m;i++) {
        cin>>d[i]>>s1[i]>>c[i];p[i]=i;
        int len1=0,ba=1;
        while (n>=ba) len1++,ba*=d[i]; 
        powba[0]=1;
        for (int u=1;u<=len1;u++)
            powba[u]=powba[u-1]*(d[p[i]]+1);
        num[i]=0;
        int len=s1[i].size();
        for (int j=0;j<len;j++) { 
            char c=s1[i][j];
            if (c=='?' && len-1-j<len1)
                num[i]=num[i]*(d[i]+1)+calc(c,d[i]);
            else if (c!='?') num[i]=num[i]*(d[i]+1)+calc(c,d[i]);
        }
    }
    sort(p+1,p+1+m,[](int x,int y){return d[x]<d[y];});
    for (int l=1;l<=m;l++) {
        int r=l;
        while (r+1<=m && d[p[r]]==d[p[r+1]]) r++;
        int len=0,ba=1;
        while (n>=ba) len++,ba*=d[p[l]]; 
        powba[0]=1;
        for (int u=1;u<=len;u++)
            powba[u]=powba[u-1]*(d[p[l]]+1);
        for (int s=0;s<powba[len];s++) {
            ff[s]=0;
            for (int u=0;u<len;u++)
                if (s/powba[u]%(d[p[l]]+1)==d[p[l]]) ff[s]=powba[u]; 
        }
        for (int i=0;i<n;i++) {
            int u=i; g[0]=0;
            while (u) {g[++g[0]]=u%d[p[l]];u/=d[p[l]];}
            int ba2=0;
            for (int w=g[0];w;w--)
                ba2*=(d[p[l]]+1),ba2+=g[w];
            P[i]=ba2;
        }
        for (int T=1;T<=B;T++) {
            // int Mod=Prime[T];
            for (int s=0;s<powba[len];s++) F[s]=1;
            for (int i=0;i<n;i++) F[P[i]]=a[i]%Mod3[T];
            for (int s=0;s<powba[len];s++) {
                if (!ff[s]) continue;
                if (!F[s]) continue;
                for (int v=1;v<=d[p[l]];v++)
                    F[s]=1ll*F[s]*F[s-v*ff[s]]%Mod3[T];
            }
            // cerr<<F[0]<<" "<<F[1]<<" "<<a[0]<<" "<<P[0]<<" qwq?\n";
            for (int i=l;i<=r;i++) {
                if (res[p[i]]) continue;
                // cerr<<num[p[i]]<<" "<<F[num[p[i]]]<<" "<<powba[len]<<" qwq?\n";
                for (int t1=1;t1<=Prime[0];t1++) {
                    if (Mod3[T]%Mod2[t1]) continue;
                    if ((F[num[p[i]]]+c[p[i]])%Mod2[t1]==0) {
                        res[p[i]]=Mod2[t1];
                        break;
                    }
                }
            }
        }
        l=r;
    }
    for (int u=1;u<=m;u++)
        cout<<(!res[u]?-1:res[u])<<"\n";
    return 0;
}