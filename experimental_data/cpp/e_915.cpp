#include<bits/stdc++.h>
using namespace std;
//xianduanshu
inline int read()
{
 int ret=0; char c=getchar();
 while(c<48||c>57)c=getchar();
 while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
 return ret;
}

struct node
{
 int l, r;
 bool operator < (const node & a)const
 {
  if(l!=a.l)return l<a.l;
  return r<a.r; 
  } 
};
set<node> ::iterator it; //_ //bzoj
set<node>s;//<_< >_>
int n,q,ans,l,r,k,a,b;

int main()
{
// freopen("1.in","r",stdin);
 n=read(); q=read();
 ans=n;
 while(q--)
 {
  l=read(); r=read(); k=read();//.
  if(k==2)
  {
   if(s.empty())
   {
    
    printf("%d\n",ans);
       continue;
   }
   it=s.lower_bound((node){l,0});
   while(it!=s.end())
   {
    a=(*it).l;
       b=(*it).r;
       //& ?
       if(a<=r)
       {
        if(b>r)
        {
            ans+=r-a+1;
            s.erase(it);
            s.insert((node){r+1,b});
            break;
        } 
        ans+=b-a+1;
           s.erase(it);
       }
       else break;
       it=s.lower_bound((node){l,0});
   }
   it=s.lower_bound((node){l,0});
  if(it!=s.begin())
  {
   --it;
   if((*it).r>=l)
   {
    a=(*it).l;
    b=(*it).r;
    if((*it).r<=r)
    {
//    a=(*it).l;
    ans+=((*it).r-l+1);//() //ll -4
    s.erase(it);   //a>b   l rL R
    s.insert((node){a,l-1});
    }
    else
    {
     
    ans+=(r-l+1);//() //ll -4
    s.erase(it);   //a>b   l rL R
    s.insert((node){a,l-1});
    s.insert((node){r+1,b});
    }
   }
  }
   printf("%d\n",ans);
   continue;
  }
  
  if(s.empty())
  {  
      s.insert((node){l,r});
      ans-=r-l+1;
      printf("%d\n",ans);
   continue; 
  }
  
  it=s.lower_bound((node){l,0});
  while(it!=s.end())
   {
    a=(*it).l;
       b=(*it).r;
       //& ?
       if(a<=r)
       {
        if(b>r)
        {
            ans+=r-a+1;
            s.erase(it);
            s.insert((node){r+1,b});
            break;
        } 
        ans+=b-a+1;
           s.erase(it);
       }
       else break;
       it=s.lower_bound((node){l,0});
   }
  it=s.lower_bound((node){l,0});
  if(it!=s.begin())
  {
   --it;
   if((*it).r>=l)
   {
    a=(*it).l;
    b=(*it).r;
    if((*it).r<=r)
    {
//    a=(*it).l;
    ans+=((*it).r-l+1);//() //ll -4
    s.erase(it);   //a>b   l rL R
    s.insert((node){a,l-1});
    }
    else
    {
     
    ans+=(r-l+1);//() //ll -4
    s.erase(it);   //a>b   l rL R
    s.insert((node){a,l-1});
    s.insert((node){r+1,b});
    }
   }
  }
   s.insert((node){l,r});
   ans-=r-l+1;
   printf("%d\n",ans);
   //con
 }
}