#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define sz(a) a.size()
#define endl '\n'
#define inf 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define fastio std::ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i,a,b) for( int i=a; i<b; i++)
#define ii pair < ll , ll >
#define F first
#define S second
#define input freopen("C:\\Users\\ASUS\\Desktop\\input.txt","r+",stdin)
#define output freopen("C:\\Users\\ASUS\\Desktop\\output.txt","w+",stdout)
#define debug input; output

using namespace std;

  const int N=100005;

  int main(){ fastio;
   ll n;
   cin>>n;
   ll odd=0,even=0;
   while(n--)
   {
       ll x; cin>>x;
       odd+=(x%2);
       even+=(x%2)^1;
   }

   if (even>=odd)
   {
       cout<<odd; return 0;
   }

   cout<<even+(odd-even)/3;



  }