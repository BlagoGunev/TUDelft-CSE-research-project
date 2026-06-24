#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <list>
#include <map>
#include <set>
#include <fstream>
#include <iostream>
#include <queue>
#include <algorithm>
#include <sstream>
#include <limits.h>
#define _USE_MATH_DEFINES 
#include <math.h> 

#define pb(a) push_back(a) 
#define sz size()
#define ALL(a) a.begin(),a.end()
#define ALLR(a) a.rbegin(),a.rend()
#define X first
#define Y second

typedef long long ll;
typedef long double ld;

template<typename T> inline void SWAP(T &a, T &b){T tmp=a;a=b;b=tmp;}
template<typename T> inline T ABS(const T &val) {return val<0?-val:val;}
template<typename T> inline T MAX(const T &a, const T &b){return a>b?a:b;}
template<typename T> inline T MIN(const T &a, const T &b){return a<b?a:b;}

#define MSET(d) memset(d,0,sizeof(d))
#define forn(i,n) for(int i=0;i!=n;i++)
#define for1(i,n) for(int i=1;i<=n;i++)
#define forab(i,a,b) for(int i=a;i!=b;i++)
#define for1ab(i,a,b) for(int i=a+1;i<=b;i++)
#define fordab(i,a,b) for(int i=b-1;i>=a;i--)
#define ford1ab(i,a,b) for(int i=b;i!=a;i--)
#define ford(i,n) for(int i=n-1;i!=-1;i--)
#define ford1(i,n) for(int i=n;i!=0;i--)

const int INTinf=2147483647;
const int nINTinf=0-2147483648;
#define LLinf 9223372036854775807

using namespace std;
typedef pair<int, int> pii;
int n,m,a, n2;
int lvl[10];
int rasp[10];

ld MX=0.0;
ld tmp;
void calc(int pos, ld chance, int sum, int acc){
	if (pos==n){
		if (acc>n2){
			tmp+=chance;
		} else
		if (sum==0){
			tmp+=chance;
		} else {
			tmp+=(chance*a)/(a+sum);
		}
	} else
	if (rasp[pos]>=10){
		calc(pos+1, chance, sum, acc+1);
	}
	else if (rasp[pos]){
		calc(pos+1, (chance*rasp[pos])/10, sum, acc+1);
		calc(pos+1, (chance*(10-rasp[pos]))/10, sum+lvl[pos], acc);
	} else calc(pos+1, chance, sum+lvl[pos], acc);
}
void konf(int kol, int pos){
	if (!kol){
		tmp=0.0;
		calc(0, 1, 0, 0);
		if (tmp>MX) MX=tmp;
	} else
	if (pos==n-1){
		rasp[pos]+=kol;
		tmp=0.0;
		calc(0, 1, 0, 0);
		if (tmp>MX) MX=tmp;
		rasp[pos]-=kol;
	} else{
		int mmm=MIN(kol, 10-rasp[pos]);
		for1ab(i, -1, mmm){
			konf(kol-i, pos+1);
			rasp[pos]++;
		}
		rasp[pos]-=mmm+1;
	}
}
int main(){
	//freopen("input.txt","r",stdin);
	cin>>n>>m>>a;
	n2=n>>1;
	forn(i,n){
		cin>>lvl[i]>>rasp[i];
		rasp[i]/=10;
	}
	konf(m, 0);
	cout.setf(ios_base::fixed);
	cout.precision(10);
	cout<<MX<<endl;
	return 0;
}