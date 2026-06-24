#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define MAXN 100000
#define ri(a) scanf("%d",&a)
#define rll(a) scanf("%lld",&a)
#define FOR(i,l,r) for(int i=l; i<r; i++)
using namespace std;

long long K, w;
int N, f;

struct path {
	int to, minL;
	long long sum;
};

vector<path> A(MAXN);

vector<path> solve(long long e) {
	vector<path> C(N), B;
	if(e==1) {
		FOR(i,0,N) {
			C[i].to=A[i].to;
			C[i].sum=A[i].sum;
			C[i].minL=A[i].minL;
		}
	} else {
		B=solve(e/2);
		FOR(i,0,N) {
			C[i].to=B[B[i].to].to;
			C[i].sum=B[i].sum+B[B[i].to].sum;
			C[i].minL=min(B[i].minL,B[B[i].to].minL);
		}
		if(e%2==1) {
			FOR(i,0,N) {
				C[i].sum+=A[C[i].to].sum;
				C[i].minL=min(C[i].minL,A[C[i].to].minL);
				C[i].to=A[C[i].to].to;
			}
		}
	}
	return C;
}

int main() {
	ri(N); rll(K);
	FOR(i,0,N) {
		ri(f);
		A[i].to=f;
	}
	FOR(i,0,N) {
		rll(w);
		A[i].minL=w;
		A[i].sum=w;
	}
	A=solve(K);
	FOR(i,0,N) printf("%lld %d\n",A[i].sum,A[i].minL);
}