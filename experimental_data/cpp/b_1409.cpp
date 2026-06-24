#include<bits/stdc++.h>
                                  using namespace std;
                                  #define pb push_back
                                  #define endl '\n'
                                  #define mod 1000000007
                                  #define forn(i, n) for (int i = 0; i < (int)(n); i++)
                                  #define REPa(i,b) for(int i=1;i<=b;i++)
                               #define REP(i,n) for(int i=0;i<n;i++)
                                  #define init(arr,value) memset(arr,value,sizeof(arr))
                                  #define test unsigned int tet;cin >> tet;while(tet--)
                                  #define sz(a) int((a).size())
                                  #define vi vector<int>
                                  typedef long long ll;
                                  typedef unsigned long long ull;
                                  typedef long double ld;
                                  typedef pair<int, int> pii;
                                  typedef pair<ll, ll> pll;
                                  #define sf scanf
                                  #define pf printf
                                  #define all(x) (x).begin(), (x).end()
                                  #define SUM(v) accumulate(all(v),ll(0))
                                  #define present(container, element) (container.find(element) != container.end())
                                     #define cpresent(container, element) (find(all(container),element) != container.end())
                                     int max(int a,float b){
                                         if(a>b)
                                           return a;
                                           return b;
                                     }
                                     ll gcd(ll a,ll b){
                                       if(a%b==0) return b;
                                       else
                                           return gcd(b,a%b);
                                       }
                                     ll lcm(ll a,ll b){
                                       return a*b/gcd(max(a,b),min(a,b));
                                       }
                                     bool sort_pair(pair<int,int>a,pair<int,int> b){
                                       return a.first>b.first;
                                      }
                                     bool sort_pair_(pair<int,int>a,pair<int,int>b){
                                       return a.second>b.second;
                             }
                                     ll power(ll a,ll n){
                                         ll res=1;
                                         while(n){
                                             if(n%2)n--,res*=a;
                                             n/=2;
                                             a=(a*a);
                                         }
                                         return res;
                                         
                                     }
                               int main(){
                                   
                                   int t;
                                   sf("%d",&t);
                                   while(t--){
                                       ll a,b,x,y,n;
                                       sf("%lld %lld %lld %lld %lld",&a,&b,&x,&y,&n);
                                       ll Mx=power(1LL*2,1LL*62);
                                       
                                       
                                       if((b-y)>=n&&a-x>=n)Mx=min(Mx,min(a*(b-n),b*(a-n)));
                                       
                                       if((a-x)>=n&&(b-y)<n){
                                           Mx=min(Mx,min((a-n)*b,(y*(a-(n-(b-y))))));
                                       }
                                       
                                       if((a-x)<n&&(b-y)>=n){
                                           Mx=min(Mx,min((b-n)*a,(x*(b-(n-(a-x))))));
                                       }
                                       
                                       if(a-x<n&&b-y<n){
                                           if(a+b-(x+y)<n)Mx=min(Mx,x*y);
                                           else
                                           Mx=min(Mx,min((x*(b-(n-(a-x)))),(y*(a-(n-(b-y))))));
                                       }
                                       pf("%lld\n",Mx);
                                       
                                       
                                   }
                                   
                                   
                               }