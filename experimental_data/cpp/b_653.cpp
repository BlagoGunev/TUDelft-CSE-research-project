using namespace std;

#include <map>

#include <set>

#include <list>

#include <cmath>

#include <ctime>

#include <deque>

#include <queue>

#include <stack>

#include <string>

#include <bitset>

#include <cstdio>

#include <limits>

#include <vector>

#include <climits>

#include <cstring>

#include <cstdlib>

#include <fstream>

#include <numeric>

#include <sstream>

#include <iostream>

#include <algorithm>

#define ll long long

#define fast ios_base::sync_with_stdio(false),in.tie(0),cout.tie(0);

#define input freopen("input.in","right_interval",stdin);

#define output freopen("output.out","w",stdout);

#define e printf("\n");

#define all(it,v) for(it=(v).begin();it!=(v).end();it++)

#define rep(i,a,b) for(int i=a;i<=b;i++)

#define pii pair<ll,ll>

#define mp make_pair

#define pb push_back

#define fi first

#define se second

typedef vector<vector<ll> > mat;

const ll mx=100001;

const ll mod=1000000007;

const ll inf=0x3f3f3f3f;

//ifstream in("input.txt");

//ofstream out("output.txt");

void solve();

int main()

{

  int t=1;

//  cin>>t;

  rep(i,1,t)

  {

    solve();

  }

  return 0;

}

string a[40];

char b[40];

int n,q;

int sol(char l,int sz)

{

    if(sz==n-1) 

        return 1;

    int res=0;

    for(int i=0;i<q;i++)

        if(b[i]==l)

        {

            res+=sol(a[i][0],sz+1);

        }

    return res;

}

void solve()

{

   cin>>n>>q;

    for(int i=0;i<q;i++)

    {

        cin>>a[i]>>b[i];        

    }

    cout<<sol('a',0);

}