#include <bits/stdc++.h>
        using namespace std;
        typedef long long ll;
        typedef unsigned long long ull;
        # define M_PI  3.14159265358979323846
        ll k=1e9+7;  
        const int M=998244353;
        long long mod(long long x){
            return ((x%M + M)%M);
        }
        long long add(long long a, long long b){
            return mod(mod(a)+mod(b));
        }
        long long mul(long long a, long long b){
            return mod(mod(a)*mod(b));
        }
    
        ll modPow(ll a, ll b){
            if(b==0)
                return 1LL;
            if(b==1)
                return a%M;
            ll res=1;
            while(b){
                if(b%2==1)
                    res=mul(res,a);
                a=mul(a,a);
                b=b/2;
            }
            return res;
        }
 
 
       void solve(){
           int n;
           cin>>n;
           string s;
           cin>>s;
           map<char,ll>mp;
           ll m=0;
           for(auto &it:s){
               mp[it]++;
               m=max(m,mp[it]);
           }
           ll sum=0;
           if(m>n/2){
              for(auto&it:mp){
                  if(it.second<=n/2)
                  sum+=it.second;
              }
                  cout<<m-sum<<endl;
           }
           else
           cout<<n%2<<endl;
           }



        int main(){
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            cout<<fixed;
            cout<<setprecision(10);
            int t;
            cin>>t;
            for(int i=1;i<=t;i++){
            solve();
            }
            return 0;
        }