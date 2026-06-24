#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;

// Debug
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// bool cmp(pair<int,int> a,pair<int,int> b)
// {
//     if(a.first!=b.first)
//     return a.first<b.first;

//     else 
//     return a.second>b.second;
// }

int main(){
    int t;
    cin>>t;
    while(t--){
        
        ll n;
        cin>>n;

        vector<ll> v(n);
        ll ans=0;
        ll op=0;

        f(i,0,n){
            cin>>v[i];
            ans+=abs(v[i]);
        }
        ll cnt=0;
        f(i,0,n){
            
            if(v[i]<=0){
                if(v[i] < 0)
                cnt++;
            }
            else{
                if(cnt>0){
                    op++;
                    cnt=0;
                }
            }
        }

               if(cnt>0){
                    op++;
                    cnt=0;
                }

        

        cout<<ans<<" "<<op<<endl;





    }
}