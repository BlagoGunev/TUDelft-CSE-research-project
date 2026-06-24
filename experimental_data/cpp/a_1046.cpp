#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<ctime>
#define ll long long
#define N 200005

using namespace std;
inline int Get() {int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}while('0'<=ch&&ch<='9') {x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}return x*f;}

int n,k,cc;
struct robot {
	ll x,R,q;
	ll l,r;
	bool operator <(const robot &a)const {return R<a.R;}
}s[N];
ll ans;
ll d[N<<2];
int tem[N<<2];
int low(int i) {return i&(-i);}
void add(int v,int f) {for(int i=v;i<=cc;i+=low(i)) tem[i]+=f;}
void Clear(int v) {for(int i=v;i<=cc;i+=low(i)) tem[i]=0;}
int query(int v) {
	int ans=0;
	for(int i=v;i;i-=low(i))
		ans+=tem[i];
	return ans;
}
bool cmp(const robot &a,const robot &b) {return a.q<b.q;}
deque<int>st;
void CDQ(int l,int r) {
	if(l==r) return ;
	int mid=l+r>>1;
	CDQ(l,mid),CDQ(mid+1,r);
	int st=mid+1,ed=mid;
	for(int i=l;i<=mid;i++) {
		while(ed<r&&s[ed+1].q<=s[i].q+k) {
			ed++;
			add(s[ed].x,1);
		}
		while(st<=ed&&s[st].q<s[i].q-k) {
			add(s[st].x,-1);
			st++;
		}
		ans+=query(s[i].r)-query(s[i].l-1);
	}
	for(int i=mid+1;i<=r;i++) Clear(s[i].x);
	inplace_merge(s+l,s+mid+1,s+r+1,cmp);
}

int main() {
	n=Get(),k=Get();
	for(int i=1;i<=n;i++) {
		s[i].x=Get(),s[i].R=Get(),s[i].q=Get();
		d[++d[0]]=s[i].x;
		d[++d[0]]=s[i].x-s[i].R;
		d[++d[0]]=s[i].x+s[i].R;
	}
	sort(d+1,d+1+d[0]);
	cc=unique(d+1,d+1+d[0])-d;
	for(int i=1;i<=n;i++) {
		s[i].l=lower_bound(d+1,d+cc,s[i].x-s[i].R)-d;
		s[i].r=lower_bound(d+1,d+cc,s[i].x+s[i].R)-d;
		s[i].x=lower_bound(d+1,d+cc,s[i].x)-d;
	}
	sort(s+1,s+1+n);
	CDQ(1,n);
	cout<<ans;
	return 0;
}