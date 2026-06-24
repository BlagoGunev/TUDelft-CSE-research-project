#include<bits/stdc++.h> //Ithea Myse Valgulious
namespace chtholly{
typedef long long ll;
#define re0 register int
#define rec register char
#define rel register ll
#define gc getchar
#define pc putchar
#define p32 pc(' ')
#define pl puts("")
/*By Citrus*/
inline int read(){
  int x=0,f=1;char c=gc();
  for (;!isdigit(c);c=gc()) f^=c=='-';
  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');
  return f?x:-x;
  }
template <typename mitsuha>
inline bool read(mitsuha &x){
  x=0;int f=1;char c=gc();
  for (;!isdigit(c)&&~c;c=gc()) f^=c=='-';
  if (!~c) return 0;
  for (;isdigit(c);c=gc()) x=(x<<3)+(x<<1)+(c^'0');
  return x=f?x:-x,1;
  }
template <typename mitsuha>
inline int write(mitsuha x){
  if (!x) return 0&pc(48);
  if (x<0) x=-x,pc('-');
  int bit[20],i,p=0;
  for (;x;x/=10) bit[++p]=x%10;
  for (i=p;i;--i) pc(bit[i]+48);
  return 0;
  }
inline char fuhao(){
  char c=gc();
  for (;isspace(c);c=gc());
  return c;
  }
}using namespace chtholly;
using namespace std;
const int yuzu=2e5;
int n,zero,f;
ll a[yuzu|10];
int main() {
  read(n);
  for(int i=1; i<=n; i++) {
    read(a[i]);
    if (!a[i]) zero++;
    if (a[i]<0) f++;
  }
  if(!zero) {
    if(f&1) {
      int xiao=1e9+7,pos;
      for(int i=1;i<=n;i++) if (a[i]<0&&abs(a[i])<xiao) xiao=abs(a[i]),pos=i;
      printf("2 %d\n",pos);
      int st;
      st=pos==1?2:1;
      for(int j=1; j<=n; j++) {
        if (j!=pos&&j!=st) 
          printf("1 %d %d\n",j,st);
      }
    } else {
      for (int i=2; i<=n; i++) printf("1 %d %d\n",i,1);
    }
  } else {
    if(f&1) {
      int c=n;
      int pos;
      for(int i=1; i<=n; i++) {
        if(a[i]==0) pos=i;
      }
      for(int i=1; i<=n; i++) {
        if(i==pos) continue ;
        if(a[i]==0) {
          c--;
          printf("1 %d %d\n",i,pos);
        }
      }
      int xiao=1e9+7,poss;
      for(int i=1; i<=n; i++) {
        if (!a[i]) continue ;
        if (a[i]<0&&abs(a[i])<xiao) xiao=abs(a[i]),poss=i;
      }--c,printf("1 %d %d\n",poss,pos);
      if (c^1) printf("2 %d\n",pos);
      int st;
      for(int i=1; i<=n; i++) {
        if(a[i]==0) continue ;
        if(i==pos||i==poss) continue ;
        st=i;
        break;
      }
      for(int i=1; i<=n; i++) {
        if(a[i]==0) continue ;
        if(i==pos||i==poss||i==st) continue ;
        printf("1 %d %d\n",i,st);
      }
    } else {
      int pos;
      int c=n;
      for (int i=1; i<=n; i++)  if (!a[i]) pos=i;
      for (int i=1; i<=n; i++) {
        if (i==pos) continue ;
        if (!a[i]) {
          --c,printf("1 %d %d\n",i,pos);
        }
      }
      if (c^1) printf("2 %d\n",pos);
      int st;
      for (int i=1; i<=n; i++) {
        if (!a[i]) continue ;
        st=i;break;
      }
      for (int i=1; i<=n; i++) {
        if (!a[i]||i==st) continue ;
        printf("1 %d %d\n",i,st);
      }
    }
  }
}