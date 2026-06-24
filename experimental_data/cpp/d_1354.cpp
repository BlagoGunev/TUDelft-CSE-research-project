#include<bits/stdc++.h>
using namespace std;
#define fp(i,l,r) for(register int (i)=(l);(i)<=(r);++(i))
#define fd(i,l,r) for(register int (i)=(l);(i)>=(r);--(i))
#define fe(i,u) for(register int (i)=front[(u)];(i);(i)=e[(i)].next)
#define mem(a) memset((a),0,sizeof (a))
#define O(x) cerr<<#x<<':'<<x<<endl
//#define int long long
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void wr(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)wr(x/10);
	putchar('0'+x%10);
}
const int MAXN=1e6+10;
int c[MAXN],n,Q,mx;
inline void add(int i,int v){
	for(;i<=n;i+=i&-i)
	c[i]+=v;
}
inline int sum(int i){
	int ans=0;
	for(;i;i-=i&-i)ans+=c[i];
	return ans;
}
inline int getkth(int k){
	int ans=0;
	for(int i=mx;i;i>>=1){
		if(ans+i<=n&&k>c[ans+i])k-=c[ans+i],ans+=i;
	}
	return ans+1;
}
main(){
	n=read();Q=read();
	for(mx=1;mx<=n;mx<<=1);mx>>=1;
	fp(i,1,n)add(read(),1);
	while(Q--){
		int u=read();
		if(u>=1)add(u,1);
		else add(getkth(-u),-1);
	}
	printf("%d\n",sum(n)?getkth(1):0);
	return 0;
}