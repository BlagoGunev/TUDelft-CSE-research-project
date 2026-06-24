#include <bits/stdc++.h>
#include <chrono>
#include <random>
#include <iterator>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;



#define int ll
#define pf push_front
#define pb push_back
#define pob pop_back
#define pof pop_front 
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define kill(x) {cout <<(x) << endl; return;}
#define kandam std::ios_base::sync_with_stdio(0); 
#define vazhi cin.tie(NULL);
#define endl "\n"

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" " <<(x) << endl;
#else
#define debug(x);
#endif
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;


ll mod= 1e9 +7;//  998244353  ;
const ll inf= 2e18 +37 ;  const int infi=2e9+37;
const int  N= 3e5 + 37;      
vector <ll> fact ={1};


 ll fpow(ll b, ll p){ll ans=1; while(p){if(p%2)ans=(ans*b)%mod;b=b*b%mod;p/=2;} return ans;}
 ll sprime(ll n){for(int i=2;i*i<=n;i++)if(n%i==0)return i;return n; }
 inline ll ceil(ll a , ll b) {return (a+b-1)/b; }
 inline ll inv(ll n) { return fpow(n,mod-2); }
 void factorial(int Nf){for(int i=1;i<Nf;i++) fact.pb(fact[i-1]*i %mod); }
 ll C(ll n,ll r) {  if(n<r)return 0; return fact[n] *inv(fact[n-r]) % mod *inv(fact[r]) % mod; } 
 


   	  
void kingpin()
{
	int n,m;
	cin >> n >> m;
	
	string s[n];
	
	for(int i=0;i<n;i++)cin >> s[i];
	
	int l=0, r=0;
	
	for(int i=0;i<n;i++)
	{
		int c=0;
		for(int j=0;j<m;j++)c+=s[i][j]=='#';
		
		if(c>l)l=c, r=i;
	}
	int left=-1, right=0;
	
	for(int i=0;i<m;i++)if(s[r][i]=='#')
	{
		if(left==-1)left=i;
		right=i;
	}
	
	cout << (r+1) << " " << (left+right)/2 +1 << endl;
	
	
	
}
   	    
   	     
   	     
   	     
   	    
   	     
   	     
   	     
   	     
   	     
   	     
   	     

 
 
 
   
   
  
  
  
  
    
    




 
   
   
	 
	 
	 
     
     






       



int32_t main(void)      
 { 
 
 
 
 
  
  int T=1;
  
               cin >> T;

   
   
cout << fixed << setprecision(10);


  for(int ii=1;ii<=T;ii++) {
  	cerr<< "Test Case "<< " " << ii << endl;
  	kingpin();
  	
  	
  	cerr << "-----------------" << endl;
  }
  
  
  
  
   return 0; }