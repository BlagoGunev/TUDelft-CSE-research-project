/*

██████████████████████████████████████████████████████████████████████████████████████████████████████████

█░░░░░░░░░░░░░░█░░░░░░██░░░░░░█░░░░░░░░░░░░░░█░░░░░░██░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░░░░░███░░░░░░░░░░░░░░█

█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀░░░░█░░▄▀▄▀▄▀▄▀▄▀░░█

█░░▄▀░░░░░░░░░░█░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░░░▄▀▄▀░░█░░▄▀░░░░░░▄▀░░█

█░░▄▀░░█████████░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█

█░░▄▀░░░░░░░░░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░▄▀░░█

█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█

█░░░░░░░░░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░▄▀░░█

█████████░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█

█░░░░░░░░░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░░░▄▀▄▀░░█░░▄▀░░██░░▄▀░░█

█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀░░░░█░░▄▀░░██░░▄▀░░█

█░░░░░░░░░░░░░░█░░░░░░██░░░░░░█░░░░░░██░░░░░░█░░░░░░██░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░░░░░███░░░░░░██░░░░░░█

*/



#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define NUM 1e18

#define Mod 1'000'000'007

#define OO 2'000'000'000

#define all(v) ((v).begin()), ((v).end())

#define allr(v) ((v).rbegin()), ((v).rend())

#define sz(v) ((ll)((v).size()))

#define Ceil(a, b) ((a / b) + (a % b ? 1 : 0))

#define is_small(c) (c >= 97 && c <= 122)

#define is_cap(c) (c >= 65 && c <= 90)

#define cin(v)   for (auto &i : v)  cin >> i;

#define cinp(v)    for (auto &i : v) cin >> i.first >> i.second;

#define coutp(v)      for (auto &i : v) cout << i.first << " " << i.second << "\n";

#define cin2D(v)      for (auto &i : v)  for (auto &j : i) cin >> j;

#define cout2D(v)   for (auto &i : v) {  for (auto &j : i) {  cout << j << " "; } cout << "\n";}

#define cout(v)   for (auto &i : v)  cout << i << " "; cout << "\n";

#define fixed(n) cout << fixed << setprecision(n);

#define nl cout << "\n";

#define Digits(n) 1 + floor(log10(n))  

#define is_vow(c) (c == 'a' || c == 'o' || c == 'u' || c == 'i' || c == 'e')

const ll NO = 1073741824;

const float si = 0.16666666666666666666666666666667;

// getline( cin>>ws , s )

void fast_io()

{

  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

#ifndef ONLINE_JUDGE

  freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);

#endif

}



vector<ll> Insert(string &s)

{

  vector<ll> res;



  for (auto &i : s)

    res.push_back(i - '0');



  return res;

}

bool sq(ll n)

{

  ll s = sqrt(n);

  return s * s == n;

}

// bool comp(ll x, ll y)

// {

//   return abs(x) <= abs(y);

// }

ll gcd(ll int a, ll int b)

{

  if (b == 0)

    return a;

  return gcd(b, a % b);

}



ll lcm(ll a, ll b)

{

  return (a / gcd(a, b) * b);

}



long long base_decimal(string n, long long num, unsigned ll mod)

{

  auto val = [](char c)

  {

    return (c >= '0' && c <= '9' ? (int)c - '0' : (int)c - 'A' + 10);

  };



  long long size = n.size() - 1, res = 0, pow = 1;



  for (long long i = size; i >= 0; i--)

  {

    res += (val(n[i]) * pow) % mod;

    pow *= num % mod;

    pow %= mod;

  }



  return res;

}

float logarithm(ll a, ll b)

{

  return log2(a) / log2(b);

}

bool comp1(pair<ll,ll>&a , pair<ll,ll>&b)

{

       return a.second > b.second ;

}



//****************************************************************************

 void solve()

 {  

    ll n , cnt = 0 ; cin >> n ; 

    vector<ll>v(n) ;



   for(ll i = 0 , x ; i < n ;i++)  

   {

      cin >> x ;

      v[i] = x % 2 ;

   }



  for(ll i = 0 ; i < sz(v) ; i++) 

  {

      if(v[i] != (i % 2))

      {

          for(ll j = i+1 ;j < sz(v) ; j++)

          {

             if(v[i] == (j%2) && v[j] != (j%2)) 

             {

               cnt++ ; 

               swap(v[i] , v[j]) ;

               break;

             } 

          }

      }

  } 

  for(ll i = 0 ; i < sz(v) ; i++) 

     if(v[i] != (i % 2)) 

      return  void(cout << -1 <<"\n");

  

  cout << cnt <<"\n";

 } 

 

int main()

{

  fast_io();

   int t = 1 ;  cin >> t;

  while (t--)

    solve();



  return 0;

}