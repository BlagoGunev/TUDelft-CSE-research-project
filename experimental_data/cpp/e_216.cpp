#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

typedef long long LL;
typedef double db;
#define mp make_pair
#define pb push_back
const db EPS = 1e-8;
const db PI = acos(- 1.0);

#define rep(i,n) for(int i=0;i<n;++i)

const int maxn = 100005;

map< int ,int > cc;
int k,b,n;
int a[ maxn ], tp[ maxn ];
typedef long long LL ;

int MOD(int a, int k) {
    a%=k;
    return a<0?a+k:a;
}

int main(){
    while(cin>>k>>b>>n) {
        for(int i=0;i<n;++i) scanf("%d", a + i), tp[i]=a[i];
        LL ans = 0 ;
        cc.clear();
        if(!b){
            LL ct = 0;
            for(int i=0;i<n;++i) {
                if(a[i]==0) {
                    ct = 0;
                    int j;
                    for(j=i;j<n;++j) if(a[j] != 0) break; else ++ ct;
                    ans += ct * (ct + 1) / 2;
                    i  = j - 1;
                }
            }
        }else {
            int tb = b;
            b%=k-1;
            for(int i=0;i<n;++i) a[i] %= k-1;
            int sum = 0;
            ++ cc[ 0 ];
            for(int i=0;i<n;++i) {
                sum += a[i];
                sum %= k-1;
                //cout <<"sum = " << sum << endl;
                int j = MOD(sum-b,k-1);
                if(cc.find(j) != cc.end())
                    ans += cc [ j];
                ++ cc[ sum ];
            }
            if(tb==k-1) {
                LL ct = 0;
                for(int i=0;i<n;++i) a[i]=tp[i];
                for(int i=0;i<n;++i) {
                    if(a[i]==0) {
                        ct = 0;
                        int j;
                        for(j=i;j<n;++j) if(a[j] != 0) break; else ++ ct;
                        //cout <<"ct = " << ct << endl;
                        ans -= ct * (ct + 1) / 2;
                        i  = j - 1;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
 10 5 6
 3 2 0 5 6 1
 7 6 4
 3 5 0 4
 257 0 3
 0 0 256
 */