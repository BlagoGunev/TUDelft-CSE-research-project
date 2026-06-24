#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXSIZE=10000020;
int bufpos;
char buf[MAXSIZE];
#define NEG 0
void init(){
 #ifdef LOCAL
  freopen("D.txt","r",stdin);
 #endif
 buf[fread(buf,1,MAXSIZE,stdin)]='\0';
 bufpos=0;
}
#if NEG
int readint(){
 bool isneg;
 int val=0;
 for(;!isdigit(buf[bufpos]) && buf[bufpos]!='-';bufpos++);
 bufpos+=(isneg=buf[bufpos]=='-');
 for(;isdigit(buf[bufpos]);bufpos++)
  val=val*10+buf[bufpos]-'0';
 return isneg?-val:val;
}
#else
int readint(){
 int val=0;
 for(;!isdigit(buf[bufpos]);bufpos++);
 for(;isdigit(buf[bufpos]);bufpos++)
  val=val*10+buf[bufpos]-'0';
 return val;
}
#endif
char readchar(){
 for(;isspace(buf[bufpos]);bufpos++);
 return buf[bufpos++];
}
int readstr(char* s){
 int cur=0;
 for(;isspace(buf[bufpos]);bufpos++);
 for(;!isspace(buf[bufpos]);bufpos++)
  s[cur++]=buf[bufpos];
 s[cur]='\0';
 return cur;
}
ll a[200002];
int main(){
 init();
 int n=readint();
 ll d=readint(),b=readint();
 for(int i=1;i<=n;i++)
  a[i]=readint()+a[i-1];
 int k=n/2,x1=0;
 for(int i=1;i<=k;i++){
  if (a[min(i+d*i,1LL*n)]-(i-1-x1)*b<b)
   x1++;
 }
 int x2=0;
 for(int i=n;i>k;i--)
  if (a[n]-a[max(i-d*(n-i+1)-1,0LL)]-(n-i-x2)*b<b)
   x2++;
 printf("%d",max(x1,x2));
}