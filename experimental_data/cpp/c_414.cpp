// Author: bill125
// ntr jcpwfloi
// orz LXLWDGY WJMZBMR dilutedream sevenkplus 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <bitset>

using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> Pair;
#define rep(i,n) for (int i=0; i<n; ++i)
#define repD(i,n) for (int i=n-1; i>=0; --i)
#define For(i,a,b) for (int i=a; i<=b; ++i)
#define ForD(i,a,b) for (int i=a; i>=b; --i)
#define ForE(i,a) for (Edge* i=h[a]; i; i=i->next)
#define forv(i,a) for (unsigned int i=0, ___t=a.size(); i<___t; ++i)
#define ForV(i,a) for (__typeof(a.begin()) i = a.begin();i != a.end();++i)
#define fill(a,b) memset(a,b,sizeof(a))
#define lowbit(a) ((a) & (-(a)))
#define sqr(a) ((a)*(a))
#define pb push_back
#define mp make_pair
#define gi gI()
#define cut puts("===================")

void setIO(string NAME) {
	#ifndef ONLINE_JUDGE
	string in=NAME+".in", out=NAME+".out";freopen(in.c_str(),"r",stdin),freopen(out.c_str(),"w",stdout);
	#endif
}
inline ll gI() {char c=getchar();while ((c<'0' || c>'9')&&c!='-') c=getchar();ll flag=1,p=0;if (c=='-') flag=-1,c=getchar();while (c>='0' && c<='9') p=p*10+(c-'0'),c=getchar();return p*flag;}
int gs(char *C) {char c=getchar();while (c==' ' || c=='\n') c=getchar();int l=0;while (c!=' ' && c!='\n') C[l++]=c,c=getchar();C[l]=0;return l;}
template <class T> void debug (const T a,const int & n) {rep(i,n) printf("%d%c", a[i],(i==n-1)?'\n':' ');}

const int inf=~0U>>1, maxn=2000000+10;
int n;
int a[maxn], _a[maxn], b[maxn];
ll cnt1[maxn<<1], cnt2[maxn<<1], sum1[25], sum2[25];

void work1(int x,int l,int r,int dep) {
	if (l==r) return ;
	int m=(l+r)>>1;
	work1(x<<1, l, m, dep+1);
	work1((x<<1)+1, m+1, r, dep+1);
	int i=l, j=m+1;
	int t=l;
	while (i<=m || j<=r) {
		if (i<=m && (j==r+1 || a[i]<=a[j])) b[t++]=a[i++];
		else b[t++]=a[j++], cnt1[x]+=m-i+1;
	}
	For(i,l,r) a[i]=b[i];
	sum1[dep]+=cnt1[x];
}

void work2(int x,int l,int r, int dep) {
	if (l==r) return ;
	int m=(l+r)>>1;
	work2(x<<1, l, m, dep+1);
	work2((x<<1)+1, m+1, r, dep+1);
	int i=l, j=m+1;
	int t=l;
	while (i<=m || j<=r) {
		if (i<=m && (j==r+1 || a[i]>=a[j])) b[t++]=a[i++];
		else b[t++]=a[j++], cnt2[x]+=m-i+1;
	}
	For(i,l,r) a[i]=b[i];
	sum2[dep]+=cnt2[x];
}

int main() {
	setIO("test");
	
	n=gi;
	For(i,1,(1<<n)) a[i]=gi, _a[i]=a[i];;
	work1(1, 1, (1<<n), 1);
	For(i,1,(1<<n)) a[i]=_a[i];
	work2(1, 1, (1<<n), 1);
	
//	For(i,1,n) printf("%lld %lld\n", sum1[i], sum2[i]);
	
	int m=gi;
	rep(i,m) {
		int q=gi;
		ll ans=0;
		ForD(i,n,n-q+1) swap(sum1[i], sum2[i]);
		For(i,1,n) ans+=sum1[i];
		printf("%I64d\n", ans);
	}
	
	return 0;
}