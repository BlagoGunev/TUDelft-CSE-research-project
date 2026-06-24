#include<bits/stdc++.h>
using namespace std;
int s[5],T,a,b,c;
int main(){
//	freopen("a.in","r",stdin);
 scanf("%d",&T);
 while(T--){
  scanf("%d%d%d",&a,&b,&c);
  s[1]=a;s[2]=b;s[3]=c;
  sort(s+1,s+4);
  int ok=0;
  if(s[1]<s[2]&&s[2]==s[3])
   ok=1;
  if(a==b&&b==c)
   ok=2;
  if(ok==1)
    printf("YES\n"),printf("1 %d %d\n",s[1],s[3]);
  
  else if(ok==2)
   printf("YES\n"),printf("%d %d %d\n",a,a,a);
  else printf("NO\n");
 }
 return 0;
}