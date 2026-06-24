#include "set"

#include "map"

#include "cmath"

#include "vector"

#include "cstring"

#include "iostream"

#include "algorithm"

#define nl "\n"

#define te cin >> t

#define pb push_back

#define pob pop_back

#define st for(int z=1;z<=t;z++)

#define ll long long int

#define llu long long unsigned int

#define vect(type1,name) vector<type1>name

#define full(x) x.begin(),x.end()

#define amx = *max_element(arr,arr+n);

#define amn = *min_element(arr,arr+n);

#define gcd(x,y) (ll)(__gcd(x,y))

#define lcm(x,y) (ll)((x/gcd(x,y))*y)

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);



using namespace std;



typedef pair<ll,ll> pr;

typedef vector<ll> v;

typedef vector<string> vs;

typedef map<ll,ll> mp;

typedef set<ll> ss;

typedef multiset<ll> mst;



void hello(){



   ll a,b,c,d;

   cin >> a >> b >> c >> d;

   if(c > a){

   if(c <= b)

   cout << c << nl;

   else cout << a+c << nl;

   }

   else{

   if(a <= d)

   cout << a << nl;

   else cout << a+c << nl;

   }



}



int main(){



   FIO

   ll t;

   te;st

   hello();

   return 0;

}