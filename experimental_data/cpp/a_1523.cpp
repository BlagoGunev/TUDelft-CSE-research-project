#include<bits/stdc++.h>

#define x first

#define y second

using namespace std;

using i64=long long;

void solve()

{

  string s;

  int n;

  int m;

  cin>>n;

  cin>>m;

  cin>>s;

  auto ans=s;

  int lastp=-2e9;

  for(int i=0;i<n;i++)

  {   

      if(i&&s[i]!=s[i-1]&&s[i-1]=='1')

      {

        lastp=i-1;

      }

      if(i-lastp<=m)

        ans[i]='1';

  }

  lastp=2e9;

   for(int i=n-1;i>=0;i--)

  {   

      if(i<n-1&&s[i]!=s[i+1]&&s[i+1]=='1')

      {

        lastp=i+1;

      }

      if(lastp-i<=m)

        ans[i]='1';

  }

  int cnt0=0;

  bool beg=true;

  for(int i=0;i<n;i++)

  {

      if(s[i]=='0')

        cnt0++;

      if(i&&s[i]!=s[i-1]&&s[i-1]=='1')

        beg=false;

      if(i>0&&s[i]!=s[i-1]&&s[i-1]=='0')

      {if(cnt0&1&&!beg)

      {

        ans[i-(cnt0+1)/2]='0';

      }

      beg=false;

      cnt0=0;

      }

  }

  cout<<ans<<"\n";

}

int main()

{

  std::ios::sync_with_stdio(false);

  std::cin.tie(nullptr);

  int t;

  cin>>t;

  while(t--)

  solve();

  return 0;

}