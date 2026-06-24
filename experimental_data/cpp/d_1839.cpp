#include    <bits/stdc++.h>
using       namespace   std;
#define     int   long long
#define     ll    long long int 
#define     pll   pair <ll,ll> 
#define     vll   vector <ll> 
#define     vpl   vector <pll> 
#define     ld    long double
#define     s     second 
#define     f     first 
#define     REP(i,a,b)     for(int i=int(a);i<int(b);i++)
#define     RREP(i,a,b)    for(int i=int(a);i>int(b);i--)
int mod     =              998244353 ; 
int inf     =              1e18;
#define     all(a)         a.begin() , a.end()
#define     allr(a)        a.rbegin() , a.rend()
#define     IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     out(a)         cout << #a << " = " << a <<endl
#define     out2(a,b)      cout<< #a << "[" << b << "]" << " = " << a[b] << endl;
#define     outp(a)        cout << #a << " first = " << a.first << "  second = " << a.second << endl
auto seed   =              chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937               mt(seed);
int myrand(int mod)        { return (int) ( (((double) rand() / RAND_MAX) * (mod) )); }
////////////////////////////////////////////////////////////////////////////////////////////////


const int N = 500 ; 
int dp[N + 1][N + 1] , arr[N + 10] ; 

int ad(int a , int b)
{
   if(min(a , b) ==  - inf)return  - inf ; 
   return a + b ; 
}

int f(int idx , int seg)
{
   if(idx < 0)return  - inf ; 
   if(seg < 0)return  - inf ; 
   if(idx == 0) return 0 ; 
   int  & ans =  dp[idx][seg] ; 
   if(ans != -1)return ans ; 
   return 0 ; 
}

int n ; 
void f2()
{
   for(int idx = 1 ; idx <= n ; idx ++ )
      for(int seg = 0 ; seg <= n ; seg ++ )
      {
         int  & ans =  dp[idx][seg] ; 
         ans =  - inf ; 
         if(arr[idx-1] <= arr[idx])
            ans = ad(f(idx-1 , seg) , 1) ; 

         for(int i = idx-2 ; i >= 0 ; i -= 1)
         {
            if(arr[i] <= arr[idx])
            {
               ans = max(ans , ad(f(i , seg-1) , 1)) ; 
            }
         }
      }
}
   
int solve()
{
   cin >> n ;
   for(int i = 0 ; i <= n ; i += 1)
      for(int j = 0 ; j <= n ; j += 1)
         dp[i][j] = -1 ; 

   for(int i = 1 ; i <= n ; i += 1)
      cin >> arr[i] ; 

   f2() ; 
   for(int i = 1 ; i <= n ; i += 1)
   {
      int ans = f(n , i) ; 
      for(int j = 1 ; j <= n-1 ; j += 1)
         ans = max(ans , f(j , i-1)) ; 
      cout <<  n - ans << " " ; 
   }
   cout << endl ; 


   return 0 ; 
}




int32_t main()
{
   IOS ; 
   #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
   #endif
   int test=1;
   cin>>test;
   for(int i=1;i<=test;i++)
   {
      solve() ; 
   }
   return 0;
}