/* Don't try to hack it :|
 
            _/﹋\_
            (҂`_´)
            <,︻╦╤─҉- - - - - - - - - - - - - - -
            _/﹋\_
*/
//@Tushar Mhaske

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define F first
#define S second
#define all(c)  c.begin(), c.end()
#define ulli unsigned long long int
#define lli long long int
#define llv vector< ll >
#define llc vector< char >
#define lls vector< string >
#define llb vector< bool >
#define mp make_pair
#define endl "\n"
#define degb cout<<"HI"<<endl;
#define ins insert
#define foo(i,n) for(ll i = 0;i<n;i++)
#define foa(i,a) for(auto i = a.begin();i!=a.end();i++)
#define foe(i,a,b) for(ll i = a;i<=b;i++)
#define INF 2147483647
#define siz size
#define len length
#define sp setprecision(16)
#define mod 1000000007

lli powr(ll a,ll b){   /*power(a,b) by modular exponentiation*/
  if(b==0){
    return 1;
  }
  if(b%2==0){
    return powr(((a%mod)*(a%mod))%mod,b/2);
  }
  else{
    if(b==1){
      return a;
    }
    else{
      return (a*powr(((a%mod)*(a%mod)%mod),(b-1)/2))%mod;
    }
  }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int q;
    cin>>q;
    foo(z,q){
        ll n;
        cin>>n;
        ll a[n];
        ll b[n+1];
        ll x[n+1];
        x[n] = 0;
        foo(i,n){
            x[i] = 0;
            cin>>a[i];
            b[a[i]] = i+1;
        }
        ll pos;
        for(ll i = 1;i<=n;i++){
            if(a[i-1]==i){
                x[i-1] = 1;
                continue;
            }
            pos = b[i]-1;

            //cout<<b[2]<<" ";
            ll cnt = 0;
            for(ll j = pos-1;j>=0;j--){
                if(x[j]==1&&j+1==pos){
                    x[pos] = 1;
                    break;
                }
                if(x[j]==0){
                    cnt++;
                   // cout<<j<<" ";
                    swap(a[j],a[j+1]);
                    b[a[j]]--;
                    b[a[j+1]]++;
                    x[j] = 1;
                }
                else{
                    break;
                }
            }

           // cout<<b[2]<<" ";
        }
        foo(i,n){
            cout<<a[i]<<" ";

        }
        cout<<endl;
    }  
 
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
 
     
    return 0;
}