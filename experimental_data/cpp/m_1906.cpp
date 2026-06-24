#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define py cout << "YES" <<endl;
#define pn cout << "NO" <<endl; 
#define f(i,a,b) for (ll i=a;i<b;i++)
#define rf(i,a,b) for(ll i=b;i>=0;i--)
#define pb push_back
#define vl vector<ll>
#define vpl vector<pair<ll,ll>>
#define F first
#define S second
#define all(A) A.begin(), A.end()
#define nl cout<<endl;s
#define tk1(a) ll a; cin>>a;
#define tk2(a,b) ll a,b; cin>>a>>b;
#define tk3(a,b,c) ll a,b,c; cin>>a>>b>>c;
#define tk4(a,b,c,d) ll a,b,c,d; cin>>a>>b>>c>>d;
#define show(a,n) for(ll i=0;i<n;i++) {cout<<a[i]<<" ";} cout<<endl;
#define cina(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define cinv(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define N 1000000007


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    tk1(n);
    ll a[n];
    cina(a,n);
    sort(a,a+n);
    ll sum=0;
    ll lsum=0;
    f(i,0,n){
        sum+=a[i];
    }
    lsum=sum-a[n-1];
    if(a[n-1]>2*lsum){
        cout<<(lsum)<<endl;
    }
    else{
        cout<<sum/3<<endl;
    }

    return 0;
}