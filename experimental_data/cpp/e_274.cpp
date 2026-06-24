#include<bits/stdc++.h>
#define int long long
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
using namespace std;
template<typename T>istream&operator>>(istream&I,vector<T>&v){for(auto&i:v)I>>i;return I;}
template<typename T>ostream&operator<<(ostream&O,vector<T>&v){for(auto&i:v)O<<i<<' ';return O;}
namespace AC{
using ll=long long;
const int N=2e5+5;
const int dx[]={-1,-1,1,1};
const int dy[]={1,-1,-1,1};
const string dirs[]={"NE","NW","SW","SE"};
ll n,m,k,ans,xs,ys,d,dv=1;
string dir;
map<ll,ll>mp[N];
set<pair<ll,ll>>s[2][N];
void add(int x,int y){
	mp[x][y]=1;
	s[0][x+y].insert({x,y});
	s[1][x-y+m+1].insert({x,y});
}
void gt(int ty){
	auto it=s[d&1][(d&1)?xs-ys+m+1:xs+ys].lower_bound({xs,ys});
	if(d<2)it--;
	ans+=ty*abs(xs-(*it).first);
	xs=(*it).first-dx[d],ys=(*it).second-dy[d];
	ll cnt=mp[xs+dx[d]].count(ys)+mp[xs].count(ys+dy[d]);
	if(cnt==0||cnt==2)(d+=2)%=4,dv=2;
	else if(mp[xs+dx[d]].count(ys))ys+=dy[d],d^=3;
	else xs+=dx[d],d^=1;
}
void solve(){
	cin>>n>>m>>k;
	for(int i=0;i<=n+1;i++)add(i,0),add(i,m+1);
	for(int i=0;i<=m+1;i++)add(0,i),add(n+1,i);
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
	}
	cin>>xs>>ys>>dir;
	for(int i=0;i<4;i++)if(dir==dirs[i])d=i;
	gt(0);
	int sx=xs,sy=ys,sd=d;
	gt(1);
	while(!(sy==ys&&sx==xs&&sd==d))gt(1);
	cout<<ans/dv;
}
}
signed main(){
	int t=1;
	//cin>>t;
	while(t--)AC::solve();
}