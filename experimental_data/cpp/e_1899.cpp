#include <bits/stdc++.h> 
using namespace std;
using ll = long long;

using vi = vector<int>;
using vll=vector<long long>;
#define pb push_back
#define all(x) begin(x), end(x)
#define rall(v) v.rbegin(),v.rend()
#define sz(x) (int) (x).size()
#define trav(a,x) for (auto& a : x)
#define lower(x) transform(x, ::tolower)
#define upper(x) transform(x, ::toupper)

using pi = pair<int,int>;
using vip =vector<pair<int,int>>;
using vllp =vector<pair<long,long>>;

ll factorial(ll n)    { if(n==0) return 1; ll res = 1; for (ll i = 2; i <= n; i++) res = res * i; return res; }
ll nPr(ll n, ll r)    { return factorial(n) / factorial(n - r); }
ll nCr(ll n, ll r)    { return factorial(n) / (factorial(r) * factorial(n - r));}
ll gcd(ll a, ll b)    { if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b)    { return (a * b) / gcd(a, b);}
bool isPrime(ll n)    { if(n <= 1) return false; for(ll i = 2; i*i <= n; i++) if(n % i == 0) return false; return true; }

#define fr(i,a,b) for(long long i=a;i<b;i++)
#define frr(i,a,b) for(long long i=b;i>=a;i--)
#define f first
#define s second
#define mp make_pair
#define popcount(x)  __builtin_popcountll(x)


void SnowFlame(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin); 
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
//-----------------------------------------------------------------------------------------------------------------
//tatakae! tatakae!!
//try solving upto 4 problmes in div 3 and 2 prblm in div 2 try for c 

//THE DAYS THAT BREAK U ARE THE DAYS THAT MAKE U!!!REMEMBER..
/*
int find(int x){
    int p=0;
    while(x>0){
        if(x&1){
            return p;
        }
        p++;
        x=x>>1;
    }
    return -1;
}
*/
void snow(){
  ll n;
  cin>>n;
  vi v(n);
  int mini=INT_MAX;
   fr(i,0,n) 
 {
cin>>v[i];
mini=min(mini,v[i]);
 }
 int ans=0;
 fr(i,0,n){
    if(v[i]==mini){
        ans=i;
        break;
    }
 }
 for(int i=ans+1;i<n;i++){
    if(v[i]<v[i-1]){
        cout<<"-1"<<endl;
        return;
    }
 }
 cout<<ans<<" "<<endl;
       
}

int main(){

 SnowFlame();
int tc;
cin>>tc;
while(tc--){
 snow();
}

return 0;
}

//solve maths from strivers cp sheet


// bitwise numbers are always written from highest priority bit to lowest priority bit
// left shift operator << increases bit. Eg - 16<<1 - 32
// right shift operator >> decreases bit. Eg - 16>>1 - 8
//atoi,stoll can be used for conversion from string to int, long, long long

// For binary search:

// initialize start && end as the extreme values in search space. If search space is [0,n-1], start=0,end=n-1
// use while(start<=end)
//Use mid=start+(end-start)/2
// implement 3 cases:
// If(value==ans), if(value<ans) && if(value>ans)

/*:
datatypes:
parity,exceptional cases,constraints.
go through test case to get any greedy logic and try patterns.
asking for optimized answer and have some kind of patterns ->dp.
estimated ans is less than n or max ans or min ans. with big bounds ->binary search.
if this step depends on forward steps -> try reverse as well.:
when problem is related to sorting -> have sorted vector aditionally.

*/