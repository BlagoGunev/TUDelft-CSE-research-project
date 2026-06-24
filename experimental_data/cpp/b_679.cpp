#include<cstdio>

#define min(a,b) ((a)<(b)?(a):(b))

#define c(x) (1LL*(x)*(x)*(x))

#define f(x) (c((x)+1)-c((x)))

#define ll long long 

int ans,a[105]; ll res,n,s[105];

int main(){

	scanf("%lld",&n); ll tmp=n,now=0; int ans=0;

	for (int i=1;i<=100000;i++)

		while (c(i)<=tmp&&now+c(i)<c(i+1))

			tmp-=c(i),now+=c(i),a[++ans]=i,s[ans]=s[ans-1]+c(i);

	printf("%d ",ans); a[ans+1]=200000; n++;

	for (int i=ans;i>=1;i--){

		while (now+f(a[i])<n)now+=f(a[i]),++a[i];

		n-=c(a[i]); res+=c(a[i]); now-=c(a[i]); if (n>f(a[i]))n=f(a[i]);

	} printf("%lld\n",res);

}