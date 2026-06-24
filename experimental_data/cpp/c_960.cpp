#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx=100005;
bool ans=true;
ll  x,d;
vector<ll>v;

void func(ll pre,ll x){
    if(v.size()>10000){
        ans=false;
        return ;
    }
    if(ans==false)return ;
    if(x==0) return ;
    if(x==1){
        v.push_back(pre+d+1);
        return ;
    }
    for(ll i=0;;i++){
        if(powl(2,i)-1>x){
            for(ll j=1;j<i;j++){
                v.push_back(pre+d+1);
            }
            func(pre+d+1,x-powl(2,i-1)+1);
            break;
        }
    }
}


int main(){
    //freopen("input.txt","r",stdin);
    scanf("%lld %lld",&x,&d);
    func(0,x);
    if(ans==false)printf("-1\n");
    else {
        printf("%lld\n",(ll)v.size());
        for(ll i=0;i<v.size();i++){
            printf("%lld ",v[i]);
        }
        printf("\n");

    }
}