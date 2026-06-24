#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+26;
int T,n,a[2][maxn];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%1d",&a[0][i]);
        for(int i=1;i<=n;i++)
            scanf("%1d",&a[1][i]);
        for(int i=1,j;i<=n;i++){
            printf("%d",a[0][i]);
            if(a[1][i]<a[0][i+1]||i==n){
                for(j=i;j<=n;j++)
                    printf("%d",a[1][j]);
                puts("");
                for(j=i-1;j>=1;j--)
                    if(a[1][j]!=a[0][j+1])
                        break;
                printf("%d\n",i-j);
                break;
            }
        }
    }
    return 0;
}