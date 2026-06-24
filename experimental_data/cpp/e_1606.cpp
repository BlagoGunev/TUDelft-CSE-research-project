#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#define tout cerr
#else
#define TEST(n) ((void)0)
#define tout cin
#endif

using namespace std;

const int MOD=998244353;
int D[501][501], V[501][501];

int mul(int a, int b) {return 1LL*a*b%MOD;}
int nCr(int n, int r)
{
	if(n==r || r==0) return 1;
	if(V[n][r]>-1) return V[n][r];
	return V[n][r]=(nCr(n-1,r)+nCr(n-1,r-1))%MOD;
}

int solve(int N, int X)
{
	if(N==1) return 1;
	if(N>X) return 0;
	if(D[N][X]>-1) return D[N][X];
	int v=1;
	D[N][X]=0;
	for(int i=0;i<N;i++) {
		D[N][X]=(D[N][X]+mul(nCr(N,i),mul(v,solve(N-i,X-N+1))))%MOD;
		v=mul(v,N-1);
	}
	return D[N][X];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt","r",stdin));
	TEST(freopen("output.txt","w",stdout));
	TEST(freopen("debug.txt","w",stderr));
	int N, X, ans=1;
	cin>>N>>X; memset(D,-1,sizeof(D)); memset(V,-1,sizeof(V));
	for(int i=0;i<N;i++) ans=mul(ans,X);
	if(N>X) {
		cout<<ans<<'\n';
		return 0;
	}
	for(int i=1;i<=X;i++) {
		ans-=solve(N,i);
		if(ans<0) ans+=MOD;
	}
	cout<<ans<<'\n';
	return 0;
}