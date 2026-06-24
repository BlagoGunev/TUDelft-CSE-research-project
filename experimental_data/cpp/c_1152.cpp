#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<queue>
#include <stack>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<iomanip>
#include<math.h>
#include <cstdio>
//#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int large=1E9+7;

LL n,m;
LL gcd(LL a, LL b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void solve(){
    
    cin>>n>>m;
    if(n<m)
        swap(n,m);
    if(n%m==0){
        cout<<0<<endl;
    return;}
    LL tmp=n-m;
    
    LL ans=(m/tmp)*tmp;
    if(m%tmp)
        ans+=tmp;
    for(LL i=2;i*i<=tmp;i++){
        if(tmp%i==0){
            if(i>=m)
            ans=min(ans,i);
            if(tmp/i>=m)
            ans=min(ans,tmp/i);
        }
    }
    
    cout<< ans-m<<endl;
}
int main(){
    
    cin.sync_with_stdio(0);cin.tie(0);
    solve();
    
}