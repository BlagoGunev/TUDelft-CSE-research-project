#include <bits/stdc++.h>

#define pb push_back

#define soyaib cin.tie(0); ios_base::sync_with_stdio(false); cout.tie(0)

#define endl "\n"

#define all(v) v.begin(),v.end()

#define ll long long

using namespace std;



int main()

{

    soyaib;

    ll t;

    cin >> t;



    while(t--)

  {

      ll a, b, c, d, e, f, g, h, l, m, n, o=0, p=0;



      cin >> n;

      ll arr[n+1], arr1[n+1];

      arr1[0] = 0;

      arr[0] = 0;



      for(ll i = 1; i <= n; i++)

      {

           cin >> arr[i];

           arr1[i] = arr1[i-1] + arr[i];

      }



      for(ll i=1; i<n; i++)

      {

          a = arr1[n] - arr1[i];

          o = __gcd(arr1[i], a);

          p = max(p, o);

      }



      cout << p << endl;



  }

}