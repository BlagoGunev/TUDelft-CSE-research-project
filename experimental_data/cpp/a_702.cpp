#include<bits/stdc++.h>

using namespace std;

void read(int &x){

    register int c=getchar();

    x=0;

    for(;c<48||c>57;c=getchar());

    for(;c>47&&c<58;c=getchar())

        x=(x<<1)+(x<<3)+c-48;

}

int main(){

    int n,a,b,c=1,d=1;

    read(n);read(b);

    --n;

    while(n--){

        read(a);

        if(a>b)

            c++;

        else{

            d=max(c,d);

            c=1;

        }

        b=a;

    }

    printf("%d",max(c,d));

}