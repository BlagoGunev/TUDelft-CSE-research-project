#include<cstring>
#include<cstdio>

using namespace std;

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define ms(x,y) memset(x,y,sizeof(x))

const int NN=100005;

int n,a[NN],b[NN],c[NN];
bool fl;

int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
int main()
{
	n=read();
	rep(i,1,n-1) a[i]=read();
	rep(i,1,n-1) b[i]=read();
	rep(x,0,3) if (!fl)
	{
		ms(c,0);c[1]=x;fl=1;
		rep(i,1,n-1)
		{
			int A=a[i]&1,B=b[i]&1;
			if (!A&&B) {fl=0;break;}
			if (A&&!B) {if (c[i]&1) c[i+1]+=0;else c[i+1]+=1;}
			if (!A&&!B) {if (c[i]&1) {fl=0;break;} else c[i+1]+=0;}
			if (A&&B) {if (c[i]&1) c[i+1]+=1;else {fl=0;break;}}
				A=a[i]&2,B=b[i]&2;
			if (!A&&B) {fl=0;break;}
			if (A&&!B) {if (c[i]&2) c[i+1]+=0;else c[i+1]+=2;}
			if (!A&&!B) {if (c[i]&2) {fl=0;break;} else c[i+1]+=0;}
			if (A&&B) {if (c[i]&2) c[i+1]+=2;else {fl=0;break;}}
		}
	}
	if (!fl) {puts("NO");return 0;} else puts("YES");
	rep(i,1,n) printf("%d ",c[i]);puts("");
	return 0;
}