#include<cstdio>
inline void read(int&r)
{ register char c;r=0;do c=getchar();while(c<'0'||c>'9');
  do r=r*10+c-'0',c=getchar();while(c>='0'&&c<='9'); }
inline int abs(int x){ return x<0?-x:x; }

int l[100001],r[100001];
int main()
{
  int n,i,sl=0,sr=0,ans,p=0;read(n);
  for(i=1;i<=n;i++)
	read(l[i]),read(r[i]),sl+=l[i],sr+=r[i];
  ans=abs(sl-sr);

  for(i=1;i<=n;i++){
	sl+=r[i]-l[i];
	sr+=l[i]-r[i];
	if(abs(sl-sr)>ans)
	  ans=abs(sl-sr),p=i;
	sl-=r[i]-l[i];
	sr-=l[i]-r[i];
  }

  printf("%d\n",p);
  return 0;
}