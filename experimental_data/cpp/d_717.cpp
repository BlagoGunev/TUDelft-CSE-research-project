#include <bits/stdc++.h>

using namespace std;

#define pb(a) push_back(a)

#define mp(a,b) make_pair(a,b)

//#define f first

//#define s second

#define ll long long

#define mod 1000000007

#define N 209

typedef map<int,int> Mapp;

int n,m,a,b,c,d,k,h,w,x,y,q,t,res,ma,mi,T,act=0,pas=1;

double p[N],ans;

vector<int> v;

inline void copy(double to[],double from[])

{

	for(int i=0;i<=x;i++)to[i]=from[i];

}

inline void zero(double b[])

{

	for(int i=0;i<=x;i++)b[i]=0.0;

}

inline void mul(double to[],double z[],double y[])

{

	for(int i=0;i<=x;i++)for(int j=0;j<=x;j++)

		to[i^j]+=z[i]*y[j];

}

void calc(double b[],int n)

{

	if(n==1)

	{

		for(int i=0;i<=x;i++)b[i]=p[i];

		return;

	}

	double c[N]={0};

	calc(c,n/2);

	mul(b,c,c);

	if(n&1)

	{

		copy(c,b);

		zero(b);

		mul(b,c,p);

	}

}

int main() 

{

	//ios_base::sync_with_stdio(false);cin.tie(NULL);

	cin>>n>>x;

	for(int i=0;i<=x;i++)scanf("%lf",&p[i]);

	x*=2;

	double b[N]={0};

	calc(b,n);

	for(int i=1;i<=x;i++)ans+=b[i];

	cout<<fixed<<setprecision(10)<<ans;

	return 0;

}