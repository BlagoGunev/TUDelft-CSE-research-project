// LUOGU_RID: 164383221
#include<bits/stdc++.h>
#define within :
#define LJY main
using namespace std;
typedef long long ll;
const int N=3e5+5;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
inline int read(){
  char ch=getchar();int x=0;
  while(ch<'0'||ch>'9') ch=getchar();
  while(ch>='0'&&ch<='9')
    x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
  return x;
}
int n,a[N],to[N],ord[N],col[N],tot;
int nxt[N],lst[N],dem[N];
vector<pair<int,int> >p[N],ans;
int Time(int u,int v){
  int p=-(dem[n-u+1]+dem[n-v+1])/2;
  while(p<0) p+=n;while(p>=n) p-=n;return p;
}
void add(int u,int v){p[Time(u,v)].emplace_back(u,v);}
void getcol(int u){
  vector<int>tmp;++tot;
  for(int i=u;!col[i];i=to[i])
    col[i]=tot,tmp.emplace_back(i);
  sort(tmp.begin(),tmp.end());
  for(int i=1;i<tmp.size();i++)
    nxt[tmp[i-1]]=tmp[i],lst[tmp[i]]=tmp[i-1];
  for(int i=1;i<tmp.size();i++) add(tmp[i-1],tmp[i]);
}
void solve(){
  if(n==1) return;
  if(n==2){if(a[1]>a[2]) ans.emplace_back(1,2);return;}
  for(int i=1;i<=n;i++) to[i]=a[n-i+1];
  for(int i=1;i<=n;i++) if(i&1) dem[i]=i;else dem[i]=1-i;
  for(int i=1;i<=n;i++) ord[i]=i;
  for(int i=1;i<=n;i++) if(!col[i]) getcol(i);
  for(int i=1;i<=n;i++){
    for(int j=p[i-1].size()-1;j>=0;j--){
      auto [x,y]=p[i-1][j];
      auto getid=[&](int p)->int {
        if((n-p+1)&1) p+=n-i+1;
        else p-=n-i+1;if(p<=0) p=1-p;
        if(p>n) p=n*2+1-p;return p;
      };if(col[x]==col[y]&&x!=to[x]){
        int u=getid(x),v=getid(y);
        ans.emplace_back(min(u,v),max(u,v));
        swap(to[x],to[y]);int du=x,dv=y;
        vector<int>L,R;
        while(1){
          L.emplace_back(du);du=to[du];
          if(du==x) break;
          R.emplace_back(dv);dv=to[dv];
          if(dv==y){swap(L,R);break;}
        }tot++;
        for(int v within L) col[v]=tot;
        sort(L.begin(),L.end());
        for(auto u within L){
          int a=lst[u],b=nxt[u];
          if(!a||!b) continue;
          nxt[a]=b;lst[b]=a;
          if(col[a]==col[b]) add(a,b);
        }lst[L[0]]=0;nxt[L.back()]=0;
        for(int i=1;i<L.size();i++)
          nxt[L[i-1]]=L[i],lst[L[i]]=L[i-1],add(L[i-1],L[i]);
      }
    }if(n&1){
      if(i&1) ans.emplace_back(1,n-1);
      else ans.emplace_back(2,n);
    }else{
      if(i&1) ans.emplace_back(1,n);
      else ans.emplace_back(2,n-1);
    }
  }
}
signed LJY(){
  n=read();for(int i=1;i<=n;i++) a[i]=read();
  solve();printf("%d\n",ans.size());
  for(auto [u,v] within ans) printf("%d %d\n",u,v);
  return 0;
}