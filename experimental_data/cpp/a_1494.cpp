#include "iostream"

#include "cmath"

#include "vector"

#include "cstring"

#include "map"

#include "set"

#include "algorithm"

#include "unordered_map"

#define nl "\n"

#define te cin >> t

#define pb push_back

#define pob pop_back

#define st for(int z=1;z<=t;z++)

#define ll long long int

#define pi 2*acos(0.0)

#define llu long long unsigned int

#define vect(type1,name) vector<type1>name

#define full(x) x.begin(),x.end()

#define amx = *max_element(arr,arr+n);

#define amn = *min_element(arr,arr+n);

#define gcd(x,y) (ll)(__gcd(x,y))

#define lcm(x,y) (ll)((x/gcd(x,y))*y)

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



using namespace std;



typedef pair<ll,ll>pr;

typedef vector<char>vc;

typedef vector<ll>vi;

typedef vector<string>vs;

typedef map<ll,ll>mp;

typedef set<ll>ss;

typedef multiset<ll>mst;

typedef unordered_map<ll,ll>ump;



void hello(){



   string s;

   cin >> s;

   ll n = s.size();

   if(s[0] == s[n-1]){

   cout << "NO" << nl;

   return;

   }

   char e = s[0],f = s[n-1];

   ll a=0,b=0;

   for(ll i=0;i<n;i++){

   if(s[i] == e)a++;

   else a--;

   if(a < 0){

   break;

   }

   }

   for(ll i=0;i<n;i++){

   if(s[i] != f)b++;

   else b--;

   if(b < 0){

   break;

   }

   }

   if(a == 0 or b == 0){

   cout << "YES" << nl;

   }

   else {

   cout << "NO" << nl;

   }

//   for(ll i=0;i<n;i++){

//   if(k[i] == e)

//   k[i] = '(';

//   else if(k[i] == f)

//   k[i] = ')';

//   else k[i] = '(';

//   }

//   ll c=0,d=0;

//   for(ll i=0;i<n;i++){

//   if(k[i] == '(')c++;

//   else c--;

//   if(c < 0){

//   cout << "NO" << nl;

//   return;

//   }

//   }

//   for(ll i=0;i<n;i--){

//   if(k[i] != ')')d++;

//   else d--;

//   if(d < 0){

//   cout << "NO" << nl;

//   return;

//   }

//   }

//   if(c == 0 or d == 0){

//   cout << "YES" << nl;

//   return;

//   }

//   else {

//   cout << "NO" << nl;

//   return;

//   }

//   ll a = count(s.begin(),s.end(),')');

//   ll b = count(s.begin(),s.end(),'(');

//   if(a == b){

//   cout << "YES" << nl;

//   return;

//   }

//   for(ll i=0;i<n;i++){

//   if(k[i] == e)

//   k[i] = '(';

//   else if(k[i] == f)

//   k[i] = ')';

//   else k[i] = '(';

//   }

//   ll c = count(k.begin(),k.end(),')');

//   ll d = count(k.begin(),k.end(),'(');

//   if(c == d){

//   cout << "YES" << nl;

//   return;

//   }

//   cout << "NO" << nl; {X}



}



int main(){



   FIO

   ll t;

   te;st

   hello();

   return 0;

}