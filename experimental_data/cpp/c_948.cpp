#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
inline char tc(void){
	static char fl[10000],*A=fl,*B=fl;
	return A==B&&(B=(A=fl)+fread(fl,1,10000,stdin),A==B)?EOF:*A++;
}
inline int read(void){
	int a=0;char c;
	while((c=tc())<'0'||c>'9');
	while(c>='0'&&c<='9')a=a*10+c-'0',c=tc();
	return a;
}
int n,s[100006];
ll sum,ans;
priority_queue<ll,vector<ll>,greater<ll> >a;
int main(void){
	register int i,x;
	n=read();
	for(i=1;i<=n;++i)s[i]=read();
	for(i=1;i<=n;++i){
		x=read(),a.push(s[i]+sum),ans=0,sum+=x;
		while(!a.empty()&&a.top()<=sum)ans+=a.top()+x-sum,a.pop();
		ans+=1ll*a.size()*x;
		printf("%I64d ",ans);
	}
	return 0;
}