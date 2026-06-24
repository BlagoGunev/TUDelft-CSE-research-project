#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gc getchar()
inline int read(){
	int x=0;int f=0;char c=gc;
	for(;c<48||c>57;c=gc)
		if(c=='-')f=1;
	for(;c>47&&c<58;c=gc)
		x=x*10+c-48;
	return f?-x:x;
}
#define io read()

#define maxn 100005
int n,a[maxn],b[maxn],fl;

inline void init(){
	n=io;
	for(int i=0;i<n;++i)a[i]=io;
	for(int i=0;i<n;++i)b[i]=io;
	fl=a[0]==b[0]&&a[n-1]==b[n-1];
	
	for(int i=n-1;i;--i){
		a[i]-=a[i-1];
		b[i]-=b[i-1];
	}
	sort(a+1,a+n);
	sort(b+1,b+n);
}

inline void solve(){
	for(int i=1;i<n;++i)
		if(a[i]!=b[i])fl=0;
	puts(fl?"Yes":"No");
}

#define fo(f) freopen(f".in","r",stdin);freopen(f".out","w",stdout);
int main(){
	init();
	solve();
	return 0;
}