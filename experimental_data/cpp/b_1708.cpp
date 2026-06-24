#include <bits/stdc++.h>

using namespace std;



typedef long long ll;

#define fo(i, a, n) for (ll i = a; i < n; i++)

#define foe(i, a, n) for (ll i = a; i <= n; i++)

#define dbg(x) cout << #x << " = " << x << endl

#define pb push_back

#define ppb pop_back

#define all(x) (x).begin(), (x).end()

#define vi vector<ll>

#define vii vector<vector<ll>>

#define sz(x) ((ll)(x).size())



void solve()

{

   ll n,l,r,c=0;

   cin >> n>>l>>r;

   vi v;

   v.pb(l);

   foe(i,2,n){

      if(l%i==0){

         v.pb(l);

         c++;

      }

      else{

         ll j = l/i;

         j = (j+1)*i;

         if(j<=r){

            v.pb(j);

            c++;

         }

         else break;

      }

   }

   if(c==n-1){

      cout<<"YES\n";

      for(auto i : v) cout<<i<<" ";

         cout<<'\n';

   }

   else cout<<"NO\n";

}



int main()

{

   ios::sync_with_stdio(false); cin.tie(NULL);

   ll t = 1;

   cin >> t;

   while (t--)

   {

      solve();

   }

   return 0;

}