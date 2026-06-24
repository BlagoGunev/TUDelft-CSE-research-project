#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<algorithm>
//#include<string>
//#include<sstream>
//#include<vector>
//#include<map>
//#include<set>
//#include<ctype.h>
//#include<stack>
//#include<queue>
#ifdef LOCAL
FILE*FP=freopen("text.in","r",stdin);
//FILE*fp=freopen("text.out","w",stdout);
#endif
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define piii pair<int,pii>
#define pll pair<ll,ll>
#define plll pair<ll,pll> 
#define pdd pair<double,double>
#define pdi pair<double,int>
#define pid pair<int,double>
#define vi vector <int> 
#define vii vector <vi> 
#define st first
#define nd second
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define _forplus(i,a,b) for( register int i=(a); i<=(b); i++)
#define forplus(i,a,b) for( register int i=(a); i<(b); i++)
#define _forsub(i,a,b) for( register int i=(a); i>=(b); i--)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define pi (acos(-1))
#define EPS 0.00000001
#define MOD 1000000007
#define fastio 	std::ios::sync_with_stdio(false);std::cin.tie(0);
int main(){
	#define int ll
	fastio
	int t;
	cin>>t;
	while(t--){
		int r,b,d;
		cin>>r>>b>>d;
		if(min(r,b)*d>=abs(r-b))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}