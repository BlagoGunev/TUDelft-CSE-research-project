#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,avx2") 
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define ll long long
#define int long long
#define ull unsigned long long
#define SZ(x) ((int)((x).size()))
#define ALL(x) (x).begin(),(x).end()
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 1000005
#define inf 0x3f3f3f3f

int n,k,sum,lg;
pii a[maxn];
int sa[maxn];
map<int,int>mp;

pii res,resp;
bool cmp(pii a,pii b){
	return (long double)a.fi/a.se <= (long double)b.fi/b.se;
}
int G(int x){
	int res=0,p=n+1;
	For(i,1,n) {
		res+=(a[i].fi+x-1)/x*a[i].se;
		if(i*x > a[i].fi*lg){
			p=i+1;
			break;
		}
	}
	// i + (a[i+1].fi)/x * log
	while(p<=n){
		int t=(a[p].fi+x-1)/x;
		int l=p+1,r=n,pos=p;
		while(l<=r){
			int mid=l+r>>1;
			if((a[mid].fi+x-1)/x == t) pos=mid,l=mid+1;
			else r=mid-1;
		}
		res+=(sa[pos]-sa[p-1])*t;
		p=pos+1;
	}
	return res;
}
void add(int x,int y){
	if(cmp(res,mkp(sum,x*y))) return;
	pii ans=mkp(G(x),y);
	if(cmp(ans,res)) res=ans,resp=mkp(x,y);
}

signed main()
{
	n=read(),k=read();
	For(i,1,n)mp[read()]++;
	lg=1;
	while((1<<lg)<n)++lg;
	
	n=0;
	for(auto [x,y]:mp) a[++n]=mkp(x,y),sum+=x*y;
	
	reverse(a+1,a+n+1);
	For(i,1,n) sa[i]=sa[i-1]+a[i].se;
	
	res.fi=4e18,res.se=1;
	for(int i=k/2;i;--i){
		add(i,k-i);
		if(i!=k-i) add(k-i,i);
	}
	cout<<resp.fi<<" "<<resp.se;
	return 0;
}
/*

*/