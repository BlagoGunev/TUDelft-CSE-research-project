#include<stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<math.h>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<ctype.h>
#define LL long long
#define oo 1000000000
#define N 300005
using namespace std;
int get(){
    char c;int res=0;
    while(c=getchar(),!isdigit(c));
    do{
        res=(res<<3)+(res<<1)+(c-'0');
    }while(c=getchar(),isdigit(c));
//printf("res=%d\n",res);
    return res;
}
int num[50][50],sum1[45][45],sum[45][45][45][45],sum2[45][45][45][45];
int main(){
    int n,m,i,j,k,a,b,c,d,q,x;
    while(scanf("%d %d %d",&n,&m,&q)!=EOF){
        memset(sum1,0,sizeof(sum1));
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++){
                scanf("%1d",&x);
                sum1[i][j]=sum1[i-1][j]+sum1[i][j-1]-sum1[i-1][j-1]+(!x);
            }
        memset(sum,0,sizeof(sum));
        for(c=1;c<=n;c++)
            for(d=1;d<=m;d++) 
                for(a=c;a<=n;a++)
                    for(b=d;b<=m;b++){
                        int temp=sum1[a][b]-sum1[a][d-1]-sum1[c-1][b]+sum1[c-1][d-1];
                        if(temp==(a-c+1)*(b-d+1)){
                            sum[c][d][a][b]=1; 
                        }
                    }
        for(a=1;a<=n;a++)
            for(b=1;b<=m;b++)
                for(c=a;c<=n;c++)
                    for(d=b;d<=m;d++){
                    //  printf("|||--%d %d %d %d %d\n",a,b,c,d,sum[a][b][c][d]);
                        sum[a][b][c][d]+=sum[a][b][c-1][d]+sum[a][b][c][d-1]-sum[a][b][c-1][d-1];
                    //  printf("--%d %d %d %d %d\n",a,b,c,d,sum[a][b][c][d]);//printf("%d %d %d %d %d %d %d--\n",a,b,c,d,sum[a][b][c][d],sum[a][b][c][d-1],sum[a][b][c-1][d-1]);
                    }
        memset(sum2,0,sizeof(sum2));
        for(c=1;c<=n;c++)
            for(d=1;d<=m;d++)
                for(a=c;a>=1;a--)
                    for(b=d;b>=1;b--){
                        sum2[a][b][c][d]=sum2[a+1][b][c][d]+sum2[a][b+1][c][d];
                        sum2[a][b][c][d]+=sum[a][b][c][d]-sum2[a+1][b+1][c][d];
                    }
        while(q--){
            a=get();b=get();c=get();d=get();
            //printf("%d %d %d %d         s\n",a,b,c,d);
            int ans=0,x,y;
            ans=sum2[a][b][c][d];
        /*  for(x=a;x<=c;x++)
                for(y=b;y<=d;y++){
                    ans+=sum[x][y][c][d]-sum[x][y][c][y-1]-sum[x][y][x-1][d]+sum[x][y][x-1][y-1];
                    //printf("%d %d %d\n",x,y,ans);
                }*/
            printf("%d\n",ans);
        }
    }
    return 0;
}