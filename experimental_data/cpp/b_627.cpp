#include<cstdio>

using namespace std;

const int N=200200;

int i,j,k,n,m,a,b,q,ch,o,x,y,ans,t;

int Ta[N],Tb[N],p[N];

void R(int &x)

{

	x=0;ch=getchar();

	while (ch<'0' || '9'<ch) ch=getchar();

	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();

}

int min(int x,int y)

{

	if (x<y) return x;

	return y;

}

int Lb(int x) {return x&-x;}

void T_add(int *T,int x,int y)

{

	if (!y) return;

	for (;x<=n;x+=Lb(x)) T[x]+=y;

}

int T_query(int *T,int x)

{

	int y=0;

	for (;x;x-=Lb(x)) y+=T[x];

	return y;

}

int main()

{

	R(n);R(k);R(a);R(b);R(q);

	for (i=1;i<=q;i++)

	{

		R(o);

		if (o==1)

		{

			R(x);R(y);

			t=p[x];

			p[x]+=y;

			if (t<b) T_add(Tb,x,min(p[x],b)-t);

			if (t<a) T_add(Ta,n-x+1,min(p[x],a)-t);

		}

		else

		{

			R(x);

			ans=T_query(Tb,x-1);

			if (x+k<=n) ans+=T_query(Ta,n-x-k+1);

			printf("%d\n",ans);

		}

	}

}