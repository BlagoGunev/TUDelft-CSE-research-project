#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define oo 3005

double	r[oo],R[oo],h[oo],H[oo],q[oo];
int	n,i,j,k,Tmp,Min;
double	Height,ans=0,xx;


double	Work(int i,int j)
{
	if (r[j]>=R[i]) return h[i];
	if (r[i]>r[j])
	{
		if (h[i]<=h[j] && R[i]>=r[j]+(R[j]-r[j])/h[j]*h[i]) return 0;
		if (h[i]>=h[j] && R[j]<=r[i]+(R[i]-r[i])/h[i]*h[j]) return 0;
	}
	if (q[i]<q[j])
	{
		if (R[i]>=R[j] && r[i]<=R[j]) return (R[j]-r[i])/(R[i]-r[i])*h[i]-h[j]; else
		return h[i]-(R[i]-r[j])/(R[j]-r[j])*h[j];
	} else
	return (r[j]-r[i])/(R[i]-r[i])*h[i];
}

int	main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	scanf("%d",&n);
	for (i=1;i<=n;++i)
	{
		scanf("%lf%lf%lf",&h[i],&r[i],&R[i]);
		q[i]=(R[i]-r[i])/h[i];
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<i;++j){
			xx=Work(j,i);
			H[i]=MAX(H[i],H[j]+xx);
		}
		ans=MAX(ans,H[i]+h[i]);
	}
	printf("%.8lf\n",ans);

//	printf("%d\n",(int)(ans+0.5+1e-5));
	
	return 0;
}