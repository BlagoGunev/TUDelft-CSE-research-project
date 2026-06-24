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

  vector<int>cnt(n);

  map<int,vector<int>>S;

  for(int i=0;i<n;i++)

  {cin>>a[i];

    a[i]--;

   S[cnt[a[i]]].push_back(i);

   cnt[a[i]]++;     

  }

  vector<int>b(n);

  for(int i=0;i<n;i++)

  {

    sort(S[i].begin(),S[i].end(),[&](int i,int j)

      {

        return a[i]<a[j];

      });

    int k=S[i].size();

    for(int j=0;j<k;j++)

      b[S[i][j]]=a[S[i][(j+1)%k]];

  }

  for(int i=0;i<n;i++)

    cout<<b[i]+1<<" ";

  cout<<"\n";

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