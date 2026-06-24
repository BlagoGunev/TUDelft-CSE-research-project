#include <iostream>

#include <algorithm>

#include <cmath>

#include <math.h>

#include <vector>

#include <map>

#include <set>

#include <unordered_set>

#include <unordered_map>

#include <string>

#include <cstring>

#include <stack>

#include <numeric> 

#include <bitset>



/* LAMBDA Example

  auto mx = max_element(mpp.begin(), mpp.end(),

              [](auto &x,auto &y){return x.second < y.second;});



  cout << mx->first << endl;

  

  bool cmp(string a, string b) {

    if (d[a][0] != d[b][0]) return d[a][0] > d[b][0];

    if (d[a][1] != d[b][1]) return d[a][1] < d[b][1];

    for (int i = 0; i < a.size(); i++) {

        if (a[i] != b[i]) return a[i] > b[i];

    }

    return false;

    }



*/

 

// CP template

// substr(first_indice, last_indice) to get substring

using namespace std;

#define eps 1e-9

#define debug(x) cout << (#x) << " = " << x << endl

#define _USE_MATH_DEFINES

typedef pair<int,int> pii;

typedef long long int ll;

typedef unsigned long long int ull;

typedef vector<int> vi;

typedef vector<ll> vll;

typedef vector<char> vc;

#define all(v)       ((v).begin()), ((v).end())

#define rall(v)      ((v).rbegin()), ((v).rend())

#define endl "\n"

#define pi M_PI

#define cin_str(s)   (getline(cin, s))

/* To avoid problems with negative numbers in cpp ! */

#define modulo_neg(a,b) ((a%b + b)%b) 

 

void fast_io(string name="tests")

{

  ios::sync_with_stdio(NULL);

  cin.tie(NULL), cout.tie(NULL); 

  #ifndef ONLINE_JUDGE

    freopen((name+".in").c_str(), "r", stdin);

    freopen((name+".out").c_str(), "w", stdout);  

  #endif 

}

 

 

ll gcd(int a,int b){while(b^=a^=b^=a%=b);return a;}

ll lcm(int a, int b){return (a / gcd(a, b)) * b;}

 

string strip(string res)

{

  for(int i = res.size()-1; i > 0; --i)

  {

    if(res[i] != ' ')

    {

      res.erase(res.begin()+i+1, res.end());

      break;

    }

  }

  return res;

}



string bin(ll x)

{

  string s = bitset<64>(x).to_string();

  const auto loc1 = s.find('1');

  return s.substr(loc1) ;

}



template <typename A, typename B>

multimap<B, A> flip_map(map<A,B> & src) {

    multimap<B,A> dst;

    for (typename map<A, B>::const_iterator it = src.begin(); it != src.end(); ++it)

        dst.insert(pair<B, A>(it -> second, it -> first));

    return dst;

}



bool isPrime(int n)

{

  if (n <= 1){return false;}

  for (int i = 2; i * i <= n; i++)

  {if (n % i == 0){return false;}}return true;

}



void primeFactors(int n)

{

    int c=2;

    while(n>1)

    {

        if(n%c==0){

        cout<<c<<" ";

        n/=c;

        }

        else c++;

    }

}



// Order of args references order in the Container.

bool comp(string a, string b)

{

  return a.size()>=b.size();

}



ll fact(int n)

{

  if(n==0)return 1;

  return fact(n-1)*n;

}



// Problem's Code 

void solve()

{

  int t;

  cin >>t;

  while(t--)

  {

    ll a,b;

    cin>>a>>b;

    if(a<2){cout << 0 <<endl;}

    else if(a==2){cout << b << endl;}

    else{cout<< 2*b<<endl;}

  }

}



// Main function

int main()

{

  fast_io("tests");

  solve();

}