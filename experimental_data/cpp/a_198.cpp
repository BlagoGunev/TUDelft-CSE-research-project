#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<pair<ll, ll> > vii;
# define M_PI           3.14159265358979323846 
#define PB push_back

#define FOR(prom,a,b) for ( ll prom = (a); prom < (b); ++prom )
#define F(a) FOR(i,0,a)
#define FF(a) FOR(j,0,a)

#define MM(co, cim) memset( (co), (cim), sizeof((co)) )
#define DEB(x) cerr << ">>> " << #x << " : " << x << endl;

#define EPS (1e-10)
#define INF (1<<30)

int main(){
	ld K, B, N, T;
	cin>>K>>B>>N>>T;
	if(K==1){
		if(1+B*N<=T){
			cout<<0<<endl; return 0;
		}
		cout<<(int)ceil((1+B*N-T)/B)<<endl;
		return 0;

	}
	ld A=log((K*T-T+B)/(K-1+B));
	ld C = log(K);
	ld res=(A)/C;
	if(res>N){ //nebo rovno?
		cout<<0<<endl; return 0;
	}
	cout<<(int)ceil(N-res)<<endl;   
	return 0;
}