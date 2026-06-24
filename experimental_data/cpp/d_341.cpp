#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N=1000;

struct BIT
{
	ll data[1+N][1+N];
	ll   get(int,int);
	void set(int,int,ll);
} B[2][2];

ll BIT::get(int i,int j)
{
	ll x=0;
	for(int a=min(i,N);a>0;a-=a&-a)
		for(int b=min(j,N);b>0;b-=b&-b)
			x^=data[a][b];
	return x;
}

void BIT::set(int i,int j,ll x)
{
	for(int a=max(i,1);a<=N;a+=a&-a)
		for(int b=max(j,1);b<=N;b+=b&-b)
			data[a][b]^=x;
}

ll get(int i,int j)
{
	return B[i&1][j&1].get(i,j);
}

void set(int i,int j,ll x)
{
	B[i&1][j&1].set(i,j,x);
}

int main()
{
	int Q;
	scanf("%*d%d",&Q);
	while(--Q>=0)
	{
		int c,x1,y1,x2,y2; ll v;
		scanf("%d%d%d%d%d",&c,&x1,&y1,&x2,&y2);
		if(c==1)
		{
			v=0;
			v^=get(x2  ,y2  );
			v^=get(x2  ,y1-1);
			v^=get(x1-1,y2  );
			v^=get(x1-1,y1-1);
			printf("%I64d\n",v);
		}
		else if(c==2)
		{
			scanf("%I64d",&v);
			set(x1  ,y1  ,v);
			set(x1  ,y2+1,v);
			set(x2+1,y1  ,v);
			set(x2+1,y2+1,v);
		}
	}
	return 0;
}