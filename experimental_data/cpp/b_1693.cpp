#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> // Common file

#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

#include <ext/pb_ds/detail/standard_policies.hpp>



using namespace std;

using namespace __gnu_pbds;



typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef tree<pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_multi_set;

typedef tree<int , int, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_map;



// ord_set.find_by_order(1) --> returns an iterator to the k-th largest element (counting from zero)

// ord_set.order_of_key(3) --> returns the number of items in a set that are strictly smaller than our item



typedef long long ll; 

typedef long double ld;

typedef pair<int, int> pi; 

typedef pair<ll, ll> pl; 

typedef pair<string, string> pss; 

typedef vector<int> vi; 

typedef vector<vi> vvi; 

typedef vector<pi> vpi;

typedef vector<pl> vpl;

typedef vector<ll> vl; 

typedef vector<vl> vvl; 

typedef map<int,int > mpi;

typedef queue<int> qi;

typedef priority_queue<int> pqi;

typedef priority_queue <int, vector<int>, greater<int>> minpq;



#define ff first

#define ss second

#define pb push_back

#define mkp make_pair

#define endline "\n"

#define print(a,b) cout<<a<<" "<<b<<" "

#define println(a,b) cout<<a<<" "<<b<<endl



#define mod 1000000007

#define mxN 10000000

#define all(v) v.begin(),v.end() 

#define rall(v) v.rbegin(),v.rend() 

#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)





// int uint64_log10(uint64_t n)

// {

//   #define S(k, m) if (n >= UINT64_C(m)) { i += k; n /= UINT64_C(m); }



//   int i = -(n == 0);

//   S(16,10000000000000000); S(8,100000000); S(4,10000); S(2,100); S(1,10);

//   return i;



//   #undef S

// }



// int uint64_log2(uint64_t n)

// {

//   #define S(k) if (n >= (UINT64_C(1) << k)) { i += k; n >>= k; }



//   int i = -(n == 0); S(32); S(16); S(8); S(4); S(2); S(1); return i;



//   #undef S

// }





// ll fact[mxN];

// void factorial() {

//   fact[0] = 1 ;

//   for(ll i = 1;i< mxN;++i) 

//     fact[i] = ( i * fact[i-1] ) % mod ;

// }



ll power(int a,int b) {

  a %= mod ; 

  if(b == 0 ) return 1;

  ll p = power(a,b/2) % mod ;

  p = p * p % mod ;

  return b & 1 ? p * a % mod : p ; 

}



ll invMod(ll a) {

  return power(a,mod-2) % mod ;

}

int gcd(int a, int b) {

  if (a < b)swap(a, b);

  while (b) {

    int r = a % b; a = b; b = r;

  }

  return a;

}



// ll ncr(int n, int k) { 

//     ll res = 1; 

  

//     if (k > n - k) 

//         k = n - k; 

  

//     for (int i = 0; i < k; ++i) { 

//         res = (res* (n - i))%mod; 



//         res = (res *invMod(i+1))%mod;

//     } 

  

//     return res; 

// } 





void prt(vi v){

  for (int i=0;i<v.size();i++){

    cout<<v[i]<<" ";

  }

  cout<<endl;

}



void prt2d(vvi v){

  for (int i=0;i<v.size();i++){



    for(int j=0;j<v[0].size();j++)

       cout<<v[i][j]<<" ";

    cout<<endl;

  }

}



vi graph[200005];

ll l[200005],r[200005];

ll operations;



ll dfs(int curr){

  ll opr=0;

  for(auto ch: graph[curr]){

     ll x=dfs(ch);

     //cout<<"ch: "<<ch<<" "<<x<<endl;

     opr+=x;

  }

  if(opr<l[curr]){

    operations++;

    return r[curr];

  }

  else return min(r[curr],opr);

}

void solve(){

  ll i,j,n,m,p;

  cin>>n;

  

  operations=0;

  for(i=2;i<=n;i++){

    cin>>p;

    graph[p].pb(i);

  }



  for(i=1;i<=n;i++){

    cin>>l[i]>>r[i];

  }

  

  dfs(1);

  cout<<operations<<endl;

  for(i=1;i<=n;i++)graph[i].clear();



}







//bool compare( int a[2], int b[2]) { return (a[1]<=a[1]) ; }

int main(){

  fio;

  #ifndef ONLINE_JUDGE

     freopen("input.txt","r", stdin);

     freopen("output.txt","w", stdout);

    #endif

   

   int i,j,t=1;

   cin>>t;



   while(t--){

     solve();

   }

   

   return 0;

}