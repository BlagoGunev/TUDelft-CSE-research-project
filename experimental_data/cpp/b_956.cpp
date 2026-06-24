#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
inline char tc(void){
 static char fl[10000],*A=fl,*B=fl;
 return A==B&&(B=(A=fl)+fread(fl,1,10000,stdin),A==B)?EOF:*A++;
}
inline int read(void){
 int a=0;char c;
 while((c=tc())<'0'||c>'9');
 while(c>='0'&&c<='9')a=a*10+c-'0',c=tc();
 return a;
}
int n,U,E[100005];
double ans=0;
int main(void){
 register int i,l,r;
 bool b=0;
 n=read(),U=read();
 for(i=1;i<=n;++i)E[i]=read();
 l=0,r=1;
 while(l<n){
  ++l;
  while(r<n&&E[l]+U>=E[r+1])++r;
  if(r-l<2)continue;
  b=1;
  ans=max(ans,(E[r]-E[l+1])/(double)(E[r]-E[l]));
 }
 if(b)printf("%.10f\n",ans);
 else puts("-1");
 return 0;
}