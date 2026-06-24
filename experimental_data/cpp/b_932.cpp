#include<bits/stdc++.h>
inline int read(){
 char c=getchar();while (c!='-'&&(c<'0'||c>'9'))c=getchar();
 int k=1,kk=0;if (c=='-')c=getchar(),k=-1;
 while (c>='0'&&c<='9')kk=kk*10+c-'0',c=getchar();return kk*k;
}using namespace std;
void write(int x){if (x<0)putchar('-'),x=-x;if (x/10)write(x/10);putchar(x%10+'0');}
void writeln(int x){write(x);puts("");}
const int N=1e6;
int g[2000000],f[2000000][10],l,r,k,q;
int doit(int x){
 int ans=1;while (x){
  if (x%10)ans*=x%10;x/=10;
 }return ans;
}
signed main(){
 for (int i=1;i<=9;i++)g[i]=i;
 for (int i=1;i<=N;i++)g[i]=g[doit(i)];
 for (int i=1;i<=N;i++){
  for (int j=1;j<=9;j++)f[i][j]=f[i-1][j];
  f[i][g[i]]++;
 }q=read();while (q--){
  l=read();r=read();k=read();writeln(f[r][k]-f[l-1][k]); 
 }
}