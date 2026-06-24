#include<cstdio>

#include<iostream>

#include<cstring>

using namespace std;

const int N=1100;

const int M=2200;

int aa[N];



int main(){

    #ifdef DouBi

    freopen("in.cpp","r",stdin);

    #endif // DouBi

    int n,m;

    while(scanf("%d%d",&n,&m)!=EOF){

        for(int i=1;i<=n;i++){

            scanf("%d",&aa[i]);

        }

        int sum=0;

        for(int i=0;i<m;i++){

            int a,b;scanf("%d%d",&a,&b);

            sum+=min(aa[a],aa[b]);

        }

        printf("%d\n",sum);

    }

    return 0;

}