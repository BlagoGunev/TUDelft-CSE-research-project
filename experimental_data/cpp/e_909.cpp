#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
 int x = 0; char ch = gc(); bool positive = 1;
 for (; !isdigit(ch); ch = gc()) if (ch == '-') positive = 0;
 for (; isdigit(ch); ch = gc()) x = x * 10 + ch - '0';
 return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
     a=-a; putchar('-');
 }
 write(a); puts("");
}
const int N=100005;
vector<int> v[N];
int ans,n,m,a[N],l[2],r[2],rd[N],q[N][2];
int main(){
 n=read(); m=read();
 for(int i=1;i<=n;i++)a[i]=read();
 for(int i=1;i<=m;i++){
  int a=read()+1,b=read()+1;
  rd[a]++; v[b].push_back(a);
 }
 for(int i=1;i<=n;i++)if(!rd[i])q[++r[a[i]]][a[i]]=i;
 int dq=0;
 while(l[0]<r[0]||l[1]<r[1]){
  while(l[dq]<r[dq]){
   int t=q[++l[dq]][dq];
   for(int i=0;i<v[t].size();i++)if(--rd[v[t][i]]==0)q[++r[a[v[t][i]]]][a[v[t][i]]]=v[t][i];
  } 
  //cout<<dq<<endl;
  ans+=dq; dq^=1;
 }
 cout<<ans<<endl;
}