//################################################# 

              // CODED BY BHASKAR //

//################################################# 



#include <bits/stdc++.h>

using namespace std;



#define ll long long

#define ld long double

#define mp make_pair

#define pb push_back

#define ppb pop_back

#define MODULO 1e9+7

#define PI 3.14

#define debug1(a) cout<<#a<<"="<<a<<endl;

#define debug2(a,b) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<endl;

#define debug3(a,b,c) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<endl;

#define debug4(a,b,c,d) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<endl;

#define debug5(a,b,c,d,e) cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<endl;

#define print1(a) cout<<a<<endl;

#define print2(a,b) cout<<a<<" "<<b<<endl;

#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;

#define print4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

#define print5(a,b,c,d,e) cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;

#define ln cout<<endl;

#define print1Darr(a,n) for(ll i=0; i<n; i++){cout<<a[i]<<" ";}cout<<endl;

#define print1Dvect(v) for(ll i=0; i<v.size(); i++){cout<<v[i]<<" ";}cout<<endl;

#define print2Darr(a,row,column) for(ll i=0; i<row; i++){for(ll j=0; j<column; j++){cout<<a[i][j]<<" ";}cout<<endl;}

#define print2Dvect(v) for(ll i=0; i<v.size(); i++){for(ll j=0; j<v[i].size(); j++){cout<<v[i][j]<<" ";}cout<<endl;}

#define printMap(mm) for(auto it=mm.begin(); it!=mm.end(); it++){cout<<it->first<<" "<<it->second<<endl;}

#define printSet(s) for(auto it=s.begin(); it!=s.end(); it++){cout<<*it<<" ";}cout<<endl;

#define printVectPair(v) for(ll i=0; i<v.size(); i++){cout<<v[i].first<<" "<<v[i].second<<endl;}

#define sortArr(a,n) sort(a,a+n);

#define sortVect(v) sort(v.begin(),v.end());

#define revArr(a,n) reverse(a,a+n);

#define revVect(v) reverse(v.begin(),v.end());

#define IFOR(a,n) for(ll i=a; i<n; i++)

#define JFOR(a,n) for(ll j=a; j<n; j++)

#define KFOR(a,n) for(ll k=a; k<n; k++)

#define IFORREV(n,a) for(ll i=n-1; i>=a; i--)

#define JFORREV(n,a) for(ll j=n-1; j>=a; j--)

#define KFORREV(n,a) for(ll k=n-1; k>=a; k--)

#define inArr(a,n) IFOR(0,n){cin>>a[i];}

#define inVect(v,n) IFOR(0,n){ll x;cin>>x;v.pb(x);}

#define NO cout<<"NO"<<endl;

#define YES cout<<"YES"<<endl;

#define sz(x) ((ll)(x).size())

#define uniqueVect(v) v.erase(unique(v.begin(),v.end()),v.end());

ll digitCount(ll n){return (floor(log10(n)+1));}

ll leftMostSetBit(ll n){ll x=log2(n);return x;}

ll countOfSetBit(ll n){return (bitset<32>(n).count());}

ll sumArr(ll a[],ll s,ll n){ll jodd=0;for(ll i=s; i<n; i++){jodd+=a[i];}return jodd;}

ll sumVect(vector<ll> &v){ll jodd=0;for(ll i=0; i<v.size(); i++){jodd+=v[i];}return jodd;}

ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}

ll lcm(ll a,ll b){return (a/gcd(a,b))*b;}

ll modAdd(ll a,ll b,ll m){a=a%m; b=b%m;return (((a+b)%m)+m)%m;}

ll modMul(ll a,ll b,ll m){a=a%m; b=b%m;return (((a*b)%m)+m)%m;}

ll modSub(ll a,ll b,ll m){a=a%m; b=b%m;return (((a-b)%m)+m)%m;}

ll nextPerfectSquare(ll x){if(x>=0){ll sr=sqrt(x);if(sr*sr==x){return x;}}ll nextN=floor(sqrt(x))+1;return nextN*nextN;}

bool isPalindrome(string s){ll low=0,high=s.size()-1;while(low<=high){if(s[low++]!=s[high--]){return false;}}return true;}

bool isPowerOfTwo(ll n){if(n==0){return false;} return (ceil(log2(n))==floor(log2(n)));}

bool isArrSorted(ll *arr, ll n){for(ll i=0; i<n-1; i++){if(arr[i]>arr[i+1]){return false;}}return true;}

bool isVectSorted(vector<ll> &v){for(ll i=0; i<v.size()-1; i++){if(v[i]>v[i+1]){return false;}}return true;}

//---------------------------------------------------------------------------------------------------------------------------------------



//======== CUSTOM FUNCTIONS() =========







//=====================================



//========= SOLVE() ===================



void solve(){

//---------------------------

    ll n;

    cin>>n;



    ll temp=floor(sqrt(n));

    if(temp*temp==n){

        cout<<(temp-1)*2<<endl;

    }else{

        ll rest=n-(temp*temp), rest1;

        if(rest%temp==0){

            rest1=rest/temp;

        }else{

            rest1=rest/temp+1;

        } 

        cout<<2*(temp-1)+rest1<<endl;

    }

//---------------------------

}



//=====================================



//========= MAIN() ====================



int main(){

    ll testCase=1;

    cin>>testCase;

    while(testCase--){

        solve();

    }

	return 0;

}



//=====================================