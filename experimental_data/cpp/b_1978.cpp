#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(x) x.begin(),x.end()
#define vpii vector<pair<int,int>>
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef map<int,int> mii;
const int Prime1= 1000000007;
const int Prime2= 998244353;


long long binpow(long long a, long long b, long long m) {
 a %= m;
long long res = 1;
while (b > 0) {
if (b & 1){
res = res * a % m;}
a = a * a % m;
b >>= 1;
}
return res;
 }
 
 
vector<int> hp(int n){
vector<int>h(n,0) ;
for(int i=2;i<n;i++){
h[i]=i;
}
for( int i=2;i*i<n;i++){
if(h[i]==i){
for(int  j=i;j<n;j+=i){
h[j]=i;
}
}
}
return h;
}
 
 
 
 
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        int diff=b-a;
        if(diff<=0){
            cout<<n*a<<endl;
            continue;
        }
        int torem=diff-n;
        int todel= (torem*(torem+1))/2;
        if(torem<=0){
            todel=0;
        }

        int temp=(diff*(diff+1))/2-todel;
        cout<<n*a+temp<<endl;
    }

return 0;
}