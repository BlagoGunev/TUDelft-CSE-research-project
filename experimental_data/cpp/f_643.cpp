#include<cstdio>

using namespace std;

typedef unsigned int ui;

const ui N=150;

ui i,j,k,n,p,q,ans,t,ii;

ui tmp[N],C[N];

ui gcd(ui a,ui b)

{

	if (!b) return a;

	return gcd(b,a%b);

}

void pre()

{

	ui i,j,k,g,num=0;

	C[0]=1;

	for (i=1;i<=p;i++)

	{

		tmp[++num]=n-i+1;

		k=i;

		for (j=1;j<=num && k>1;j++)

		{

			g=gcd(tmp[j],k);

			k/=g;tmp[j]/=g;

		}

		C[i]=1;

		for (j=1;j<=num;j++) C[i]*=tmp[j];

	}

}

int main()

{

	scanf("%u%u%u",&n,&p,&q);

	if (n-1<p) p=n-1;

	pre();

	for (i=1;i<=q;i++)

	{

		t=0;

		for (ii=1,j=0;j<=p;j++,ii*=i) t+=C[j]*ii;

		ans^=t*i;

	}

	printf("%u\n",ans);

}