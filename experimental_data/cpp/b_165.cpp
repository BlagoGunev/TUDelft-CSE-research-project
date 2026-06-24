#include <bits/stdc++.h>
#include<bits/stdc++.h>

using namespace std;

char f;

int u=1e9;

char show(int n,int k, int s){

    int64_t p=0,t=1;

    while(s/t>0){

        p+=s/t;

        t*=k;

    }

    f=(n==p ? '=': n>p? '<':'>');

    if(f=='=' || f=='>'){

        u=min(u,s);

    }

    return n==p ? '=': n>p? '<':'>';

}

int main(){

    int n,k,l=1,r=1e9,m=1;

    cin>>n>>k;

    while(show(n,k,m)!='='){

        if(r-l==1){

            show(n,k,l);

            show(n,k,r);

            break;

        }

        if(f=='>'){

            r=m;

            m=(m+l)>>1;

        }

        else {

            l=m;

            m=(m+r)>>1;

        }

    }

    cout<<u;

}