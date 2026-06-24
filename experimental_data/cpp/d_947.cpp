#include<bits/stdc++.h>
using namespace std;
int input(){
 int f=1,s=0;char c=getchar();
 while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
 while(c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}
 return s*f;
}
const int N=100050;
int n,m,a1[N],b1[N],a2[N],b2[N];
char s[N],t[N];
bool check(int la,int lb,int ra,int rb){
 if(!lb && rb>0)return ((rb%2==0) && (la>ra));
 if(lb>rb)return 0;
 if(lb==rb)return (la>=ra) && (la-ra)%3==0;
 return (rb-lb)%2==0 && la>=ra;
}
// a:B1 b:B2 c:A1 d: A2
int main(){
 scanf("%s%s",s+1,t+1);
 n=strlen(s+1);m=strlen(t+1);
 for(int i=1;i<=n;++i){
  b1[i]=b1[i-1]+(s[i]!='A');
  if(s[i]=='A')a1[i]=a1[i-1]+1;
 }
 for(int i=1;i<=m;++i){
  b2[i]=b2[i-1]+(t[i]!='A');
  if(t[i]=='A')a2[i]=a2[i-1]+1;
 }
 for(int l1,l2,r1,r2,Q=input();Q--;){
  l1=input();r1=input();l2=input();r2=input();
  putchar(check(min(a1[r1],r1-l1+1),b1[r1]-b1[l1-1],min(a2[r2],r2-l2+1),b2[r2]-b2[l2-1]) ? '1' : '0');
 }
 return 0;
}