#include <iostream>

#include <cstdio>

#include <cmath>

#include <cstring>

#include <algorithm>

#include <vector>

#include <map>

#include <cstdlib>

#include <set>

using namespace std;



#define X first

#define Y second

#define Mod 1000000007

#define N 500110

#define Inf 1000000007

typedef long long ll;

typedef pair<int,int> pii;



int a,b,k,t;

int factor[N],inv[N];



inline int Mul(int x,int y){return 1ll*x*y%Mod;}

inline int Add(int x,int y){return ((x+y)%Mod+Mod)%Mod;}



int Power(int x,int p)

{

	int tmp=1;

	while (p)

	{

		if (p&1) p^=1,tmp=Mul(tmp,x);

		else p>>=1,x=Mul(x,x);

	}

	return tmp;

}



int C(int n,int m)

{

	if (m==0) return 1;

	if (m>n) return 0;

	return Mul(factor[n],Mul(inv[m],inv[n-m]));

}



int Calc(int l,int r)

{

	if (l<=0) return C(r+1,2*t);

	else return C(r+1,2*t)-C(l+1,2*t);

}



int main()

{

	//freopen("in.in","r",stdin);

	//freopen("out.out","w",stdout);

	

	scanf("%d%d%d%d",&a,&b,&k,&t);

	if (b-a>=2*k*t){printf("0\n");return 0;}

	factor[0]=1;

	for (int i=1;i<N;i++) factor[i]=Mul(factor[i-1],i);

	inv[N-1]=Power(factor[N-1],Mod-2);

	for (int i=N-2;i>=0;i--) inv[i]=Mul(inv[i+1],i+1);

	

	int Ans=0,op=1;

	for (int i=0;i<=2*t;i++)

	{

		Ans=Add(Ans,Mul(C(2*t,i),op*Calc(2*t-1+b-a+2*k*t-(2*k+1)*i,2*t-1+4*k*t-(2*k+1)*i)));

		//cout<<2*t-1+b-a+2*k*t-(2*k+1)*i<<" "<<2*t-1+4*k*t-(2*k+1)*i<<" "<<Calc(2*t-1+b-a+2*k*t-(2*k+1)*i,2*t-1+4*k*t-(2*k+1)*i)<<endl;

		op*=-1;

		//cout<<i<<" "<<Ans<<endl;

	}

	if (Ans<0) Ans+=Mod;

	printf("%d\n",Ans);

	return 0;

}