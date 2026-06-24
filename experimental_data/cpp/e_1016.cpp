#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
double zuo,you,ans,s[500010];
int x,y,L[500010],n,sy,a,b,A,B,l,r,o,R[500010],q;
double cal(double p){
	return 1.0*(y-sy)/y*(p-x)+x;
}
double BI(){
	return 1.0*(y-sy)/y;
}
double gt(int x,int y){
	if (x>y) return 0.0;
	return s[y]-s[x-1];
}
int main(){
	cin>>sy>>a>>b>>n;
	FOR(i,1,n) getint(L[i]),getint(R[i]);
	FOR(i,1,n) s[i]=s[i-1]+R[i]-L[i];
	cin>>q;
	while (q--){
		scanf("%d%d",&x,&y);
		if (cal(R[n])<a){puts("0.000000000000000");continue;}
		l=1,r=n;
		while (l<r){
			int o=l+r>>1;
			if (cal(R[o])>=a) r=o;
			else l=o+1;
		}
		A=r;
		l=1,r=n;
		while (l<r){
			int o=(l+r>>1)+1;
			if (cal(L[o])<=b) l=o;
			else r=o-1;
		}
		B=r;
		ans=gt(A+1,B-1)*BI();
		zuo=(a-x)/BI()+x;
		you=(b-x)/BI()+x;
		double zz=max(zuo,1.0*L[A]),yy=min(you,1.0*R[A]);
		ans+=max(yy-zz,0.0)*BI();
		if (A!=B){
			A=B;
			double zz=max(zuo,1.0*L[A]),yy=min(you,1.0*R[A]);
			ans+=max(yy-zz,0.0)*BI();
		}
		printf("%.10f\n",ans);
	}
    return 0;
}