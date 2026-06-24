#include <bits/stdc++.h>
const int N=200050;
using namespace std;
inline int gi(){
  char ch=getchar();int x=0,q=0;
  while(ch<'0' || ch>'9') ch=='-'?q=1:0,ch=getchar();
  while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
  return q?(-x):x;
}
int a[N],p[N],w[N],tot,o[N],tmp,num;
void solve(int x){
  int s=a[x];
  int l=0,r=32000,mid,ql=0,qr=32000;
  while(l<=r){
    mid=(l+r)>>1;
    if (mid*mid>=s) r=mid-1,qr=mid;
    else l=mid+1,ql=mid;
  }
  if (qr*qr==s){
    ++tot,p[x]=1;
    if (s==0) w[x]=2;
    else w[x]=1;
  }
  else{
    w[x]=min(qr*qr-s,s-ql*ql);
  }
  return;
}
int main(){
  //freopen("E.in","r",stdin);
  //freopen("E.out","w",stdout);
  int n=gi();
  for (int i=1; i<=n; ++i){
    a[i]=gi();
    solve(i);
  }
  if (tot==n/2){
    puts("0");
    return 0;
  }
  else if (tot>n/2){
    num=tot-n/2;
    for (int i=1; i<=n; ++i)
      if (p[i])
	o[++tmp]=w[i];
  }
  else{
    num=n/2-tot;
    for (int i=1; i<=n; ++i)
      if (!p[i])
	o[++tmp]=w[i];
  }
  sort(o+1,o+tmp+1);
  long long s=0;
  for (int i=1; i<=num; ++i)
    s+=o[i];
  cout<<s;
  return 0;
}