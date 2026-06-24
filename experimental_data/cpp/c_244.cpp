#include<bits/stdc++.h>

using namespace std;

void scanint(int &x){

    register int c=getchar();

    x=0;

    bool neg=0;

    for(;((c<48||c>57)&&c!='-');

    c=getchar());

    if(c=='-'){

        neg=1;

        c=getchar();

    }

    for(;c>47&&c<58;c=getchar())

        x=(x<<1)+(x<<3)+c-48;

    if(neg)

        x=-x;

}

bool b[1050000];

int a[100005];

int main(){

    memset(b,0,sizeof b);

    int n,i,j,x;

    scanint(n);

    for(i=0;i<n;i++){

        scanint(a[i]);

        b[a[i]]=1;

        for(x=0,j=i-1;j>=0&&(~x&a[i]);j--){

            x|=a[j];

            b[x|a[i]]=1;

        }

    }

    for(x=0,i=0;i<1050000;i++)

        x+=b[i];

    printf("%d",x);

}