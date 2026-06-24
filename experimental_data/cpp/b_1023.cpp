#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout<<"["<<x<<"]"<<endl;
#define bug printf("***********\n");

void read(int &x){
    char ch = getchar();x = 0;
    for (; ch < '0' || ch > '9'; ch = getchar());
    for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
}

ll n,k;
ll t,flag,ans;

int main(){
    scanf("%lld %lld",&n,&k);

    t=k/2;
    if(k%2){
        flag=1;
    }else{
        flag=0;
    }

    if(t>n){
        ans=0;
    }else{
        if(flag)
            ans=min(t,n-t);
        else
            ans=min(t-1,n-t);

    }
    cout<<ans<<endl;;
    return 0;
}