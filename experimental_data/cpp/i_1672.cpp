#include <bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;++i)

#define fd(i,a,b) for(int i=a;i>=b;--i)

#define max(a,b) ((a)>(b)?(a):(b))

#define min(a,b) ((a)<(b)?(a):(b))

#define lowbit(x) ((x)&(-x))

#define N 500005

#define M 2000005

using namespace std;

inline int read()

{

	int X=0,w=0;char ch=0;

	while(!isdigit(ch))w|=ch=='-',ch=getchar();

	while(isdigit(ch))X=(X<<3)+(X<<1)+(ch^48),ch=getchar();

	return w?-X:X;

}

int t1[N],t2[N],tr1[M],tr2[M],tr3[M],tr4[M],a[N],b[N],ta3[M],ta4[M],ad3[M],ad4[M],n,trr1[M],trr2[M],nu[N];

set<int> a1,a2;

void ins1(int x)

{

	while(x<=500000)t1[x]++,x+=lowbit(x);

}

int ask1(int x)

{

	int ret=0;

	while(x)ret+=t1[x],x-=lowbit(x);

	return ret;

}

void ins2(int x)

{

	while(x<=500000)t2[x]++,x+=lowbit(x);

}

int ask2(int x)

{

	int ret=0;

	while(x)ret+=t2[x],x-=lowbit(x);

	return ret;

}

void push3(int k)

{

	tr3[k<<1]+=ad3[k];tr3[(k<<1)+1]+=ad3[k];

	ad3[k<<1]+=ad3[k];ad3[(k<<1)+1]+=ad3[k];

	ad3[k]=0;

}

void push4(int k)

{

	tr4[k<<1]+=ad4[k];tr4[(k<<1)+1]+=ad4[k];

	ad4[k<<1]+=ad4[k];ad4[(k<<1)+1]+=ad4[k];

	ad4[k]=0;

}

void modify3(int l,int r,int k,int x,int v)

{

	if(r<=x&&trr1[k]>=v)

	{

		tr3[k]--;

		ad3[k]--;

		return;

	}

	if(l==r)return;

	push3(k);

	int mid=l+r>>1;

	if(mid<x)modify3(mid+1,r,(k<<1)+1,x,v);

	if(trr1[(k<<1)+1]>=v)modify3(l,mid,k<<1,x,v);

	tr3[k]=min(tr3[k<<1],tr3[(k<<1)+1]);

	ta3[k]=(tr3[k]==tr3[k<<1]?ta3[k<<1]:ta3[(k<<1)+1]);

}

void modify4(int l,int r,int k,int x,int v)

{

	if(l>=x&&trr2[k]<=v)

	{

		tr4[k]--;

		ad4[k]--;

		return;

	}

	if(l==r)return;

	push4(k);

	int mid=l+r>>1;

	if(mid>=x)modify4(l,mid,k<<1,x,v);

	if(trr2[k<<1]<=v)modify4(mid+1,r,(k<<1)+1,x,v);

	tr4[k]=min(tr4[k<<1],tr4[(k<<1)+1]);

	ta4[k]=(tr4[k]==tr4[k<<1]?ta4[k<<1]:ta4[(k<<1)+1]);

}

void modi3(int l,int r,int k,int x,int v)

{

	if(l==r)

	{

		tr3[k]=v;ta3[k]=x;

		trr1[k]=a[x];

		return;

	}

	push3(k);

	int mid=l+r>>1;

	if(mid>=x)modi3(l,mid,k<<1,x,v);

	else modi3(mid+1,r,(k<<1)+1,x,v);

	tr3[k]=min(tr3[k<<1],tr3[(k<<1)+1]);

	ta3[k]=(tr3[k]==tr3[k<<1]?ta3[k<<1]:ta3[(k<<1)+1]);

	trr1[k]=min(trr1[k<<1],trr1[(k<<1)+1]);

}

void modi4(int l,int r,int k,int x,int v)

{

	if(l==r)

	{

		tr4[k]=v,ta4[k]=x;

		trr2[k]=b[x];

		return;

	}

	push4(k);

	int mid=l+r>>1;

	if(mid>=x)modi4(l,mid,k<<1,x,v);

	else modi4(mid+1,r,(k<<1)+1,x,v);

	tr4[k]=min(tr4[k<<1],tr4[(k<<1)+1]);

	ta4[k]=(tr4[k]==tr4[k<<1]?ta4[k<<1]:ta4[(k<<1)+1]);

	trr2[k]=max(trr2[k<<1],trr2[(k<<1)+1]);

}

void modify1(int l,int r,int k,int x)

