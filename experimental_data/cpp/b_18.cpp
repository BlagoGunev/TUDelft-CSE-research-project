#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long i64;

int main() {
    int n,d,m,l;
    while(scanf("%d%d%d%d",&n,&d,&m,&l)!=EOF) {
        i64 ans=0;
        bool fin=false;
        if(m>l+1) {
            int k=0;
            while(k<n-1) {
                i64 a=(i64)k*m;
                i64 b=a+(i64)(l+1);
                i64 e=a+(i64)(m-1);
                i64 tmp=b/(i64)d;
                ans=tmp*(i64)d;
                while(ans<b) ans+=(i64)d;
                if(ans<=e) break;
                k++;   
            }
            if(k<n-1) {
                fin=true;
                printf("%lld\n",ans);
            }
        }
        if(!fin) {     
            i64 a=(i64)(n-1)*(i64)m+(i64)l;
            i64 tmp=a/(i64)d;
            ans=tmp*(i64)d;
            while(ans<=a) ans+=(i64)d;       
            printf("%lld\n",ans);
        }
    }
    //system("pause");
    return 0;
}