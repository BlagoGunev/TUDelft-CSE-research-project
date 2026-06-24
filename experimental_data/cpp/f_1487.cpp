#include <bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;++i)

#define fd(i,a,b) for(int i=a;i>=b;--i)

#define max(a,b) ((a)>(b)?(a):(b))

#define min(a,b) ((a)<(b)?(a):(b))

#define N 5005

#define LL unsigned long long

using namespace std;

inline int read()

{

	int X=0,w=0;char ch=0;

	while(!isdigit(ch))w|=ch=='-',ch=getchar();

	while(isdigit(ch))X=(X<<3)+(X<<1)+(ch^48),ch=getchar();

	return w?-X:X;

}

int nu[N],ans,tms=0;

LL mi[N];

char ch[N];

map<LL,int> aa;

int work(int x,int ed,LL ztt)

{

	if(aa.find(ztt)!=aa.end())return aa[ztt];

	if(x>ed)return 0;

	int nw=nu[x],bz=0;

	fo(i,x,ed)

	if(nw!=nu[i])

	{

		bz=1+(nw>nu[i]);

		break;

	}

	if(!bz)return aa[ztt]=nw*(ed-x+1);

	if(bz>1)nw--;

	int o=0,ret1=100000000,ret2=100000000;

	LL zt=0;

	if(nw)fd(i,ed,x)nu[i]=nu[i]-nw-o,o=nu[i]<0,nu[i]+=(nu[i]<0?10:0),zt+=mi[ed-i]*nu[i];

	else zt=ztt;

	if(!nu[x])ret1=work(x+1,ed,zt)+nw*(ed-x+1);

	o=zt=0;

	fd(i,ed,x)nu[i]=1-o-nu[i],o=nu[i]<0,nu[i]+=(nu[i]<0?10:0),zt+=mi[ed-i]*nu[i];

	if(!nu[x])ret2=work(x+1,ed,zt)+(nw+1)*(ed-x+1);

	fd(i,ed,x)nu[i]=nw+1-o-nu[i],o=nu[i]<0,nu[i]+=(nu[i]<0?10:0);

	return aa[ztt]=min(ret1,ret2);

}

int main()

{

	int t=1;mi[0]=1;

	fo(i,1,5001)mi[i]=mi[i-1]*17;

	while(t--)

	{

		scanf("%s",ch+1);

		int len=strlen(ch+1);

		LL zt=0;

		fo(i,1,len)nu[i]=ch[i]-'0',zt=(zt<<4)+zt+nu[i];

		printf("%d\n",work(0,len,zt));

	}

	return 0;

}