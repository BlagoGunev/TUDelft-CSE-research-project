bool M1;
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<iomanip>
#include<cassert>
#include<random>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<queue>
#include<deque>
#include<cmath>
#include<ctime>
#include<array>
#include<map>
#include<set>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/hash_policy.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
#define fi first
#define se second
#define ll long long
#define Vector Point
#define I128 __int128
#define LD long double
#define ull unsigned ll
#define pii pair<int,int>
#define pb(x) push_back(x)
#define syt cerr<<"sytakioi\n"
#define F(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
#define look_memory cerr<<abs(&M2-&M1)/1024.0/1024<<'\n'
#define rd_i(l,r) uniform_int_distribution<int>(l,r)(rd)
#define rd_r(l,r) uniform_real_distribution<double>(l,r)(rd)
#define look_time cerr<<(clock()-Time)*1.0/CLOCKS_PER_SEC<<'\n'
using namespace std;
//using namespace __gnu_cxx;
mt19937 rd(time(0));
const int N=4e5+5;
int T,n,ans;
char c[N];
int a[N],s[N],t;
int lg[N],st[20][N],ls[20][N],rs[20][N];
map<pii,int> mp;
inline int Min(int x,int y){return a[x]>a[y]?x:y;}
inline int calc(int l,int r){
	int k=lg[r-l+1];
	return Min(st[k][l],st[k][r-(1<<k)+1]);
}
inline int get_dis(int x,int y){
	if(mp.count({x,y})) return mp[{x,y}];
	int res=0;
	if(a[x]<a[y]){
		if(ls[0][x]) res=get_dis(ls[0][x],y)+1;
	}else{
		if(rs[0][y]) res=get_dis(x,rs[0][y])+1;
	}
	return mp[{x,y}]=res;
}
inline int solve(int l,int r){
	if(l>r) return 0;
	if(l==r) return 1;
	int p=calc(l,r),x=solve(l,p-1),y=solve(p+1,r);
	ans=max(ans,x+y+1);
	if(l!=1||r!=n) ans=max(ans,x+y+2);
	if(l!=1&&r!=n) ans=max(ans,x+y+3+get_dis(l-1,r+1));
	return max(x,y)+1;
}
inline void mian(){
	cin>>n;
	F(i,1,n) cin>>a[i];
	F(i,1,n) cin>>c[i];
	t=0;
	F(i,1,n){
		while(t&&a[s[t]]<a[i]) --t;
		ls[0][i]=s[t];
		s[++t]=i;
	}
	t=0;
	UF(i,n,1){
		while(t&&a[s[t]]<a[i]) --t;
		rs[0][i]=s[t];
		s[++t]=i;
	}
	lg[0]=-1;F(i,1,n) lg[i]=lg[i>>1]+1,st[0][i]=i;
	F(j,1,19) F(i,1,n-(1<<j)+1) st[j][i]=Min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
	F(j,1,19) F(i,1,n) ls[j][i]=ls[j-1][ls[j-1][i]],rs[j][i]=rs[j-1][rs[j-1][i]];
	ans=max(ans,solve(1,n));
	cout<<ans-1<<'\n';
	ans=0;
	mp.clear();
}
bool M2;
int main(){
	int Time=clock();
	look_memory;
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>T;
	while(T--) mian();
	look_time;
	return 0;
}