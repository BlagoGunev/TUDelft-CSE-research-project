#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#define sz(a) ((int)(a).size())
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define Rep(i,j,k) for (int i=(j); i<=(k); i++)
#define Repd(i,j,k) for (int i=(j); i>=(k); i--)
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SUM(a) accumulate(all(a),string())
#define online1
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;

int n, a, b, h[210];
int f[2][41000][2];

inline void update(int &x, int y){
	if (y!=-1)
	if (x==-1 || y<x)
		x=y;
}

int main(){
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin>>n>>a>>b;
	Rep(i,1,n)
		scanf("%d",h+i);
		
	int now=0, next=1;
	memset(f,0xff,sizeof f);
	f[now][0][0]=0;
	
	Rep(i,0,n-1){
		Rep(j,0,min(a,i*200))
			Rep(o,0,1)
				if (f[now][j][o]!=-1)
					Rep(o1,0,1){
						int tmp=f[now][j][o];
						if (o1!=o) tmp+=min(h[i],h[i+1]);
						update(f[next][j+((!o1)?h[i+1]:0)][o1],tmp);
					}
		
		now^=1, next^=1;
		Rep(j,0,(i+1)*200)
			Rep(o,0,1)
				f[next][j][o]=-1;
	}
	
	int ans=-1, sum=0;
	Rep(i,1,n) sum+=h[i];
	Rep(j,0,a) if (sum-j<=b)
		update(ans,f[now][j][0]),
		update(ans,f[now][j][1]);
	cout<<ans<<endl;

    return 0;
}