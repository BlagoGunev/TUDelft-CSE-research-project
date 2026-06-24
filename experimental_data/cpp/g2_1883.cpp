// LUOGU_RID: 154472715
// Problem: D2. Dances (Hard Version)
// Contest: Codeforces - Codeforces Round 905 (Div. 2)
// URL: https://codeforces.com/contest/1888/problem/D2
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int64 long long
using namespace std;
int64 t,n,m,l,r,mid,sum1,sum2,p1,p2,a[100001],b[100001],c[100001];
inline void init(int64 x){
	p1=1LL;
	p2=0LL;
	c[1LL]=x;
	for(int64 i=2LL;i<=n;i++){
		c[i]=a[i];
	}
	sort(c+1,c+n+1);
}
int64 calc(int64 x){
	init(x);
	while(p1<=n-p2){
		while(c[p1]>=b[p1+p2]&&p1<=n-p2){
			p2++;
		}
		if(c[p1]>=b[p1+p2]){
			return n-p1+1LL;
		}else{
			p1++;
		}
	}
	return p2;
}
inline void work(){
	scanf("%lld%lld",&n,&m);
	l=1LL;
	r=m+1LL;
	for(int64 i=2LL;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int64 i=1LL;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	sort(b+1LL,b+n+1LL);
	sum1=calc(1LL);
	sum2=calc(m);
	if(sum1==sum2){
		printf("%lld\n",m*sum1);
		return;
	}
	while(l+1LL<r){
		mid=(l+r)/2LL;
		if(calc(mid)==sum1){
			l=mid;
		}else{
			r=mid;
		}
	}
	printf("%lld\n",l*sum1+(m-r+1LL)*sum2);
}
int main(){
	scanf("%lld",&t);
	for(;t--;){
		work();
	}
}