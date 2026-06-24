#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
LL n,L,R;
LL count(LL x){
	if(x==0||x==1) return 1;
	return count(x/2)*2+1;
}
LL get(LL m){
	LL res=0,now=n;
	while(now>1&&m){
		LL t=count(now/2);
		if(t+1<=m) res+=now/2+(now&1), m-=t+1; else
		now/=2;
	}
	if(m) res+=now;
	return res;
}
int main(){
	//freopen("B.in","r",stdin);
	//freopen("B.out","w",stdout);
	scanf("%lld%lld%lld",&n,&L,&R);
	printf("%lld\n",get(R)-get(L-1));
	return 0;
}