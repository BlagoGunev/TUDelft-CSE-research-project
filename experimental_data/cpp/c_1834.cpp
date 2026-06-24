#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define ull unsigned long long
#define loop(i,a,n) for(ll i=a;i<n;i++)
#define rloop(j,n)  for(ll j=n-1;j>-1;j--)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define sort(v) sort(v.begin(),v.end());
#define dsort(v)  sort(arr, arr + n, greater<long long>());
#define pb push_back
#define ppb pop_back
#define vi.in(x) vi.insert(x)
#define ff first
#define ss second
#define endl "\n"
#define vi  vector<ll> vi
#define si set<ll> si
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll> > vpll;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; deb(x); cerr << endl;
#else
#define debug(x)
#endif
ll factorial(ll n)
{
    ll product = 1;
    for (int i = 1; i <= n; i++) product = product * i; return product;
}
 
bool isprime(int n)
{
    for (int i = 2; i * i <= n; i++){ if (n % i == 0) return true;} return false;
}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b) ; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b ; }
unsigned long long fibonacci(unsigned long long k) {
    double phi = (1 + sqrt(5)) / 2;
   return round((pow(phi, k) - pow(1 - phi, k)) / sqrt(5));
}
const long long M = 1000000007;

/* Karan Agg Template*/
ll power(ll a,ll b){
 
 if(b==0){
    return 1;
 }
ll res=power(a,b/2);

if(b&1){
    return a*res*res;
}
else {
    return res*res;
}


}
ll powerit(ll a,ll b){
 ll ans=1;
 while(b){
 if(b&1){

    ans=(a*ans)%M;
 }
 a=(a*a)%M;
 b>>=1;



 }



return ans;

}
ll small_factor(ll n){
    ll z=1;
  for (int i = 2; i * i <= n; i++){ 
      
      if (n % i == 0) {
          
          z=i;
          
          return z;}
      
     
      } 
      
      return z;
      }




      
/* Start From Here*/
void karan(){

/* Do Code Here*/
ll n;
cin>>n;
string s1;
string s2;
cin>>s1>>s2;
string s3=s1;
reverse(s3.begin(),s3.end());
if(s1==s2){
    cout<<0<<endl;
    return ;
}
if(s2==s3){
    cout<<2<<endl;
    return ;
}
string s4=s2;
reverse(s4.begin(),s4.end());
ll x=0,y=0;
loop(i,0,n){
 if(s1[i]!=s2[i]){
    x++;
 }
 if(s1[i]!=s4[i]){
    y++;
 }


}
bool normal=true;
bool reverse=true;



bool palindrome=true;
loop(i,0,n){
if(s2[i]!=s2[n-i-1]){
    palindrome=false;
    break;
}
}
if(palindrome==true){

    cout<<((x-1)*2)+1<<endl;
    return;
}
if(y<x){
if(y%2!=0){
    cout<<2*y<<endl;
}
else {
    cout<<(y*2)-1<<endl;
}
return;

}
if(x<y){
 if(x%2==0){
    cout<<2*x<<endl;
    return ;
 }
 else {
    cout<<2*x-1<<endl;
    return ;
 }

}

if(x==y){
if(x%2==0){
    cout<<2*x-1<<endl;
}
else {
    cout<<2*x-1<<endl;
}

    return ;
}

    return ;
}








int main() {
  #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;

    while (t--) {
 karan();


    }
    return 0;}