#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#define N 300010
#define LL long long
using namespace std;

int n,i,m,cnt;
int b[N],c[N];

struct Mar{
	int x,y;
}a[N];

inline int Abs(int x){return (x<0)?x:-x;}
inline int Min(int a,int b){return (a<b)?a:b;}
inline void Swap(int &x,int &y){x^=y^=x^=y;}

bool cmp(const Mar a,const Mar b){
	if (a.x==b.x)
		return a.y<b.y;
	else return a.x<b.x;
}

inline int read(){
	int p=0;	char	c=getchar();
	while (c<48||c>57)	c=getchar();
	while (c>=48&&c<=57)	p=(p<<1)+(p<<3)+c-48,c=getchar();
	return p;
}

inline bool Check(int p){
	int i=0,j=0,cnt=0;
	memset(c,0,sizeof(c));
	for (i=1;i<=m;i++){
		if (a[i].x==p||a[i].y==p)	{
		cnt++;	continue;
	}
		if (a[i].x==a[i].y)	c[a[i].x]++;
		else c[a[i].x]++,c[a[i].y]++;
	}
	for (i=1;i<=n;i++)
		if (c[i]>=(m-cnt))	return 1;
	return 0;
}

int main(){
//	freopen("zht.in","r",stdin);
//	freopen("zht.out","w",stdout);
	n=read();	m=read();
	if (m==1||n==2){
		cout<<"YES"<<endl;
		return 0;
	}
	for (i=1;i<=m;i++){
		a[i].x=read();	a[i].y=read();
		if (a[i].x>a[i].y)	Swap(a[i].x,a[i].y);
	}
	for (i=1;i<=m;i++){
		b[a[i].x]++;	b[a[i].y]++;
	}
	for (i=1;i<=n;i++)
		if (b[i]>=m/2)
			if (Check(i)){
				cout<<"YES"<<endl;
				return 0;
			}
	cout<<"NO"<<endl;
	return 0;
}