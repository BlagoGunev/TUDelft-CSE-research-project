/*

ID: CaoLei

PROG: b.cpp

LANG: C++

*/



#include <cstdio>

#include <iostream>

#include <cstring>

#include <algorithm>

#include <set>

#include <queue>

#include <map>

#include <cmath>

#include <vector>

using namespace std;

#define N 500010

#define pi acos(-1.0)

#define inf 0x3f3f3f3f

#define pb(x) push_back((x))

typedef long long ll;

typedef unsigned long long ull;



ll g[6][6];

int a[5]={1,2,3,4,5};

int main(){

    while(~scanf("%I64d%I64d%I64d%I64d%I64d",&g[1][1],&g[1][2],&g[1][3],&g[1][4],&g[1][5])){

        for(int i=2;i<=5;i++){

            for(int j=1;j<=5;j++){

                scanf("%I64d",&g[i][j]);

            }

        }

        ll ans=0,tmp=0;

        do{

            tmp=0;

            for(int i=0;i<4;i++){

               // printf("%d ",a[i]);

                int pre=i+1;

                for(int j=i;j<4;j+=2,pre=j+1){

                    tmp+=(g[a[j]][a[pre]]+g[a[pre]][a[j]]);

                }

            }

            ans=max(tmp,ans);

            //printf("\n");

        }while(next_permutation(a,a+5));

        cout<<ans<<endl;

    }

    return 0;

}