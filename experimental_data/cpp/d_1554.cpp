#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>



using namespace std;

using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

#define ll long long

#define endl '\n'

#define all(x) x.begin(), x.end()

ll BE(ll a, ll b)

{

  ll res = 1;

  while (b > 0)

  {

    if (b & 1)

    {

      res = (res * a * 1LL);

    }

    a = (1LL * a * a);

    b = b >> 1;

  }

  return res;

}



void pro()

{

  // read code

  // read consttraints

  // focus on something which is not seen but exist

  

  /////// *****Jil Patel***** ///////

  int n;

  cin >> n;

  if (n == 1)

  {

    cout << "a" << endl;

    return;

    }

		int x=n/2;

		string a=string(x,'a')+(n%2?"bc":"b")+string(x-1,'a');

		cout << a << endl;

}



int main()

{

  #ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("ouput.txt", "w", stdout);

  #endif

  ios::sync_with_stdio(0); // Input and output clearance

  cin.tie(0);

  ll t = 1;

  cin >> t;

  ll cnt = 1;

  while (t--)

  {

    // cout << "Case #" << cnt << ": ";

    pro();

    cnt++;

  }

}

//  int a[n];

//    fr(i, n) cin >>a[i];