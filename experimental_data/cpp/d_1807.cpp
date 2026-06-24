#include<bits/stdc++.h>
    using namespace std;
 
 
 #include<ext/pb_ds/assoc_container.hpp>
 #include<ext/pb_ds/tree_policy.hpp>
 using namespace __gnu_pbds;
 
 typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;  // find_by_order, order_of_key
 // to contain duplicate value in pbds change ( less  --> less_equal)
 
 
   #include<stdio.h>
   #define int         long long int                              //sometime it cause TLE/MLE.
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
 
 
 /*------------------------------------------------------------------------------------*/
 ll gcd(ll a, ll b){if(b > a){return gcd(b, a);} if(b == 0){return a;} return gcd(b, a % b);}
 ll modpow(ll a,ll b){ll res = 1; while(b>0){if(b&1)res=(res*a)%MOD; a=(a*a)%MOD; b=b>>1;} return res;}        
 ll mod_add(ll a,ll b){return ((a%MOD) + (b%MOD))%MOD;}
 ll mod_sub(ll a,ll b){return ((a%MOD) - (b%MOD) + MOD)%MOD;}
 ll mod_mul(ll a,ll b){return ((a%MOD) * (b%MOD))%MOD;}
 ll mod_div(ll a,ll b){return ((a%MOD) * modpow(b,MOD-2))%MOD;}
 ll power(ll a,ll b){ll res = 1; while(b>0){if(b&1)res=(res*a);  if(b>1)a=(a*a);  b=b>>1;} return res;}
 bool comp(pair<ll,ll>q,pair<ll,ll>q1){return (q.ss>q1.ss);}                                    //decreasing order;
 int msb_pos(int n){int ans=0; while(n){ans++; n>>=1;} return (ans-1);}
 const int N=2e5+4;
 ll fact[N],invfact[N];
 void facti(){fact[0]=1; f(i,1,N){fact[i]=(i*fact[i-1])%MOD;} invfact[N-1]=modpow(fact[N-1],MOD-2); for(int i=N-2;i>=0;i--){invfact[i]=invfact[i+1]*(i+1)%MOD;}}
 ll ncr(ll n, ll r){if(r>n || n<0 || r<0)return 0;  return ((fact[n]*invfact[r])%MOD*invfact[n-r]%MOD)%MOD;} 
 vector<ll> sieve(ll n){ll*arr = new ll[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
  /*-----------------------------------------------------------------------------------------*/
  
  /*------------------------------------------------------------------------------------*/
 bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
 string decToBinary(ll n){string s="";ll i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
 ll binaryToDecimal(string n){string num = n;ll dec_value = 0;ll base = 1;ll len = num.length();for(int i = len - 1; i >= 0; i--){if(num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
 vector<pair<ll,ll>>prime_fact; 
 void pr_ft(ll n){for(int i = 2;i*i<=n;i++){ll cnt=0; while(n%i==0){cnt++; n/=i;} if(cnt>0)prime_fact.pb({i,cnt});}if(n>1) prime_fact.pb({n,1});}
  /*------------------------------------------------------------------------------------*/
  
  
 
 
 
 
 
 
    void solve(){

       int n,q;     cin>>n>>q;

       vector<int>v(n);
       f(i,0,n) cin>>v[i];

     
        vector<int>prefix(n);
        prefix[0] = v[0];

        f(i,1,n){prefix[i] = prefix[i-1] + v[i];}


        while(q--){

            int l,r,k;   cin>>l>>r>>k;

              l--;
              r--;

              int sum = (prefix[n-1] - prefix[r] + (l - r + 1)*1LL*k);

              if(l > 0) sum += prefix[l - 1];
              

              if(sum%2){cout<<"YES"<<endl;}
              else cout<<"NO"<<endl;


            }



 
 
 
 
 
 
 
 
 
 
 
    }
 
   
     
     int32_t main(){
 
     ios_base::sync_with_stdio(0); 
           cin.tie(0); 
           cout.tie(0); 
 
     //facti(); 
     //pr_ft(n);
 
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
 
     // pbds A;               
     //cout << "0th element: " << *A.find_by_order(0) << endl;
     //cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl;
      //A.erase(1);   // remove all 1 from set only is case of less(if set contain unique value); if there is less_equal then,to remove an element we have to put address of that element;