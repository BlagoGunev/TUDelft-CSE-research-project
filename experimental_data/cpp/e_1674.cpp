#include<bits/stdc++.h>

#define x first

#define y second

using namespace std;

using i64=long long;

void solve()

{

  int n;

  cin>>n;

  vector<int>a(n);

  for(int i=0;i<n;i++)

    cin>>a[i];

  int ans=1e9;

  auto b=a;

  sort(b.begin(),b.end());

  ans=min(ans,(b[0]+1)/2+(b[1]+1)/2);

  for(int i=1;i<n;i++)

    {

     ans=min(ans,max({(a[i-1]+1)/2,(a[i]+1)/2,(a[i]+a[i-1]+2)/3}));

    }

  for(int i=1;i+1<n;i++)

    {ans=min(ans,a[i-1]/2+a[i+1]/2+1);

    }

  cout<<ans<<"\n";

}

int main()

{

  std::ios::sync_with_stdio(false);

  std::cin.tie(nullptr);

  solve();

  return 0;

}