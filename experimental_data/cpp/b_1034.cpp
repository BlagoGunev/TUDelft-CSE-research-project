#include<bits/stdc++.h>
#define ll long long
using namespace std;
void qmax(int &x,int y) {if (x<y) x=y;}
void qmin(int &x,int y) {if (x>y) x=y;}
inline ll read()
{
    char s;
    ll k=0,base=1;
    while((s=getchar())!='-'&&s!=EOF&&!(isdigit(s)));
    if(s==EOF)exit(0);
    if(s=='-')base=-1,s=getchar();
    while(isdigit(s)){k=k*10+(s^'0');s=getchar();}
    return k*base;
}
inline void write(int x)
{
    static char cnt,num[15];cnt=0;
    if (!x)
    {
        printf("0");
        return;
    }
    for (;x;x/=10) num[++cnt]=x%10;
    for (;cnt;putchar(num[cnt--]+48));
}
int n,m;
int main()
{
	n=read();m=read();
	if (n>m) swap(n,m);
	if (n>=3)
	{
		ll ans=(ll)n*m;
		ans=ans/2*2;
		cout<<ans;
		return 0;
	}
	ll N=n,M=m;
	if ((n%6==0||m%6==0)||(N%4==0&&M!=1)||(M%4==0&&N!=1))
	{
		ll ans=N*M;
		cout<<ans;
		return 0;
	}
	ll ans=N*M;
	if (m<n) swap(n,m);
	if (n==1)
	{
		ans=m/6*6+max(0,(m%6-3)*2);
		cout<<ans;
		return 0;
	}
	if (n==2)
	{
		if (m<=2) ans-=4;
		if (m==3||m==7) ans-=2;
		cout<<ans;
		return 0;
	}
	return 0;
}