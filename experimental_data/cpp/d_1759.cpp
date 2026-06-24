#include<bits/stdc++.h>

#define ll long long

#define endl "\n"

#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

void solve(){

ll n,nn,m,mm;

cin>>n>>m;

nn=n;

mm=m;

ll k =1;

ll cnt2=0,cnt5=0;

while(n%2==0){

    cnt2++;

    n >>=1;

}

while(n%5==0){

    cnt5++;

    n /= 5;

}

while(cnt2 < cnt5 && k*2<=m){

    cnt2++;

    k <<= 1;

}

while(cnt5 < cnt2 && k*5<=m){

    cnt5++;

    k*=5;

}

while(k*10<=m){

    k*=10;

}

if(k==1)

    cout<<nn*mm<<endl;

else{

    k *= m/k;

    cout<<k*nn<<endl;

}

}

int main(){

fast;

ll t;

cin>>t;

while(t--){

solve();

}

return 0;

}