#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int i,j,k,n,m,a[maxn][maxn];
int main(){
    int T;cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        if(n+m==2)puts("-1");
        else
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
                cout<<a[i][j]%(n*m)+1<<endl;
            puts("");
        }
    }
}