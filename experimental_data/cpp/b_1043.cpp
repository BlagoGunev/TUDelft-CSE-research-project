#include<bits/stdc++.h>
using namespace std;

const int N=1e3+3;
typedef long long ll;
const ll base=1e9+7;
ll Pow[N],Hash[N];
int n,a[N];
vector<int> ans;

ll Get(int i, int j){
    return Hash[j]-Hash[i-1]*Pow[j-i+1];
}

int main(){
    cin>>n;
    for (int i=1; i<=n; ++i)
        cin>>a[i];
    for (int i=n; i>0; --i)
        a[i]-=a[i-1];
    Pow[0]=1;
    for (int i=1; i<=n; ++i)
        Pow[i]=Pow[i-1]*base;
    for (int i=1; i<=n; ++i)
        Hash[i]=Hash[i-1]*base+a[i];
    bool okey;
    for (int k=1; k<=n; ++k){
        okey=1;
        for (int j=k; j<=n; j+=k)
        if (Hash[k]!=Get(j-k+1,j)){
            okey=0;
            break;
        }
        if (Hash[n%k]!=Get(n-n%k+1,n)) okey=0;
        if (okey) ans.push_back(k);
    }
    cout<<ans.size()<<'\n';
    for (int x:ans) cout<<x<<' ';
    
}