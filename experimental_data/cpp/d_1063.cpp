#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<bitset>
#include<stack>
#include<memory>
using namespace std;
typedef long long int llint;
typedef long double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
/*
cout<<fixed<<setprecision(20);
cin.tie(0);
ios::sync_with_stdio(false);
*/
const llint mod=1000000007;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-15;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
int main(void){
	llint n,l,r,K;cin>>n>>l>>r>>K;
	llint A=(r-l+n)%n +1;
	if(K<A){cout<<-1<<endl;return 0;}
	if(n<=sqrt(K)){
		for(llint s=n;s>=0;s--){
			llint t=(K-A)%(n+s);
			if(A+s-n-1<=t&&t<=s&&t<=A){cout<<s<<endl;return 0;}
		}
		cout<<-1<<endl;
		return 0;
	}else{
		//d は 何週しましたか
		llint ans=-1;
		//0週を特別管理
		if(K<=A+A){ans=n+K+1-A-A;}
		if(K==A+A){ans--;}
		for(llint d=1;d*n<=K-A;d++){
			llint s=min((K-A-A+n+1-n*d)/(d+1),(K-A-n*d)/d);
			llint t=(K-A)%(n+s);
			if(A+s-n-1<=t&&t<=s&&t<=A){maxeq(ans,s);}
		}
		cout<<ans<<endl;
	}
	return 0;
}