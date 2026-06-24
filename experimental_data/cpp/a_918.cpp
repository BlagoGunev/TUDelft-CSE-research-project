#include <cstdio>
int f[25];
char ans[1005];
int main(){
 f[0]=0;f[1]=1;
 int n;
 for(int i=0;i<1000;i++)ans[i]='o';
 for(int i=2;f[i-1]<1000;i++)ans[(f[i]=f[i-1]+f[i-2])-1]='O'; 
 scanf("%d",&n);
 ans[n]=0;
 puts(ans);
}