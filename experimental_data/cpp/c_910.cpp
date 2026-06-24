#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long a[15],ans;
int flag[15],n,f[15];
char s[15];
int cmp(int x,int y){
 return a[x]>a[y];
}

int main(){

 scanf("%d",&n);
 int i;
 for(i=0;i<10;i++){
  f[i]=i;
 }
 while(n--){
  scanf("%s",&s);
  int k=1;
  for(int j=strlen(s)-1;j>=0;j--){
   a[s[j]-97]+=k,k=k*10;
  }
  flag[s[0]-97]=1;
 }
 ans=1000000000000000;
 sort(f,f+10,cmp);
 for(i=0;i<=9;i++){
  if(!flag[i]){
   int k=1;
   long long sum=0;
   for(int j=0;j<=9;j++){
    if(i!=f[j]){
     sum+=a[f[j]]*k,k++;
    }
   }
   ans=min(sum,ans);
  }
 }
 printf("%I64d",ans);

}