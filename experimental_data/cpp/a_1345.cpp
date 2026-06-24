#include"bits/stdc++.h"

using namespace std;

#define endl '\n'

#define ll long long

const ll mod = 1e9 + 7;



int main()

{

  int t, n, m;

  cin>>t;

  while (t--) {

    cin>>n>>m;

    if((n > 2 && m > 2) || (n >= 2 && m > 2) || (n > 2 && m >= 2)) cout<<"NO\n";

    else cout<<"YES\n";

  }

}