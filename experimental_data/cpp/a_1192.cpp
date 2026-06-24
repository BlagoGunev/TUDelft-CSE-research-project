// LUOGU_RID: 154129247
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define Cl(x) memset(x,0,sizeof(x))
const bool DC=0;
const ll mod=0;
const int N=0;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll qpow(ll a,ll b,ll p=mod){ll ans=1;for(;b;b>>=1,a=a*a%p)if(b&1)ans=ans*a%p;return ans;}
void NO(){cout<<"NO\n";}
void YES(){cout<<"YES\n";}
mt19937 rnd((unsigned long long)new char);
int rnad(){return abs((int)rnd());}
int rd(int l,int r){return rnad()%(r-l+1)+l;}

pii p[150005],d[]={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1}};
pii operator+(const pii&a,const pii&b){return {a.fi+b.fi,a.se+b.se};}
int n,cnt;
map<pii,int>mp,qwq;
set<int>ps;
void dfs1(pii now){if(mp.count(now)&&qwq[now]){qwq[now]=0;for(int i=0;i<8;i++)dfs1(now+d[i]);}}
void dfs2(pii now){
	if(cnt==1&&mp.count(now))ps.insert(mp[now]);
	if(qwq.count(now)&&qwq[now]&&qwq[now]^cnt){qwq[now]=cnt;for(int i=0;i<4;i++)dfs2(now+d[i]);}
}
bool chk(pii now){
	vector<int>lst;
	for(int i=0;i<4;i++)if(!qwq[now+d[i]]||!qwq[now+d[i+4]]){
		for(int j=0,c=1,t;(++i)%=4,j<4;j++,c|=!t||!qwq[now+d[i+4]])if((t=qwq[now+d[i]])&&c){
			if(count(all(lst),t))return 0;
			lst.push_back(t),c=0;
		}
		break;
	}
	mp.erase(now),qwq[now]=-1,dfs2(now);
	for(int i=4;i<8;i++)if(!qwq[now+d[i]])for(int j=0;j<4;j++)if(qwq[now+d[i]+d[j]]==1){ps.insert(mp[now+d[i]]);break;}
	return 1;
}
void __INIT__(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
void __SOLVE__(int _case){
	cin>>n>>cnt,cnt=0;
	for(int i=0;i<n;i++){
		cin>>p[i].fi>>p[i].se;
		mp[p[i]]=i,qwq[p[i]]=-1;
		for(int j=0;j<8;j++)qwq[p[i]+d[j]]=-1;
	}
	dfs1(p[0]);
	for(int i=0;i<n;i++)if(qwq[p[i]])return NO();
	for(auto i:qwq)if(i.se<0)++cnt,dfs2(i.fi);
	cnt=1;
	vector<int>ans;
	for(int x;ps.size();ps.erase(x))if(chk(p[x=*ps.rbegin()]))ans.push_back(x);
	YES();
	for(int i=n-1;~i;i--)cout<<ans[i]+1<<"\n";
}
int main(){/*freopen(".in","r",stdin);freopen(".out","w",stdout);*/__INIT__();int T;DC?cin>>T,1:T=1;for(int _CASE=1;_CASE<=T;_CASE++)__SOLVE__(_CASE);return 0;}