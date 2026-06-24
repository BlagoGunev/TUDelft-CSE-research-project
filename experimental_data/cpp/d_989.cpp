#include<bits/stdc++.h>
#define int long long
inline int read(){
	char c=getchar();while (c!='-'&&(c<'0'||c>'9'))c=getchar();
	int k=1,kk=0;if (c=='-')c=getchar(),k=-1;
	while (c>='0'&&c<='9')kk=kk*10+c-'0',c=getchar();return kk*k;
}using namespace std;
void write(int x){if (x<0)putchar('-'),x=-x;if (x/10)write(x/10);putchar(x%10+'0');}
void writeln(int x){write(x);puts("");}
int n,l,w,x,y,xx,yy,d1,d2,dd,ans;
struct lsg{int x,y;}z[1000010],z1[1000010],z2[1000010];
bool pd(lsg x,lsg y){
	if (x.x>y.x)return 0;
	int dd=(y.x-x.x+l),xx=x.x*2+dd,yy=y.x*2+l*2-dd;
	if (x.x<0)return yy+dd*w>0;else return xx-dd*w<0;
}bool cmp(lsg x,lsg y){return x.x<y.x;}
signed main(){
	n=read();l=read();w=read();
	for (int i=1;i<=n;i++){
		x=read();y=read();
		if (x<0||(x==0&&y==-1)){
			if (y==1)xx++;
			z1[++d1].x=x;z1[d1].y=y;
		}else{
			if (y==-1)yy++;
			z2[++d2].x=x;z2[d2].y=y;
		}
	}ans=xx*yy;dd=0;sort(z1+1,z1+1+d1,cmp);
	for (int i=d1;i>=0;i--)if (z1[i].y==-1)z[++dd]=z1[i];
	for (int i=1;i<=d1;i++)if (z1[i].y==1){
		while (dd&&!pd(z1[i],z[dd]))dd--;
		ans+=dd;
	}dd=0;sort(z2+1,z2+1+d2,cmp);
	for (int i=1;i<=d2;i++)if (z2[i].y==1)z[++dd]=z2[i];
	for (int i=d2;i>=0;i--)if (z2[i].y==-1){
		while (dd&&!pd(z[dd],z2[i]))dd--;
		ans+=dd;
	}writeln(ans);
}
/*
5 1 2
0 -1
-1 1
-4 1
-2 -1
-5 1
*/