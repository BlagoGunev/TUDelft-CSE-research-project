#include<stdio.h>
#include<algorithm>
using namespace std;
long long a[300010];
long long qpow(long long x,long long p){
	long long ans=(x*x)%p;
	return (ans*ans)%p;
}
int main(){
	int n;
	long long p,k;
	scanf("%d%I64d%I64d",&n,&p,&k);
	for(int i=0;i<n;i++){
		scanf("%I64d",&a[i]);
		a[i]=((qpow(a[i],p)-k*a[i])%p+p)%p;
	}
	sort(a,a+n);
	long long t=a[0],s=1,ans=0;
	for(int i=1;i<n;i++){
		if(a[i]==t)s++;
		else{
			t=a[i];
			ans+=s*(s-1)/2;
			s=1;
		}
	}
	ans+=s*(s-1)/2;
	printf("%I64d",ans);
}