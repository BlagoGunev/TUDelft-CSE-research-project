#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>

#define For(i,a,b) for(int i=a;i<=b;i++)
#define ForD(i,a,b) for (int i=a;i>=b;i--)
#define LL long long
#define INF (2147483647)
#define sqr(x)	((x)*(x))

using namespace std;

inline int read(){
    int data=0,w=1; char ch=0;
    while (ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
    if (ch=='-') w=-1,ch=getchar();
    while  (ch>='0' && ch<='9') data=data*10+ch-'0',ch=getchar();
    return data*w;
}

inline void write(int x){
	if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
} 


int n,m,k,a[100005],f[100005],q[100005];
int main(){	
	n=read(),m=read();
	For(i,1,n*m)
		a[i]=read();
	For(i,1,m){
		int r=0;		
		for(int j=i;j<=n*m;){
			int r=j;
			while (r<=n*m&&(r==j||a[r]>=a[r-m]))	r+=m;
			r-=m;
			if (r<j)	r=j;
			int c=1,l=r;
			while (l>=j)	f[l]=c,c++,l-=m;
			j=r+m;
		}
	}
	memset(q,0,sizeof(q));
	For(i,1,n*m)
		q[(i-1)/m+1]=max(q[(i-1)/m+1],f[i]);
	
	k=read();
	
	For(i,1,k){
		int l=read(),r=read();
		if (q[l]+l-1>=r)
			puts("Yes");
		else puts("No");
	}
	
}