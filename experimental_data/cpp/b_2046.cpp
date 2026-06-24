#include<bits/stdc++.h>
using namespace std;
#define rep(i,l,r) for(int i=l,_=r;i<=_;++i)
#define per(i,r,l) for(int i=r,_=l;i>=_;--i)
#define iter(x,v) for(int _p=head[x],v;v=ver[_p],_p;_p=nxt[_p])
#define ll long long
#define lowbit(x) ((x)&-(x))
template<typename T>
inline void chkmin(T &x,T y) {x=x<y?x:y;}
template<typename T>
inline void chkmax(T &x,T y) {x=x>y?x:y;}
int t,n,a[200010],ans0[200010],ans[200010];
multiset<int> se;
int main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--) {
		cin>>n;int len0=0,len=0;se.clear();
		rep(i,1,n) cin>>a[i],se.insert(a[i]);
		rep(i,1,n) {
			auto now=se.begin();
			if(now!=se.end()&&(*now)==a[i]) ans0[++len0]=a[i],se.erase(se.find(a[i]));
			else ans[++len]=a[i]+1,se.erase(se.find(a[i])),se.insert(a[i]+1);
		}
		sort(ans+1,ans+1+len);
		rep(i,1,len0) cout<<ans0[i]<<' ';
		rep(i,1,len) cout<<ans[i]<<' ';cout<<'\n';
	}
	cout<<flush;
    return 0;
}