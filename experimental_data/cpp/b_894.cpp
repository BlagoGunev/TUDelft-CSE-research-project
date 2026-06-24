#include <bits/stdc++.h>

using namespace std;

#include<stdio.h>
#include<inttypes.h>
#define MOD 1000000007
int64_t mul(int64_t x,int64_t y){
    int64_t z;
    if(y==0)    return 1;
    if(y==1)    return x;
    z=mul(x,y/2);
    z*=z;
    z%=MOD;
    if(y%2) z*=x;
    z%=MOD;
    return z;
}
int main(){
    int64_t x,n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);
    if(k==-1 && (n+m)%2==1){
        printf("0\n");
        return 0;
    }
    x=2;
    x=mul(x,n-1);
    x=mul(x,m-1);
    printf("%lld\n",x);
    return 0;
}