#include<bits/stdc++.h>
using namespace std;
const int N=3204,C=N*N/2;
using ll=long long;
mt19937_64 rg(random_device{}());
int rd(int l,int r){return l+rg()%(r-l+1);}
int T,n,m,a[N],b[N],c[N],p[N],q[N];
struct dat{
    ll x,y;
    void init(int X,int Y){
        int d=__gcd(X,Y);
        x=X/d,y=Y/d;
    }
    bool operator<(const dat &z)
    const{return x*z.y<y*z.x;}
    bool operator==(const dat &z)
    const{return x==z.x&&y==z.y;}
}d[C];
ll d1[N];
string s;
int ck(){
    for(int i=1,d=0;i<=n;++i)
        if((d+=c[p[i]])>0)return 0;
    return 1;
}
vector<int>lk[C];
int main(){
    ios::sync_with_stdio(false);
    int i,j,k,l,r,x,y;
    cin>>T;
    while(T--){
        cin>>n,m=0,n*=2;
        for(i=1;i<=n;++i){
            cin>>a[i]>>b[i]>>s;
            p[i]=i,c[i]=s[0]=='('?-1:1;
        }
        sort(p+1,p+n+1,[&](int x,int y){
            return b[x]==b[y]?(a[x]==a[y]?c[x]<c[y]:a[x]<a[y]):b[x]<b[y];
        });
        if(ck()){puts("YES");continue;}
        for(i=1;i<=n;++i)
            for(j=i+1;j<=n;++j)
                if(a[p[i]]>a[p[j]])
                    d[++m].init(b[p[j]]-b[p[i]],a[p[i]]-a[p[j]]);
        if(!m){puts("NO");continue;}
        sort(d+1,d+m+1),m=unique(d+1,d+m+1)-d-1;
        for(i=1;i<=m;++i)lk[i].clear();
        for(i=n-1;i;--i)
            for(j=i+1;j<=n;++j)
                if(a[p[i]]>a[p[j]]){
                    d[0].init(b[p[j]]-b[p[i]],a[p[i]]-a[p[j]]);
                    k=lower_bound(d+1,d+m+1,d[0])-d;
                    lk[k].push_back(p[i]);
                    if(k<m)lk[k+1].push_back(p[i]);
                }
        for(i=1;i<=n;++i)q[p[i]]=i;
        for(i=1;i<=m;++i){
            ll _x=d[i].x,_y=d[i].y;
            for(int &p:lk[i])p=q[p];
            sort(lk[i].begin(),lk[i].end(),greater<int>());
            for(int j:lk[i])
                for(k=j;k<n;++k){
                    ll ld=_x*a[p[k]]+_y*b[p[k]],rd=_x*a[p[k+1]]+_y*b[p[k+1]];
                    if(ld<rd)break;
                    if(ld==rd&&c[p[k]]<=c[p[k+1]])break;
                    swap(p[k],p[k+1]);
                    q[p[k]]=k,q[p[k+1]]=k+1;
                }
            if(ck()){puts("YES");goto _loc_end;}
        }
        puts("NO");_loc_end:;
    }
    return 0;   
}