{

	if(l==r)

	{

		tr1[k]=x;

		return;

	}

	int mid=l+r>>1;

	if(mid>=x)modify1(l,mid,k<<1,x);

	else modify1(mid+1,r,(k<<1)+1,x);

	tr1[k]=(a[tr1[k<<1]]<a[tr1[(k<<1)+1]]?tr1[k<<1]:tr1[(k<<1)+1]); 

}

int query1(int l,int r,int k,int x,int y)

{

	if(x>y)return 0;

	if(l>=x&&r<=y)return tr1[k];

	int mid=l+r>>1,a1,a2;

	if(mid>=y)return query1(l,mid,k<<1,x,y);

	if(mid<x)return query1(mid+1,r,(k<<1)+1,x,y);

	a1=query1(l,mid,k<<1,x,y);

	a2=query1(mid+1,r,(k<<1)+1,x,y);

	return (a[a1]<a[a2]?a1:a2);

}

void modify2(int l,int r,int k,int x)

{

	if(l==r)

	{

		tr2[k]=x;

		return;

	}

	int mid=l+r>>1;

	if(mid>=x)modify2(l,mid,k<<1,x);

	else modify2(mid+1,r,(k<<1)+1,x);

	tr2[k]=(b[tr2[k<<1]]>b[tr2[(k<<1)+1]]?tr2[k<<1]:tr2[(k<<1)+1]);

}

int query2(int l,int r,int k,int x,int y)

{

	if(x>y)return 0;

	if(l>=x&&r<=y)return tr2[k];

	int mid=l+r>>1,a1,a2;

	if(mid>=y)return query2(l,mid,k<<1,x,y);

	if(mid<x)return query2(mid+1,r,(k<<1)+1,x,y);

	a1=query2(l,mid,k<<1,x,y);

	a2=query2(mid+1,r,(k<<1)+1,x,y);

	return (b[a1]>b[a2]?a1:a2);

}

int cal(int wz,int x)

{

	return abs(x-ask1(x)-wz+ask2(wz));

}

void find1(int l,int r,int sd)

{

	int wz=query1(1,n,1,l,r);

	if(!wz)return;

	while(a[wz]<sd)

	{

		a1.insert(wz);

		modi3(1,n,1,wz,cal(wz,a[wz]));

		a[wz]=n+5;

		modify1(1,n,1,wz);

		wz=query1(1,n,1,wz+1,r);

		if(!wz)return;

	}

}

void find2(int l,int r,int sd)

{

	int wz=query2(1,n,1,l,r);

	if(!wz)return;

	while(b[wz]>sd)

	{

		a2.insert(wz);

		modi4(1,n,1,wz,cal(wz,b[wz]));

		b[wz]=0;

		modify2(1,n,1,wz);

		wz=query2(1,n,1,l,wz-1);

		if(!wz)return;

	}

}

int main()

{

	n=read();

	fo(i,1,n)

	{

		int x=read();nu[i]=x;

		if(i<=x)a[i]=x,b[i]=0;

		else b[i]=x,a[i]=n+5;

		modify1(1,n,1,i);modify2(1,n,1,i);

		modi3(1,n,1,i,n+5000000);modi4(1,n,1,i,n+5000000);

	}

	find1(1,n,n+5);

	find2(1,n,0);

	int ans=0;

	nu[n+1]=n+5;

	fo(i,1,n)

	{

		if(tr3[1]<=tr4[1])

		{

			ans=max(ans,tr3[1]);

			set<int>::iterator wz=a1.find(ta3[1]);

			int l=0,r=n+1;

			if((++wz)!=a1.end())r=*wz;wz--;

			if(wz!=a1.begin())wz--,l=*wz;

			a1.erase(a1.find(ta3[1]));

			ins2(ta3[1]),ins1(nu[ta3[1]]);

			modify4(1,n,1,ta3[1],nu[ta3[1]]);

			modi3(1,n,1,ta3[1],n+5000000);

			find1(l+1,r-1,nu[r]);

		}else{

			ans=max(ans,tr4[1]);

			set<int>::iterator wz=a2.find(ta4[1]);

			int l=0,r=n+1;

			if((++wz)!=a2.end())r=*wz;wz--;

			if(wz!=a2.begin())wz--,l=*wz;

			a2.erase(a2.find(ta4[1]));

			ins2(ta4[1]),ins1(nu[ta4[1]]);

			modify3(1,n,1,ta4[1],nu[ta4[1]]);

			modi4(1,n,1,ta4[1],n+5000000);

			find2(l+1,r-1,nu[l]);

		}

	}

	printf("%d\n",ans); 

	return 0;

}