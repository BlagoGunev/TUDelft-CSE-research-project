// Problem: F. Nobody is needed
// Contest: Codeforces - Codeforces Round 936 (Div. 2)
// URL: https://codeforces.com/contest/1946/problem/F
// Memory Limit: 512 MB
// Time Limit: 6000 ms
// Author: nullptr_qwq
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
#define inf 1e9
#define pii pair<int,int>
#define F(i,a,b) for(int i=a;i<=(b);i++)
#define dF(i,a,b) for(int i=a;i>=(b);i--)
#define wh(lzm) while(lzm--)
#define cmh(sjy) while(sjy--)
#define lowbit(x) (x&(-x))
#define HH printf("\n")
#define eb emplace_back
using namespace std;
namespace Fastio{struct Reader{template<typename T>Reader&operator>>(T&x){x=0;short f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();x*=f;return*this;}Reader&operator>>(double&x){x=0;double t=0;short f=1,s=0;char c=getchar();while((c<'0'||c>'9')&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else{x*=f;return*this;}while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(long double&x){x=0;long double t=0;short f=1,s=0;char c=getchar();while((c<'0'||c>'9')&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else{x*=f;return*this;}while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(__float128&x){x=0;__float128 t=0;short f=1,s=0;char c=getchar();while((c<'0'||c>'9')&&c!='.'){if(c=='-')f*=-1;c=getchar();}while(c>='0'&&c<='9'&&c!='.')x=x*10+(c^48),c=getchar();if(c=='.')c=getchar();else{x*=f;return*this;}while(c>='0'&&c<='9')t=t*10+(c^48),s++,c=getchar();while(s--)t/=10.0;x=(x+t)*f;return*this;}Reader&operator>>(char&c){c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();return*this;}Reader&operator>>(char*str){int len=0;char c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();while(c!=' '&&c!='\n'&&c!='\r')str[len++]=c,c=getchar();str[len]='\0';return*this;}Reader&operator>>(string&str){str.clear();char c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();while(c!=' '&&c!='\n'&&c!='\r')str.push_back(c),c=getchar();return*this;}Reader(){}}cin;const char endl='\n';struct Writer{const int Setprecision=6;typedef int mxdouble;template<typename T>Writer&operator<<(T x){if(x==0){putchar('0');return*this;}if(x<0)putchar('-'),x=-x;static short sta[40];short top=0;while(x>0)sta[++top]=x%10,x/=10;while(top>0)putchar(sta[top]+'0'),top--;return*this;}Writer&operator<<(double x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(double)_;static short sta[40];short top=0;while(_>0)sta[++top]=_%10,_/=10;if(top==0)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_>0)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;return*this;}Writer&operator<<(long double x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(long double)_;static short sta[40];short top=0;while(_>0)sta[++top]=_%10,_/=10;if(top==0)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_>0)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;return*this;}Writer&operator<<(__float128 x){if(x<0)putchar('-'),x=-x;mxdouble _=x;x-=(__float128)_;static short sta[40];short top=0;while(_>0)sta[++top]=_%10,_/=10;if(top==0)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;putchar('.');for(int i=0;i<Setprecision;i++)x*=10;_=x;while(_>0)sta[++top]=_%10,_/=10;for(int i=0;i<Setprecision-top;i++)putchar('0');while(top>0)putchar(sta[top]+'0'),top--;return*this;}Writer&operator<<(char c){putchar(c);return*this;}Writer&operator<<(char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(const char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(string str){int st=0,ed=str.size();while(st<ed)putchar(str[st++]);return*this;}Writer(){}}cout;}using namespace Fastio;
#define fin Fastio::cin
#define fout Fastio::cout
#define fndl Fastio::endl
const int mod=998244353,maxn=1000005;
int a[maxn],n,cmh,pos[maxn];
vector<int>vec[maxn],g[maxn],moss[maxn];
ll ans[maxn],t[maxn];
void add(int x,int y){ if(!x)return; for(;x<=n;x+=lowbit(x)) t[x]+=y; }
ll query(int x){ ll rt=0; for(;x;x^=lowbit(x)) rt+=t[x]; return rt; }
vector<pii>qu[maxn];
int cnt[maxn],deg[maxn];
		vector<int>topo,tmp;
		queue<int>q;
void solve(){
	fin>>n>>cmh;
	F(i,0,n+1) t[i]=0,qu[i].clear();
	F(i,1,n) fin>>a[i];
	F(i,1,n) pos[a[i]]=i;
	F(i,1,cmh){
		int l,r; fin>>l>>r;
		qu[r].push_back({l,i});
	}
	F(i,1,n){
		tmp.clear(),topo.clear();
		for(int j:moss[a[i]]) if(pos[j]<=i) tmp.push_back(pos[j]);
		sort(tmp.begin(),tmp.end());
		for(int i:tmp) for(int j:tmp) 
			if(i<j&&a[j]%a[i]==0) g[j].push_back(i),deg[i]++;
		for(int i:tmp) if(!deg[i]) q.push(i);
		while(!q.empty()){
			int u=q.front(); q.pop();
			topo.push_back(u);
			for(int v:g[u]) if(!--deg[v])q.push(v);
		}
		cnt[i]=1;
		for(int u:topo) for(int v:g[u]) cnt[v]+=cnt[u];
		for(int u:tmp) add(u,cnt[u]);
		for(int u:tmp) g[u].clear(),cnt[u]=deg[u]=0;
		for(auto [pos,id]:qu[i]) ans[id]=query(i)-query(pos-1);
	}
	F(i,1,cmh) fout<<ans[i]<<' ';
	fout<<fndl;
}
signed main(){
	F(i,1,maxn-5) for(int j=i;j<=maxn-5;j+=i) moss[j].push_back(i);
	int lzm; fin>>lzm;
	wh(lzm) solve();
}