//ABHIKANT SINGH
     
 #include<bits/stdc++.h>
 using namespace std;
  
  
  #include<ext/pb_ds/assoc_container.hpp>
  #include<ext/pb_ds/tree_policy.hpp>
  using namespace __gnu_pbds;
  
  typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;    // find_by_order, order_of_key
  // to contain duplicate value in pbds change ( less  --> less_equal)
  
  
    #include<stdio.h>
    #define int         long long int                              //sometime it give TLE/MLE.
    #define f(i,a,b)    for(int i=a;i<(b);++i)
    #define fr(i,a,b)   for(int i=a;i>=b;i--)
    #define pb          push_back
    #define ppb         pop_back
    #define pii         pair<int,int>
    #define ff          first
    #define ss          second
    #define MOD         1000000007
    #define PI          3.141592653589793238462
    #define INF         1e18
    #define INT         -1e18
    #define set_bits    __builtin_popcountll
    #define trail_zeros(x)    __builtin_ctzll(x)         //16=00000....000110100 this fn return 2(there is 2 trailing zeros)
    #define lead_zeros(x)     __builtin_clzll(x)          //this fn return 58(there is 58 leading zeros for 64 bits)
    #define sz(x)             ((int)(x).size())
    #define all(x)            (x).begin(),(x).end()
    #define endl              "\n"
    #define setpr(x)          setprecision(x)<<fixed
    #define print(v)          {for(auto x : v) cout << x << " "; cout << endl;}
    #define print1(v)         for(auto x : v) cout << x.ff << " " << x.ss << endl;
    #define p(n)              cout<<n<<endl;
    typedef long long ll;
  
  
  /*-------------------------------------------------------------------------------------------------------------------------*/
  ll gcd(ll a, ll b){if(b > a){return gcd(b, a);} if(b == 0){return a;} return gcd(b, a % b);}
  ll modpow(ll a,ll b){ll res = 1; while(b>0){if(b&1)res=(res*a)%MOD; a=(a*a)%MOD; b=b>>1;} return res;}        
  ll mod_add(ll a,ll b){return ((a%MOD) + (b%MOD))%MOD;}
  ll mod_sub(ll a,ll b){return ((a%MOD) - (b%MOD) + MOD)%MOD;}
  ll mod_mul(ll a,ll b){return ((a%MOD) * (b%MOD))%MOD;}
  ll mod_div(ll a,ll b){return ((a%MOD) * modpow(b,MOD-2))%MOD;}
  ll power(ll a,ll b){ll res = 1; while(b>0){if(b&1)res=(res*a);  if(b>1)a=(a*a);  b=b>>1;} return res;}
  bool comp(pair<ll,ll>&q,pair<ll,ll>&q1){return (q.ss>q1.ss);}                                    //decreasing order;
  int msb_pos(int n){int ans=0; while(n){ans++; n>>=1;} return (ans-1);}
  const int N=2e5+2;
  ll fact[N],invfact[N];
  void facti(){fact[0]=1; f(i,1,N){fact[i]=(i*fact[i-1])%MOD;} invfact[N-1]=modpow(fact[N-1],MOD-2); for(int i=N-2;i>=0;i--){invfact[i]=invfact[i+1]*(i+1)%MOD;}}
  ll ncr(ll n, ll r){if(r>n || n<0 || r<0)return 0;  return ((fact[n]*invfact[r])%MOD*invfact[n-r]%MOD)%MOD;} 
  int spf[N+1];
  vector<int> prime;
  void sieve(){ for(int i=2; i <= N; ++i){if(spf[i] == 0){spf[i] = i;  prime.push_back(i);} for(int j = 0; (i * prime[j]) <= N; ++j){spf[i*prime[j]] = prime[j];  if(prime[j] == spf[i]) break;}}}
  vector<pair<ll,ll>> prime_fact(int n){vector<pair<ll,ll>> res; while(n > 1){ ll cnt = 0;  ll f = spf[n];  while(n%f == 0){cnt++;  n /= f;}  if(cnt > 0) res.pb({f , cnt}); } return res; }
  bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
  /*-------------------------------------------------------------------------------------------------------------------------*/
   


int prefix_count[65][N];



void findPrefixCount(vector<int>arr, int n){

     for (int i = 0; i < 64; i++) {

          // Loop to find prefix count
          prefix_count[i][0] = ((arr[0] >> i) & 1);
          for (int j = 1; j < n; j++) {
               prefix_count[i][j] = ((arr[j] >> i) & 1);
               prefix_count[i][j] += prefix_count[i][j - 1];
          }
     }
}


int rangeAnd(int l, int r){


     // To store the answer
     int ans = 0;

     // Loop for each bit
     for (int i = 0; i < 64; i++) {
          // To store the number of variables
          // with ith bit set
          int x;
          if (l == 0)
               x = prefix_count[i][r];
          else
               x = prefix_count[i][r]
                    - prefix_count[i][l - 1];

          // Condition for ith bit
          // of answer to be set
          if (x == r - l + 1)
               ans = (ans | (1 << i));
     }

     return ans;
}
 
  
  
  

  
     void solve(){

            int n;  cin>>n;
            vector<int>v(n);
            f(i,0,n) cin>>v[i];

            findPrefixCount(v , n);
              
            int q;   cin>>q;

            while(q--){
                int l,k;  cin>>l>>k;

                int ans = -1;
                if(v[l - 1] < k) {cout<<-1<<" ";  continue; }
                l--;

                int low = l , high = n - 1;
                while(low <= high){

                       int mid = low + (high - low)/2;

                       if(rangeAnd(l , mid) >= k){ans = mid;  low = mid + 1; }
                       else high = mid - 1;
                  }

                  cout<<ans + 1<<" ";
             }

             cout<<endl;

  
  
  
     }
  





    
      
      int32_t main(){
  
      ios_base::sync_with_stdio(0); 
            cin.tie(0); 
            cout.tie(0); 
  
      //facti();
      //sieve();
  
         int t=1; 
           cin>>t;
         while(t--){
           solve();
         }
           return 0;
      }
    
      
  
    //vector<pii>v(n,{1,1});
    //string s = to_string(10000);
    // int x = stoi(s);