#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;
typedef long long LL;
int m,n;
int pos[100],mark[100];
int dy[4]={-1,0,1,0},dx[4]={0,-1,0,1};
int g[100][100];
bool trav(int t){
    int i,j;
    if(t==m*n+1){
        printf("YES\n");
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                printf("%d%c",pos[(i-1)*m+j],j==m?'\n':' ');
            }
        }
        return true;
    }
    int c,r,l,k;
    c=t%m;
    if(c==0) c=m;
    r=(t-1)/m+1;
    int ny,nx;
    for(l=1;l<=m*n;l++){
        if(mark[l]==true) continue;
        bool fail=false;
        for(k=0;k<4;k++){
            ny=r+dy[k],nx=c+dx[k];
            if(ny>=1&&ny<=n&&nx>=1&&nx<=m&&pos[(ny-1)*m+nx]!=-1&&g[l][pos[(ny-1)*m+nx]]==true){
                fail=true;
                break;
            }
        }
        if(!fail){
            pos[t]=l;
            mark[l]=true;
            if(trav(t+1)) return true;
            pos[t]=-1;
            mark[l]=false;
        }
    }
    return false;
}
int main(){
    int i,j,k,l;
    scanf("%d %d",&n,&m);
    if(n>=5||m>=5){
        printf("YES\n");
        if(m>=5){
            for(i=1;i<=n;i++){
                if(i&1){
                    for(j=2;j<=m;j+=2){
                        printf("%d ",j+(i-1)*m);
                    }
                    for(j=1;j<=m;j+=2){
                        printf("%d%c",j+(i-1)*m,j+2>m?'\n':' ');
                    }
                }else{
                    for(j=4;j<=m;j+=2){
                        printf("%d ",j+(i-1)*m);
                    }
                    for(j=1;j<=m;j+=2){
                        printf("%d ",j+(i-1)*m);
                    }
                    printf("%d\n",2+(i-1)*m);
                }
            }
        }else{
            k=2,l=4;
            for(i=1;i<=n;i++){
                for(j=1;j<=m;j++){
                    if(j&1){
                        printf("%d%c",(k-1)*m+j,j==m?'\n':' ');
                    }else{
                        printf("%d%c",(l-1)*m+j,j==m?'\n':' ');
                    }
                }
                k+=2;
                if(k>n){
                    if(k&1) k=2;
                    else k=1;
                }
                l+=2;
                if(l>n){
                    if(l&1) l=2;
                    else l=1;
                }
            }
        }
    }else if(n==4&&m==4){
        printf("YES\n");
        printf("6 8 5 7\n");
        printf("14 16 13 15\n");
        printf("2 4 1 3\n");
        printf("10 12 9 11\n");
    }else{
        bool suc=true;
        int mx=max(m,n),mn=min(m,n);
        if(mx==2&&mn==1) suc=false;
        if(mx==3&&mn==1) suc=false;
        if(mx==2&&mn==2) suc=false;
        if(mx==3&&mn==2) suc=false;
        if(!suc){
            printf("NO\n");
        }else{
            printf("YES\n");
            if(n==1&&m==1){
                printf("1\n");
            }else if(n==3&&m==3){
                printf("1 3 4\n");
                printf("5 7 6\n");
                printf("9 2 8\n");
            }else if(n==1&&m==4){
                printf("2 4 1 3\n");
            }else if(m==1&&n==4){
                printf("2\n4\n1\n3\n");
            }else if(n==4&&m==2){
                printf("1 4\n5 8\n2 3\n6 7\n");
            }else if(n==4&&m==3){
                printf("1 3 4\n5 7 2\n11 6 8\n9 10 12\n");
            }else if(n==2&&m==4){
                printf("1 3 5 2\n8 6 4 7\n");
            }else if(n==3&&m==4){
                printf("1 3 5 2\n4 6 12 9\n11 8 10 7\n");
            }
        }
            
        
        /*
        for(i=1;i<=m*n;i++){
            for(j=1;j<=m*n;j++){
                g[i][j]=false;
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                for(k=0;k<4;k++){
                    int ni,nj;
                    ni=i+dy[k],nj=j+dx[k];
                    if(ni>=1&&ni<=n&&nj>=1&&nj<=m)
                        g[(i-1)*m+j][(ni-1)*m+nj]=true;
                }
            }
        }
        for(i=1;i<=m*n;i++) mark[i]=false,pos[i]=-1;
        if(!trav(1)) printf("NO\n");
        */
    }
    return 0;
}