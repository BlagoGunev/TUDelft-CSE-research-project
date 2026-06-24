#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>
#include <list>
#include <ctime>
#include <complex>

#define F1(x,y,z) for(int x=(y);x<(z);x++)
#define F2(x,y,z) for(int x=(y);x<=(z);x++)
#define F3(x,y,z) for(int x=(y);x>(z);x--)
#define F4(x,y,z) for(int x=(y);x>=(z);x--)
#define mp make_pair
#define pb push_back
#define LL long long
#define co complex<double>
#define fi first
#define se second

#define MAX 100005
#define AMAX 1025*1005
#define MOD 1000000007

#define f(c,d) ((1<<(c))*(d))

using namespace std;

int n;
LL k,ta,ans,tb;
vector<LL> x;
map<LL,LL> m;
map<LL,LL>::iterator it;

LL ab(LL a){
	if(a<0)return -a;
	return a;
}

int main(){
	scanf("%d%lld",&n,&k);
	if(k==1)x.pb(1);
	else if(k==-1)x.pb(1),x.pb(-1);
	else{
		ta=1;
		while(ab(ta)<=MOD*(LL)n){
			x.pb(ta);
			ta*=k;
		}
	}
	//F1(a,0,x.size())printf("%lld\n",x[a]);
	m[ta=0]=1;
	F1(a,0,n){
		scanf("%lld",&tb);
		ta+=tb;
		F1(b,0,x.size()){
			//printf(" %lld\n",ta-x[b]);
			it=m.find(ta-x[b]);
			if(it!=m.end())ans+=it->se;
		}
		//printf("   %lld\n",ta);
		m[ta]++;
	}
	printf("%lld\n",ans);
	#ifdef LOCAL_PROJECT
	system("pause");
	#endif
	return 0;
}