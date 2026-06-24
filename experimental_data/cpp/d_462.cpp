#include<bits/stdc++.h>

using namespace std;

void read(int &x){

    register int c=getchar();

    x=0;

    for(;c<48||c>57;c=getchar());

    for(;c>47&&c<58;c=getchar())

        x=(x<<1)+(x<<3)+c-48;

}

const int mod = 1e9+7;

long long f[100005][2];

int p[100005];

int main(){

    int n,i,x;

    read(n);

    for(i=1;i<n;++i)

        read(p[i]);

    for(i=0;i<n;++i)

        read(x),f[i][x]=1;

    for(i=n-1;i>0;--i){

        x=f[i][0]+f[i][1];

        f[p[i]][1]=(f[p[i]][1]*(long long)x+f[p[i]][0]*f[i][1])%mod;

        f[p[i]][0]=(f[p[i]][0]*(long long)x)%mod;

    }

    printf("%d",f[0][1]);

}