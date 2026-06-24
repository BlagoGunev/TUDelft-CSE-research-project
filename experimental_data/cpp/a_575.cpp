#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
const int N = 50050;
const int M = 150000;
const int T = 65536;
long long n;
int m,zm,p;
int dr[N];
struct Info
{
 long long wei;
 int val;
}xu[N];
struct Matrix
{
 int a,b,c,d;
};
Matrix qz[N],hz[N],ans,tree[M];
long long getint()
{
 long long res=0;
 char ch=getchar();
 while((ch<'0' || ch>'9') && ch!='-')
  ch=getchar();
 bool fan=0;
 if(ch=='-')
 {
  fan=1;
  ch=getchar();
 }
 while('0'<=ch && ch<='9')
 {
  res=res*10+ch-'0';
  ch=getchar();
 }
 if(fan)
  res=-res;
 return res;
}
int jia(int x,int y)
{
 x+=y;
 if(x>=p)
  x-=p;
 return x;
}
int cheng(int x,int y)
{
 long long z=x;
 z*=y;
 z%=p;
 x=z;
 return x;
}
Matrix cheng(Matrix x,Matrix y)
{
 Matrix z;
 z.a=jia(cheng(x.a,y.a),cheng(x.b,y.c));
 z.b=jia(cheng(x.a,y.b),cheng(x.b,y.d));
 z.c=jia(cheng(x.c,y.a),cheng(x.d,y.c));
 z.d=jia(cheng(x.c,y.b),cheng(x.d,y.d));
 return z;
}
bool cmp(Info x,Info y)
{
 return (x.wei<y.wei);
}
void GetData()
{
 int i;
 n=getint()-1;
 p=getint();
 m=getint();
 for(i=0;i<m;i++)
  dr[i]=getint();
 dr[m]=dr[0];
 zm=getint();
 for(i=1;i<=zm;i++)
 {
  xu[i].wei=getint();
  xu[i].val=getint();
 }
 sort(xu+1,xu+zm+1,cmp);
 for(i=1;i<=m;i++)
 {
  qz[i].a=dr[i];
  qz[i].c=dr[i-1];
  qz[i].b=1;
  qz[i].d=0;
  hz[i]=qz[i];
  tree[i+T]=qz[i];
 }
 for(i=2;i<=m;i++)
  qz[i]=cheng(qz[i-1],qz[i]);
 for(i=m-1;i>=1;i--)
  hz[i]=cheng(hz[i],hz[i+1]);
 for(i=T-1;i>=1;i--)
  tree[i]=cheng(tree[i*2],tree[i*2+1]);
}
Matrix powerx(long long x)
{
 Matrix res;
 res.a=res.d=1;
 res.b=res.c=0;
 Matrix now=qz[m];
 while(x)
 {
  if(x&1)
   res=cheng(res,now);
  now=cheng(now,now);
  x>>=1;
 }
 return res;
}
void Special(int x,int y)
{
 ans.c=ans.a;
 ans.a=jia(cheng(ans.a,x),cheng(ans.b,y));
 ans.b=ans.c;
}
Matrix FindSum(int l,int r)
{
 l+=T-1;
 r+=T+1;
 Matrix res;
 res.a=res.d=1;
 res.b=res.c=0;
 Matrix resb=res;
 while(l^r^1)
 {
  if(l%2==0)
   res=cheng(res,tree[l^1]);
  if(r%2==1)
   resb=cheng(tree[r^1],resb);
  l>>=1;
  r>>=1;
 }
 res=cheng(res,resb);
 return res;
}
Matrix power(long long l,long long r)
{
 Matrix res;
 res.a=res.d=1;
 res.b=res.c=0;
 if(l>r)
  return res;
 long long ll=(l-1)%m+1;
 long long rr=(r-1)%m+1;
 long long cl=(l-ll)/m;
 long long cr=(r-rr)/m;
 if(cl==cr)
  res=cheng(res,FindSum(ll,rr));
 else
 {
  res=cheng(res,hz[ll]);
  res=cheng(res,powerx(cr-cl-1));
  res=cheng(res,qz[rr]);
 }
 return res;
}
void DoIt()
{
 if(n<0)
 {
  cout<<0<<endl;
  return;
 }
 ans.a=1;
 ans.b=0;
 int i;
 long long has=0;
 for(i=1;i<=zm;i++)
 {
  if(xu[i].wei>n)
   break;
  ans=cheng(ans,power(has+1,xu[i].wei-1));
  if(i>1 && xu[i-1].wei+1==xu[i].wei)
   Special(xu[i].val,xu[i-1].val);
  else
   Special(xu[i].val,dr[(xu[i].wei-1)%m]);
  has=xu[i].wei;
  if(n==xu[i].wei)
   break;
  if(i<zm && xu[i].wei+1==xu[i+1].wei)
   continue;
  Special(dr[(xu[i].wei+1)%m],xu[i].val);
  has++;
 }
 ans=cheng(ans,power(has+1,n));
 cout<<ans.a<<endl;
}
int main()
{
 GetData();
 DoIt();
 return 0;
}