#include <bits/stdc++.h>

using namespace std;

typedef vector<long long> V;

typedef long long ll;



#define int long long

#define f(i,a,b) for (int i = a; i < b; i++)

#define trav(a, x) for(auto& a : x)

#define all(x) x.begin(), x.end()

#define sz(x) (int)(x).size()

#define pb push_back

#define mp make_pair

#define endl "\n"

signed main()

{

  ios_base::sync_with_stdio(false);

  cin.tie(NULL);

  cout.tie(NULL);

  int t;

  cin>>t;

  while(t--)

  {

    int n,k;

    cin>>n>>k;

    int a[n];

    set<int> s;

    f(i,0,n)

    {

      cin>>a[i];

      s.insert(a[i]);

    }



    if(sz(s)>k)

    {

      cout<<-1<<endl;

      continue;

    }

    ll x=0;

    while(sz(s)<k)

    {

      s.insert(++x);

    }

    cout<<n*k<<endl;

    f(i,0,n)

    {

      trav(a,s)

      {

        cout<<a<<" ";

      }

    }

    cout<<endl;

  }

  return 0;

}