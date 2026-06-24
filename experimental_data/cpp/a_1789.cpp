#include "bits/stdc++.h"
 
using namespace std;

typedef int ll;
typedef pair<ll,ll>pairll;
typedef pair<ll,pairll>pair3l;
typedef long double ld;

#define fr first
#define sc second
#define pb push_back
#define endl '\n'
#define N 100007
#define MOD 998244353
#define INF 100000007
//#define A 60

ll t,n,d[107];

int main(){
    
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>d[i];
        }
        ll f=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                if(__gcd(d[i],d[j])<=2)f=1;
            }
        }
        if(f==0)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    
    
    return 0;
}