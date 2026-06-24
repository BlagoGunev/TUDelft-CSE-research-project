#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

struct pii{
	int x,y;
	pii(){
	};
	pii(int _x,int _y){
		x=_x;y=_y;
	};
	bool operator<(const pii &X)const{
		if (x!=X.x) return (x<X.x);
		return (y<X.y);
	};
};

#define pb push_back
#define sz size()
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for (int i=(a);i<=(b);i++)
#define FORE(it,v) for (typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define N 100010
const int oo=(int)1e9;

bool debug;
int st,cnt,f[N],n;
bool ok;

void solve(){
	int t;
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		printf("%d\n",max(n-2,0));
	}
}

int main(){
	//debug=1;
	solve();
	//if (debug) system("pause");
	return 0;
}