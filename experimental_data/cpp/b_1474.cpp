// Problem: B. Different Divisors
// Contest: Codeforces - Codeforces Round #696 (Div. 2)
// URL: https://codeforces.com/contest/1474/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/* Author : Atahar Islam Shihab
   ICT'16th Batch,MBSTU
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define ll long long
#define maxele(v) *max_element(v.begin(),v.end())
#define minele(v) *min_element(v.begin(),v.end())
#define deb(x) cout << #x << " -> " << x << endl
#define deb2(x, y) cout << #x << " -> " << x << " || " << #y << " -> " << y << endl
#define fast  (ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0))
#define sz(x) x.size();
#define clr(x) memset(x, 0, sizeof(x))
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
const int mxn = 100005;
 
int main()
{
  fast;
  int tc ;
  cin >> tc;
  while(tc--)
  {
  	int d;
  	
  	cin >> d;
  	if(d==1) {cout << "6\n";continue;}
  	int x=1;
  	ll ans=1;
  	x+=d;
  	int lim=2;
  	for(int it=x; ;++it){
  		bool ok = true;
  		for(int i=2;i*i<=it;++i){
  			if (it%i==0){
  				ok = false;
  				break;
  			}
  		}
  		if (ok){
  			ans*=it;
  			break;
  		}
  	}
  	for(int it=ans+d; ; ++it){
  		bool ok = true;
  		for(int i=2;i*i<=it;++i){
  			if (it%i==0){
  				ok = false;
  				break;
  			}
  		}
  		if (ok){
  			ans*=it;
  			break;
  		}
  	}
  	cout << ans <<"\n";
  
  	
 
  }
 
 
  
 
  return 0;
}