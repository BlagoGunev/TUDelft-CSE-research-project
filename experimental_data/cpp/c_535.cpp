#include<bits/stdc++.h>

using namespace std;

void read(long long &x){

    register int c=getchar();

    x=0;

    for(;c<48||c>57;c=getchar());

    for(;c>47&&c<58;c=getchar())

        x=(x<<1)+(x<<3)+c-48;

}

int main(){

    long long a,b,n,x,t,m,l,r,z;

    read(a);read(b);read(n);

    while(n--){

        read(x);read(t);read(m);

        x--;

        l=x;

        r=x+999999;

        while(l<=r){

            z=(l+r)/2;

            if(a+b*z>t||a*(z-x+1)+(z+x)*(z-x+1)/2*b>t*m)

                r=z-1;

            else

                l=z+1;

        }

        if(r<x)

            printf("-1\n");

        else

            printf("%I64d\n",r+1);

    }

}