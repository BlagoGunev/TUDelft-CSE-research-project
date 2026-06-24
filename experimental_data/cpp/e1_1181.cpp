#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1000000010
#define N 100010
char getc(){char c=getchar();while ((c<'A'||c>'Z')&&(c<'a'||c>'z')&&(c<'0'||c>'9')) c=getchar();return c;}
int gcd(int n,int m){return m==0?n:gcd(m,n%m);}
int read()
{
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
int n,b[N<<2],t;
int cnt[N<<2];
struct data{int x1,y1,x2,y2;
}a[N],c[N];
bool solve(int l,int r)
{
	if (l==r) return 1;
	for (int i=1;i<=t;i++) cnt[i]=0;
	for (int i=l;i<=r;i++) cnt[a[i].x1+1]++,cnt[a[i].x2]--;
	int mx=0,mn=t+1;
	for (int i=l;i<=r;i++) mx=max(mx,a[i].x1),mn=min(mn,a[i].x2);
	int s=0,p=-1;
	for (int i=1;i<=t;i++)
	{
		s+=cnt[i];
		if (i>=mn&&i<=mx&&s==0) {p=i;break;}
	}
	if (p!=-1)
	{
		int u=l-1;
		for (int i=l;i<=r;i++) 
		if (a[i].x2<=p) c[++u]=a[i];
		int mid=u;
		for (int i=l;i<=r;i++)
		if (a[i].x1>=p) c[++u]=a[i];
		for (int i=l;i<=r;i++) a[i]=c[i];
		return solve(l,mid)&&solve(mid+1,r);
	}
	for (int i=1;i<=t;i++) cnt[i]=0;
	for (int i=l;i<=r;i++) cnt[a[i].y1+1]++,cnt[a[i].y2]--;
	mx=0,mn=t+1;
	for (int i=l;i<=r;i++) mx=max(mx,a[i].y1),mn=min(mn,a[i].y2);
	s=0,p=-1;
	for (int i=1;i<=t;i++)
	{
		s+=cnt[i];
		if (i>=mn&&i<=mx&&s==0) {p=i;break;}
	}
	if (p!=-1)
	{
		int u=l-1;
		for (int i=l;i<=r;i++) 
		if (a[i].y2<=p) c[++u]=a[i];
		int mid=u;
		for (int i=l;i<=r;i++)
		if (a[i].y1>=p) c[++u]=a[i];
		for (int i=l;i<=r;i++) a[i]=c[i];
		return solve(l,mid)&&solve(mid+1,r);
	}
	return 0;
}
signed main()
{
	n=read();
	for (int i=1;i<=n;i++)
	{
		b[++t]=a[i].x1=read();
		b[++t]=a[i].y1=read();
		b[++t]=a[i].x2=read();
		b[++t]=a[i].y2=read();
	}
	sort(b+1,b+t+1);
	t=unique(b+1,b+t+1)-b-1;
	for (int i=1;i<=n;i++)
	{
		a[i].x1=lower_bound(b+1,b+t+1,a[i].x1)-b;
		a[i].y1=lower_bound(b+1,b+t+1,a[i].y1)-b;
		a[i].x2=lower_bound(b+1,b+t+1,a[i].x2)-b;
		a[i].y2=lower_bound(b+1,b+t+1,a[i].y2)-b;
	}
	if (solve(1,n)) cout<<"YES";else cout<<"NO";
	return 0;
	//NOTICE LONG LONG!!!!!
}
//�ж��ܷ񻮷�ƽ��n-1��ʹ��ÿ���������ζ�����ͬһ����
//���о���