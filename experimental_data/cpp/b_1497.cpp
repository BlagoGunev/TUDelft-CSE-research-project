#include<bits/stdc++.h>
#define LL long long
#define V inline void
#define I inline int
#define FOR(i,a,b) for(register int i=a,end##i=b;i<=end##i;++i)
#define REP(i,a,b) for(register int i=a,end##i=b;i>=end##i;--i)
#define go(i,x) for(int i=hed[x];i;i=e[i].pre)
using namespace std;
inline int read()
{
	char x='\0';
	int fh=1,sum=0;
	for(x=getchar();x<'0'||x>'9';x=getchar())if(x=='-')fh=-1;
	for(;x>='0'&&x<='9';x=getchar())sum=sum*10+x-'0';
	return fh*sum;
}
const int N=1e5+9;
int T,n,m,a[N],buf[N];
int main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read();
		FOR(i,0,m)buf[i]=0;
		FOR(i,1,n)a[i]=read(),buf[(a[i]-1)%m+1]++;
		int ans=0;
		if(m%2==1)
		{
			if(buf[m])ans++;
			FOR(i,1,(m-1)/2)
			{
				if(!buf[i]&&!buf[m-i])continue;
				ans++;
				int mn=min(buf[i],buf[m-i]);
				buf[i]=max(0,buf[i]-mn-1);
				buf[m-i]=max(0,buf[m-i]-mn-1);
				ans+=buf[i]+buf[m-i];
			}
		}
		else
		{
			if(buf[m])ans++;
			if(buf[m/2])ans++;
			FOR(i,1,(m-1)/2)
			{
				if(!buf[i]&&!buf[m-i])continue;
				ans++;
				int mn=min(buf[i],buf[m-i]);
				buf[i]=max(0,buf[i]-mn-1);
				buf[m-i]=max(0,buf[m-i]-mn-1);
				ans+=buf[i]+buf[m-i];
			}
		}
		printf("%d\n",ans);
	}
	
	
	return 0;
}