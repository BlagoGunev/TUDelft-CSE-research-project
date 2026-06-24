#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

#define dump(n) cout<<"# "<<#n<<"="<<(n)<<endl
#define debug(n) cout<<__FILE__<<","<<__LINE__<<": #"<<#n<<"="<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,n) repi(i,0,n)
#define iter(c) __typeof((c).begin())
#define tr(c,i) for(iter(c) i=(c).begin();i!=(c).end();i++)
#define allof(c) (c).begin(),(c).end()
#define mp make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int,int> pii;

int sqr(int n)
{
	return n*n;
}

int main()
{
	int n,vb,vs;
	cin>>n>>vb>>vs;
	vi x(n);
	rep(i,n)
		cin>>x[i];
	int xu,yu;
	cin>>xu>>yu;
	
	int res=1;
	repi(i,1,n){
		double a=(double)x[res]/vb+hypot(x[res]-xu,yu)/vs;
		double b=(double)x[i]/vb+hypot(x[i]-xu,yu)/vs;
		if(fabs(a-b)<1e-10){
			if(sqr(x[res]-xu)+sqr(yu)>sqr(x[i]-xu)+sqr(yu))
				res=i;
		}
		else if(a>b)
			res=i;
	}
	cout<<res+1<<endl;
	
	return 0;
}