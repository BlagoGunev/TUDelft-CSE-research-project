#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <iomanip>
#include <utility>
#include <functional> 

using namespace std;

#define mp make_pair
#define pb push_back
#define pf push_front
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double dbl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> inline T qmin(const T a,const T b) {return a<b?a:b;} 
template<typename T> inline T qmax(const T a,const T b) {return a>b?a:b;}
template<typename T> inline void getmin(T &a,const T b) {if(a>b) a=b;}
template<typename T> inline void getmax(T &a,const T b) {if(a<b) a=b;}

void fileio(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

const int inf=1e9+7;
const ll linf=1e17+7;

const int N=1e3+7;

int pos[N][N][8],a[N],n;
int f[N][1<<8];

bool check(int x){
	memset(f,0,sizeof(f));
	f[0][0]=1;
	for(int i=0;i<=n;++i){
		for(int comb=0;comb<1<<8;++comb){
			if(i) f[i][comb]|=f[i-1][comb];
			if(!f[i][comb]) continue;
			if(comb==(1<<8)-1) return true;
			for(int c=0;c<8;++c){
				if(((comb>>c)&1)||(!pos[i+1][x][c])) continue;
				f[pos[i+1][x][c]][comb|(1<<c)]=1;
			}
		}
	}
	return false;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		--a[i];
	}
	for(int i=n;i;--i){
		for(int c=0;c<8;++c){
			pos[i][1][c]=(a[i]==c?i:pos[i+1][1][c]);
			for(int j=2;j<=n;++j){
				if(!pos[i+1][j-1][c]) continue;
				pos[i][j][c]=(a[i]==c?pos[i+1][j-1][c]:pos[i+1][j][c]);
			}
		}
	}
//	cerr<<pos[2][1][1]<<endl;
	int ul=0,ur=n+1;
	while(ur-ul>1){
		int mid=ul+ur>>1;
		if(check(mid)) ul=mid;else ur=mid;
	}
//	cerr<<ul<<endl;
	if(!ul){
		int comb=0;
		for(int i=1;i<=n;++i) comb|=1<<a[i];
		printf("%d\n",__builtin_popcount(comb));
		return 0;
	}
	int ans=-inf,x=ul;
	memset(f,-1,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<=n;++i){
		for(int comb=0;comb<1<<8;++comb){
			if(i) getmax(f[i][comb],f[i-1][comb]);
			if(f[i][comb]<0) continue;
			if(comb==(1<<8)-1) getmax(ans,f[i][comb]);
			for(int c=0;c<8;++c){
				if((comb>>c)&1) continue;
				
				int end=pos[i+1][x][c];
				if(!end) continue;
				getmax(f[end][comb|(1<<c)],f[i][comb]+x);
				
				end=pos[i+1][x+1][c];
				if(!end) continue;
				getmax(f[end][comb|(1<<c)],f[i][comb]+x+1); 
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}