#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
int n,x,y,a[1000001],b[10],p[400],kd[1000001];
int main()
{
  scanf("%d%d%d",&n,&x,&y);
  rep(i,1,n)
    scanf("%d",&a[i]);
  long long ans=(ll)1e18;
  rep(i,1,3)
    b[i]=a[1]+i-2;
  rep(i,1,3)
    b[i+3]=a[n]+i-2;
  int np=0;
  rep(ff,1,6)
  {
    int t=b[ff],s=2;
    while(t>1)
    {
      if(s>floor(sqrt(b[ff])))break;
      if(t%s==0)
      {
        while(t%s==0)t/=s;
        p[++np]=s;
      }
      s++;
    }
    if(t>1)p[++np]=t;
  }
  sort(p+1,p+1+np);
  p[0]=-1;
  rep(wtf,1,np)
    if(p[wtf]!=p[wtf-1])
    {
      //printf("%d\n",p[wtf]);
      int tem=p[wtf],l=0,r,s1=0,s2=0;
      rep(i,1,n)
        if(a[i]%tem==0)kd[i]=1;
          else if((a[i]+1)%tem==0||(a[i]-1)%tem==0)kd[i]=2,s1++;
            else 
            {
              l=i;
              kd[i]=0;
              break;
            }
      if(l)
        for(int i=n;i;i--)
          if(a[i]%tem==0)kd[i]=1;
            else if((a[i]+1)%tem==0||(a[i]-1)%tem==0)kd[i]=2,s2++;
              else 
              {
                r=i;
                kd[i]=0;
                break;
              }      
      if(l)
      {
        long long ans2=0,now=(ll)s1*y,ans1=now,ans11,ans22;
        for(int i=l-1;i;i--)
        {
          if(kd[i]==2)
          {
            now-=y;
          }
          now+=x;
          if(i==1)ans11=ans1;
          if(now<ans1)ans1=now;
        }
        now=(ll)s2*y;
        ans2=now;
        rep(i,r+1,n)
        {
          if(kd[i]==2)now-=y;
          now+=x;
          if(i==n)ans22=ans2;
          if(now<ans2)ans2=now;
        }
        long long bans=min(ans1+ans22,ans2+ans11)+(ll)(r-l+1)*x;
        if(bans<ans)ans=bans;
      }
      else
      {
        long long anss=(ll)1e18,anss2=(ll)1e18,now=x,last=0,ss=0,st=(ll)s1*y;
        rep(i,1,n)
        {
          now=min(last+x,ss+x);
          if(kd[i]==2)st-=y;
          if(i<n&&now+st<anss)anss=now+st;
          if(kd[i]==2)ss+=y;
          last=now;
        }
        now=(ll)s1*y;
        if(now<anss)anss=now;
        for(int i=n;i>1;i--)
        {
          if(kd[i]==2)now-=y;
          now+=x;
          if(now<anss)anss=now;
        }
        if(anss<ans)ans=anss;
      }
    }
  printf("%lld\n",ans);
  return 0;
}