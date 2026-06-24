#include<bits/stdc++.h>
using namespace std;
ifstream fin("window.in");
ofstream fout("window.out");
long long n,m;
const long long mod=998244353,i2=499122177;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    bool a[n+5][2*m+5];
    long long h[n+5][2*m+5];
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=m;j++){
            char x;
            cin>>x;
            a[i][j]=(x=='1');
        }
    }
    for(long long i=1;i<=n;i++)for(long long j=1;j<m;j++)a[i][j+m]=a[i][j];
    for(long long i=1;i<=n;i++){
        h[i][2*m]=0;
        long long p(1);
        for(long long j=2*m-1;j>=1;j--){
            h[i][j]=h[i][j+1]+p*a[i][j];
            h[i][j]%=mod;
            p*=2;
            p%=mod;
        }
    }
    for(long long j=1;j<=m;j++){
        long long mx(1);
        for(long long i=2;i<=n;i++){
            long long st(j),dr(j+m-1),mij((st+dr)/2),r(j-1);
            while(st<=dr){
                long long h1(h[mx][j]-h[mx][mij+1]);
                h1+=mod;
                h1%=mod;
                long long h2(h[i][j]-h[i][mij+1]);
                h2+=mod;
                h2%=mod;
                if(h1==h2)r=mij,st=mij+1;
                else dr=mij-1;
                mij=(st+dr)/2;
            }
            if(!a[mx][r+1])mx=i;
        }
        cout<<mx<<" ";
    }
    return 0;
}