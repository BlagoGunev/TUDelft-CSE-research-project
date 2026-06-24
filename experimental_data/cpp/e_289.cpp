#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<climits>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
#include<complex>
#include<set>
#include<bitset>
#include<utility>
#include<valarray>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<pair<int,int> > vpii;

#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define all(a) (a).begin(),(a).end()
#define len(a) ((int)(a).size())
#define mem(a,n) memset(a,n,sizeof(a))
#define eps 1e-9
#define rep(i,n) for(int i=0;i<(n);i++)
#define repi(i,a,n) for(int i=(a);i<(n);i++)
#define repr(i,a,n) for(int i=(n);i>=(a);i--)

int cbit(int n){
	int cc=0;
	while(n){
		cc++;
		n>>=1;
	}
	return cc;
}

int main(void){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	vi v(n+1,-1);
	ll re=0;
	repr(i,0,n){
		if(v[i]!=-1)continue;
		int x=cbit(i);
		int t=(1<<x)-1;
		t = i^t;
		//~ cout<<i<<" "<<x<<" "<<t<<endl;
		v[t]=i;
		v[i]=t;
		re+=2*(t^i);
	}
	cout<<re<<endl;
	rep(i,n+1){
		if(v[i]==-1)v[i]=i;
		cout<<v[i]<<" ";
	}
	return 0;
}