#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF=2147483647;
const int mod=1e9+7;
int id_now,id1[9][9][9][9][9],id2[500][5];
int dp[500][500],qi[500][500];
queue<int> Q;
void build(){
    int _=id1[8][0][0][0][0];
    for(int i=0;i<id_now;i++) dp[_][i]=1,Q.push(_),Q.push(i);
    for(int i=0;i<id_now;i++) dp[i][_]=2,Q.push(i),Q.push(_);
    while(!Q.empty()){
        int x=Q.front();Q.pop();
        int y=Q.front();Q.pop();
        if(dp[x][y]==1){
            int a[5],b[5];
            for(int i=0;i<5;i++) a[i]=id2[x][i],b[i]=id2[y][i];
            for(int i=1;i<5;i++) if(a[i]){
                    for(int j=0;j<5;j++) if(b[j] && (j!=i)){
                            b[j]--,b[(j-i+5)%5]++;
                            if((!dp[id1[b[0]][b[1]][b[2]][b[3]][b[4]]][x]) && (--qi[id1[b[0]][b[1]][b[2]][b[3]][b[4]]][x]==0)){
                                dp[id1[b[0]][b[1]][b[2]][b[3]][b[4]]][x]=2;
                                Q.push(id1[b[0]][b[1]][b[2]][b[3]][b[4]]);
                                Q.push(x);
                            }
                            b[j]++,b[(j-i+5)%5]--;
                        }
                }
        }
        else{
            int a[5],b[5];
            for(int i=0;i<5;i++) a[i]=id2[x][i],b[i]=id2[y][i];
            for(int i=1;i<5;i++) if(a[i]){
                    for(int j=0;j<5;j++) if(b[j] && (j!=i)){
                            b[j]--,b[(j-i+5)%5]++;
                            if((!dp[id1[b[0]][b[1]][b[2]][b[3]][b[4]]][x])){
                                dp[id1[b[0]][b[1]][b[2]][b[3]][b[4]]][x]=1;
                                Q.push(id1[b[0]][b[1]][b[2]][b[3]][b[4]]);
                                Q.push(x);
                            }
                            b[j]++,b[(j-i+5)%5]--;
                        }
                }
        }
    }
    dp[_][_]=0;
}
int main(){
    for(int i=0;i<=8;i++) for(int j=0;j<=8;j++) for(int k=0;k<=8;k++) for(int l=0;l<=8;l++) if(i+j+k+l<=8){
                        id1[i][j][k][l][8-i-j-k-l]=id_now;
                        id2[id_now][0]=i;
                        id2[id_now][1]=j;
                        id2[id_now][2]=k;
                        id2[id_now][3]=l;
                        id2[id_now][4]=8-i-j-k-l;
                        id_now++;
                    }
    for(int i=0;i<id_now;i++) for(int j=0;j<id_now;j++){
            int x=0,y=0;
            for(int k=1;k<5;k++) if(id2[i][k]) x++;
            for(int k=1;k<5;k++) if(id2[j][k]) y++;
            qi[i][j]=x*y;
        }
    build();
    int T;
    scanf("%d",&T);
    while(T--){
        int op;
        scanf("%d",&op);
        int a[5]={0},b[5]={0};
        for(int i=0;i<8;i++){
            int x;
            scanf("%d",&x);
            a[x]++;
        }
        for(int i=0;i<8;i++){
            int x;
            scanf("%d",&x);
            b[x]++;
        }
        if(op==0){
            if(dp[id1[a[0]][a[1]][a[2]][a[3]][a[4]]][id1[b[0]][b[1]][b[2]][b[3]][b[4]]]==1)
                puts("Alice");
            else if(dp[id1[a[0]][a[1]][a[2]][a[3]][a[4]]][id1[b[0]][b[1]][b[2]][b[3]][b[4]]]==2)
                puts("Bob");
            else puts("Deal");
        }
        else{
            if(dp[id1[b[0]][b[1]][b[2]][b[3]][b[4]]][id1[a[0]][a[1]][a[2]][a[3]][a[4]]]==2)
                puts("Alice");
            else if(dp[id1[b[0]][b[1]][b[2]][b[3]][b[4]]][id1[a[0]][a[1]][a[2]][a[3]][a[4]]]==1)
                puts("Bob");
            else puts("Deal");
        }
    }
    return 0;
}