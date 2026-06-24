#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> pr;
inline int rd(){
	int x=0,y=1;char c=getchar();
	for(;c<'0'||c>'9';c=getchar())if(c=='-')y=-1;
	for(;c>='0'&&c<='9';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return x*y;
}
const int N=200005;
int n,m,ans=1e9,low[N],dfn[N],dfc,st[N],tp,ins[N],be[N],tot,v1[N],v2[N],vi[N],s1,s2;
vector<int>e[N],f[N],vc[N],ve[N],an,id;
void dfs(int x){
    low[x]=dfn[x]=++dfc;st[++tp]=x;ins[x]=1;
    for(auto y:vc[x])if(!dfn[y])dfs(y),low[x]=min(low[x],low[y]);
    else if(ins[y])low[x]=min(low[x],dfn[y]);
    if(low[x]==dfn[x])
    {++tot;int o;do{o=st[tp--];ve[tot].push_back(o);be[o]=tot;ins[o]=0;}while(o!=x);}
}
void d1(int x){if(v1[x])return;v1[x]=1;for(auto y:e[x])d1(y);}
void d2(int x){if(v2[x])return;v2[x]=1;for(auto y:f[x])d2(y);}
void df1(int x,int ti){if(vi[x]==ti)return;vi[x]=ti;s1+=ve[x].size();for(auto y:e[x])df1(y,ti);}
void df2(int x,int ti){if(vi[x]==ti)return;vi[x]=ti;s2+=ve[x].size();for(auto y:f[x])df2(y,ti);}
int main(){
	n=rd();m=rd();
    for(int x,y;m--;)x=rd(),y=rd(),vc[x].push_back(y);
    for(int i=1;i<=n;++i)if(!dfn[i])dfs(i);
    for(int i=1;i<=n;++i)for(auto j:vc[i])if(be[i]!=be[j])
    e[be[i]].push_back(be[j]),f[be[j]].push_back(be[i]);
    for(int i=1;i<=tot;++i)id.push_back(i);random_shuffle(id.begin(),id.end());
    for(auto x:id)if(!v1[x]&&!v2[x]){
        s1=0;s2=0;for(auto y:e[x])df1(y,x);for(auto y:f[x])df2(y,x);
        if(abs(s1-s2)<ans)ans=abs(s1-s2),an.clear();
        if(abs(s1-s2)==ans)for(auto y:ve[x])an.push_back(y);
        if(s1<=s2)d1(x);if(s2<=s1)d2(x);
    }
    sort(an.begin(),an.end());for(auto i:an)printf("%d ",i);
	return 0;
}