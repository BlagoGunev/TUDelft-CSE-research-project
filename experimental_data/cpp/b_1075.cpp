#include <cstdio>
#define Maxn 210000
#define LL long long
using namespace std;
LL N,M,x[Maxn],driver[Maxn],Left[Maxn],Right[Maxn],calltimes[Maxn];
LL read () {
    LL X=0,w=1;char ch=0;
    while(ch<'0'||ch>'9')		{ if(ch=='-')	w=-1;ch=getchar(); }
    while(ch>='0'&&ch<='9')		{ X=(X<<1)+(X<<3)+ch-'0';ch=getchar();}
    return X*w;
}
int main () {
	N=read();M=read();
	for(LL i=1;i<=N+M;i++)
		x[i]=read();
	for(LL i=1;i<=N+M;i++)
		driver[i]=read();
	Left[0]=0;Right[N+M+1]=N+M+1;
	for(LL i=1;i<=N+M;i++)
		if(driver[i])       Left[i]=i;
		else                Left[i]=Left[i-1];
	for(LL i=N+M;i>=1;i--)
		if(driver[i])       Right[i]=i;
		else                Right[i]=Right[i+1];
	x[0]=-1e12;x[N+M+1]=1e12;
	for(LL i=1;i<=N+M;i++)
		if(!driver[i]) {
			if(x[i]-x[Left[i]]<=x[Right[i]]-x[i])       calltimes[Left[i]]++;
			else                                        calltimes[Right[i]]++;
		}
	for(LL i=1;i<=N+M;i++)
		if(driver[i])
			printf("%I64d ",calltimes[i]);
	return 0;
}