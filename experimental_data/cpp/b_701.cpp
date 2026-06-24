#include <bits/stdc++.h>
//B
//by Cydiater
//2016.7.23
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <queue>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;
#define ll long long
#define up(i,j,n)       for(int i=j;i<=n;i++)
#define down(i,j,n)     for(int i=j;i>=n;i--)
const int MAXN=1e5+5;
const int oo=0x3f3f3f3f;
inline ll read(){
      char ch=getchar();ll x=0,f=1;
      while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
      while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
      return x*f;
}
ll N,M,siz_row=0,siz_col=0,x,y,ans;
bool row[MAXN],col[MAXN];//row heng zhe de
                         //col shu zhe de
namespace solution{
      void add_row(ll x){
            if(!row[x])ans-=N-siz_col,siz_row++;
            row[x]=1;
      }
      void add_col(ll y){
            if(!col[y])ans-=N-siz_row,siz_col++;
            col[y]=1;
      }
      void init(){
            N=read();M=read();
            memset(row,0,sizeof(row));
            memset(col,0,sizeof(col));
      }
      void slove(){
            ans=N*N;
            up(i,1,M){
                  x=read();y=read();
                  add_row(x);add_col(y);
                  printf("%lld ",ans);
            }
            printf("\n");
      }
}
int main(){
      //freopen("input.in","r",stdin);
      using namespace solution;
      init();
      slove();
      return 0;
}