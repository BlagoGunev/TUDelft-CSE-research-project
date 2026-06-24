#include<bits/stdc++.h>
//#include <numeric>
using namespace std;
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
#define int long long 
#define all(v) v.begin(),v.end()
#define ll long long
#define endl '\n'
#define fi first
#define se second
#define forr(i, l, r) for (int i = l; i < r; i++)
#define sz(a) (int)a.size()
typedef vector<int> vi;
#define inf LLONG_MAX
#define YEYE ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int  INF = 1e14;
const int modulo = 1e9+7;
 
int gcd(int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}
int _gcd(int a,int b){
while (a&&b)a>b?a%=b:b%=a;
return a+b;}
// Function to return LCM of two numbers
int lcm(int a, int b)
{
  return (a / gcd(a, b)) * b;
}// string a[n]; string b[n];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int power(int x , int y) { 
  int res=1; 
  while(y) { 
    if(y%2){
        res = (res*x);
    }
    y/=2;
    x = (x*x); 
  } 
  return res; 
}

int helper(int x, int y) { 
    int res=1; 
    while (y) { 
      if(y%2){
        res = (res*x)%modulo;
      }
      y/=2;
      x = (x*x)%modulo;
    } 
    return res%modulo; 
}

void solve(){ 
  int n; cin>>n;
  int x=power(2,n)-2; 
  int ans=helper(4,x);
  ans=(ans*6)%modulo;
  cout<<ans<<endl;
} 
 
signed main(){
  YEYE;
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
   int t = 1; //cin>>t; //t++;
  //int i = 1;
  cout<<fixed<<setprecision(10);
  for(int i = 1;i<=t;i++){
    solve();
  //  if(state)
  //    cout<<"Case #"<<i<<": "<<ans<<endl;
  //  else{
  //    cout<<"Case #"<<i<<": "<<-1<<endl;
  //  }
  }
}