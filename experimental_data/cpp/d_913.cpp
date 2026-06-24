#include<bits/stdc++.h>
#define sight(c) ('0'<=c&&c<='9')
#define N 400007
inline void read(int &x){
 static char c;static int b;
 for (b=1,c=getchar();!sight(c);c=getchar())if (c=='-') b=-1;
 for (x=0;sight(c);c=getchar()) x=x*10+c-48;
    x*=b;
}
struct Node{
 int a,t,id;
 bool operator < (const Node& T)const {
    return t<T.t;
 }
}t[N];
using namespace std;
int T,n,r,ans,Ans,tot;
inline bool check(int x){
 tot=Ans=0;
 for (int i=1;i<=n;i++) if (t[i].a>=x)  {
  Ans+=t[i].t;tot++; if (tot==x) break;
 }
 return tot==x&&Ans<=T;
}
int main () {
 read(n); read(T);
 for (int i=1;i<=n;i++) read(t[i].a),read(t[i].t),t[i].id=i;
 r=trunc(log2(n));r=1<<r;
 sort(t+1,t+n+1);
 while (r) {
  if (check(ans+r)) ans+=r; r>>=1; 
 }
 printf("%d\n",ans);
 printf("%d\n",ans); tot=0;
 if (!ans) return 0;
 for (int i=1;i<=n;i++) {
  if(t[i].a>=ans) {printf("%d ",t[i].id);tot++;}
  if (tot==ans)  break;
 } return 0;
}