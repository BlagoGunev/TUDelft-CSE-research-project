#include<bits/stdc++.h>

using namespace std;

#define LL long long

#define pa pair<int,int>

const int N=500010,W=20,U=(1<<W)-1;

LL read()

{

	LL x=0,f=1;char ch=getchar();

	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}

	while(ch>='0'&&ch<='9')x=x*10ll+ch-'0',ch=getchar();

	return x*f;

}

int n,q;

int root,tot;

int tag[N*(W+1)],c[N*(W+1)],lc[N*(W+1)],rc[N*(W+1)],p0[N*(W+1)],p1[N*(W+1)];

vector<int>sta;

void del(int x)

{

	c[x]=lc[x]=rc[x]=tag[x]=p0[x]=p1[x]=0;

	sta.emplace_back(x);

}

int newnode()

{

	if(sta.empty())

	return ++tot;

	int x=sta.back();sta.pop_back();

	return x;

}

void up(int x)

{

	c[x]=c[lc[x]]+c[rc[x]];

	p0[x]=p0[lc[x]]|p0[rc[x]];

	p1[x]=p1[lc[x]]|p1[rc[x]];

}

void Xor(int x,int dep,int v)

{

	if(!x)return;

	tag[x]^=v;

	if(dep&&(v>>(dep-1))&1)swap(lc[x],rc[x]);

	int t0,t1;

	t0=(((U^v)&p0[x])|(v&p1[x]));

	t1=(((U^v)&p1[x])|(v&p0[x]));

	p0[x]=t0,p1[x]=t1;

}

void down(int x,int dep)

{

	if(tag[x])

	{

		Xor(lc[x],dep-1,tag[x]);

		Xor(rc[x],dep-1,tag[x]);

		tag[x]=0;

	}

}

void insert(int&x,int l,int r,int p)

{

	if(!x)x=newnode();

	if(l==r)

	{

		c[x]=1;

		p0[x]=U^p;

		p1[x]=p;

		return;

	}

	int mid=l+r>>1;

	if(p<=mid)insert(lc[x],l,mid,p);

	else insert(rc[x],mid+1,r,p);

	up(x);

}

int query(int dep,int x,int l,int r,int ql,int qr)

{

	if(!x||l>r||ql>r||qr<l)return 0;

	if(ql==l&&qr==r)return c[x];

	down(x,dep);

	int mid=l+r>>1;

	if(qr<=mid)return query(dep-1,lc[x],l,mid,ql,qr);

	if(ql>mid)return query(dep-1,rc[x],mid+1,r,ql,qr);

	return query(dep-1,lc[x],l,mid,ql,mid)+query(dep-1,rc[x],mid+1,r,mid+1,qr);

}

void merge(int dep,int&u1,int&u2)

{

	if(!u1){swap(u1,u2);return;}

	if(!u2)return;

	down(u1,dep),down(u2,dep);

	merge(dep-1,lc[u1],lc[u2]);

	merge(dep-1,rc[u1],rc[u2]);

	if(dep)up(u1);

	del(u2);u2=0;

}

void split(int dep,int&u1,int&u2,int k)

{

	if(!u1||c[u1]==k)return;

	if(!k){u2=u1;u1=0;return;}

	down(u1,dep);

	u2=newnode();

	int v=c[lc[u1]];

	if(k>v)split(dep-1,rc[u1],rc[u2],k-v);

	else swap(rc[u1],rc[u2]);

	if(k<v)split(dep-1,lc[u1],lc[u2],k);

	if(!lc[u2]&&!rc[u2])

	{

		c[u2]=c[u1]-k;

		p0[u2]=p0[u1];

		p1[u2]=p1[u1];

		c[u1]=k;

		p0[u1]=p1[u1]=0;

	}

	else up(u1),up(u2);

}

void Or(int x,int dep,int v)

{

	if(!x||!dep||!((v&((1<<dep)-1))&p0[x]))return;

	if(!(v&p0[x]&p1[x]))

	{

		Xor(x,dep,v&p0[x]);

		return;

	}

	down(x,dep);

	if((v>>(dep-1))&1)

	{

		Xor(lc[x],dep-1,1<<(dep-1));

		merge(dep-1,rc[x],lc[x]);

		Or(rc[x],dep-1,v);

	}

	else

	{

		Or(lc[x],dep-1,v);

		Or(rc[x],dep-1,v);

	}

	up(x);

}

int main()

{

//	freopen("in","r",stdin);

//	freopen("out","w",stdout);

	n=read(),q=read();

	for(int i=1;i<=n;i++)insert(root,0,U,read());

	while(q--)

	{

		int o=read(),l=read(),r=read();

		int k1=query(W,root,0,U,0,l-1);

		int k2=query(W,root,0,U,0,r);

		int tmp1=0,tmp2=0;

		split(W,root,tmp2,k2);

		split(W,root,tmp1,k1);

		if(o==1)

		{

			Xor(tmp1,W,U);

			Or(tmp1,W,U^read());

			Xor(tmp1,W,U);

		}

		else if(o==2)Or(tmp1,W,read());

		else if(o==3)Xor(tmp1,W,read());

		else if(o==4)printf("%d\n",c[tmp1]);

		merge(W,root,tmp1);

		merge(W,root,tmp2);

	}

}