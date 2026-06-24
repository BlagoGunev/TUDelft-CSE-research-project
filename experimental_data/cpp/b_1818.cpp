//           卐   卐   卐   卐  卐

//--------------x--------------x-----------x-------------//

//
//          卐   卐   卐   卐  卐

#include <bits/stdc++.h>

using namespace std;

#define l long long

#define vi vector<l>

#define pb push_back

#define har(v) (v.begin(), v.end())

#define f(i, a, n) for (l i = a; i < n; i++)

#define mod 1e9+7

#define ff first

#define ss second


l pw(l n)
{
  return log2(n & (~(n - 1)));
}

const int N = 1e6+1;
vi v[N];
vi fib(69);

// vector<vector<l>>v;
bool visited[N] = {0};
// l pref[N];
l n ;
l m1[N];
void dfs(l vertex)
{
  visited[vertex] = 1;
  // e++;
  // dfs(vertex);
  for (l i = 0; i < v[vertex].size(); i++)
  {
    if (visited[v[vertex][i]] == 0)
    {
      dfs(v[vertex][i]);
      // visited[child]=1;
    }
  }
}



//-----------------------------x---------------x-----------------------------------------------------


void uper_dekh()
{
  l i,j,k,c;
  cin>>n;
  if (n==1){
    cout<<1;
    return;
  }
  if (n%2==1){
    cout<<-1;
    return;
  }
  f(i,2,n+1){
    cout<<i<<" "<<i-1<<" ";
    i++;
  }




 
  }
  

  




 



int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin.tie(NULL);
  l tt = 1;
  cin>>tt;
  //fibo();
  // factor()

  for (l i = 1; i <= tt; i++)
  {
    uper_dekh();
   cout<<endl;
  }
  return 0;
}