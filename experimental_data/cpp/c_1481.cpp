#include <bits/stdc++.h>

#include <cstdio>

using namespace std;

/*#include <ext/pb_ds/assoc_container.hpp>

#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ordered_set tree<pair<long long,long long>, null_type,less<pair<long long,long long> >, rb_tree_tag,tree_order_statistics_node_update>*/

template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};

template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};

long long modu=998244353;

#define mod1   998244353

#define mod2   1000000007

#define first_bit(x) (x&(-x))

#define last_bit(x) (x&~(-x))

#define int  long long

#define ff    first

#define ss    second

#define pb    push_back

#define w(x)  long long x;cin>>x;while(x--)

#define vi    vector<long long> 

#define mii   map<long long,long long>

#define pii   pair<long long,long long>

#define set_bits __builtin_popcountll

#define fast()   ios_base::sync_with_stdio(false);cin.tie(NULL);

#define sz(x) ((long long)x.size())

#define all(x) begin(x), end(x)

#define memo(x,y) memset((x),(y),sizeof((x)))

signed main(){

 fast()

  w(t){

   int n,m;

   cin>>n>>m;

   int col[n];

   for(int i=0;i<n;i++)cin>>col[i];

   int req[n];

   for(int i=0;i<n;i++)cin>>req[i];

   int ptr[m];

   for(int i=0;i<m;i++)cin>>ptr[i];

   vector<int> amb[n+1];

   for(int i=0;i<n;i++)if(col[i]!=req[i])amb[req[i]].push_back(i);

   vector<int> ans(m,-1);

   for(int i=0;i<m;i++)if(amb[ptr[i]].size()){

    ans[i]=amb[ptr[i]][amb[ptr[i]].size()-1];

    amb[ptr[i]].pop_back();

   }

   int idx[n+1]={0};

   for(int i=0;i<n;i++)idx[req[i]]=i+1;

   for(int i=0;i<m;i++)if(ans[i]==-1&&idx[ptr[i]])ans[i]=idx[ptr[i]]-1;

   int las_idx=0;

   for(int i=0;i<m;i++)if(ans[i]!=-1)las_idx=i;

   bool pass=true;

   for(int i=0;i<m;i++)if(ans[i]==-1&&las_idx<i)pass=false;

   for(int i=0;i<=n;i++)if(amb[i].size())pass=false;

   if(pass){

    cout<<"YES"<<endl;

    for(int i=0;i<m;i++){

      if(ans[i]!=-1)cout<<ans[i]+1<<" ";

      else cout<<ans[las_idx]+1<<" ";

    }

    cout<<endl;

   }

   else cout<<"NO"<<endl;

  }

}