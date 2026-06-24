#include<stdio.h>

int Min(int a,int b){
 return a<b?a:b;
}
int main(){
 int n,d;
 scanf("%d%d",&n,&d);
 char s[105];
 scanf("%s",s);
 int ans=0;
 for(int i=0;i<n-1;i++){
  int flag=0;
  for(int j=Min(i+d,n-1);j>i;j--){
   if(s[j]=='1'){
    ans++;
    i=j-1;
    flag=1;
    break;
   }
  }
  if(!flag){
   ans=-1;
   break;
  }
 }
 printf("%d\n",ans);
 return 0;
}