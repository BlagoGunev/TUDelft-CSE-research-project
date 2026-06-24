#include<bits/stdc++.h>

#define x first

#define y second

using namespace std;

using i64=long long;

void solve() 

{ 

  int n,k;

  cin>>n>>k;

  vector<int>c(n*k);

  for(int i=0;i<n*k;i++)

    cin>>c[i],c[i]--;

  int lim=(n+k-2)/(k-1);

  vector<int>pre(n,-1);

  vector<int>l(n,-1);

  vector<int>r(n);

  int list=0;

  int cur=0;

  for(int i=0;i<n*k;i++)

  {

    if(l[c[i]]>=0)

    {

      continue;

    }

    if(pre[c[i]]>=list)

    {

      l[c[i]]=pre[c[i]];

      r[c[i]]=i;

      cur++;

      if(cur==lim)

      {

        list=i+1;

        cur=0;

      }

    }

    pre[c[i]]=i;

  }

  for(int i=0;i<n;i++)

    cout<<l[i]+1<<" "<<r[i]+1<<"\n";

}

int main()

{

  std::ios::sync_with_stdio(false);

  std::cin.tie(nullptr);

  solve();

  return 0;

}