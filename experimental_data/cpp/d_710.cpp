#include <bits/stdc++.h>
#include<cstdio>

#include<iostream>

#include<cstring>

#include<cmath>

#include<map>

#include<queue>

#include<vector>

#include<algorithm>



using namespace std;

typedef long long ll;

typedef vector<int> vi;

ll getint(){

	ll x=0,f=1;

	char ch=getchar();

	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}

	while('0'<=ch&&ch<='9'){x=x*10+ch-'0';ch=getchar();}

	return f*x;

}

ll _gcd(ll a,ll b){

	if(b==0)return a;

	return _gcd(b,a%b);

}

ll x,y;

ll ex_gcd(ll a,ll b){

	if(b==0){

		x=1,y=0;

		return a;

	}

	ll res=ex_gcd(b,a%b);

	ll t=x;x=y;y=t-a/b*y;

	return res;

}

ll a1,a2,b1,b2,L,R;

ll f(ll x){

//	cout<<"f("<<x<<")=="<<a1<<"*"<<x<<"+"<<b1<<"=="<<a1*x+b1<<endl;

	return a1*x+b1;

}

int main(){

	a1=getint();b1=getint();a2=getint();b2=getint();L=getint();R=getint();

	ll gcd=_gcd(a1,a2);

	ll lcm=a1/gcd*a2;

	if(b1>b2){

		swap(a1,a2);

		swap(b1,b2);

	}

	ll c=b2-b1;

	if(c%gcd!=0){

		printf("0\n");

		return 0;

	}

	ex_gcd(a1,a2);

//	cout<<lcm<<endl;

	c/=gcd;

	x*=c;y*=-c;

//	cout<<x<<" "<<y<<endl;

	ll dx=lcm/a1,dy=lcm/a2;

	c=0;

	if(x<0)	c=max(c,ll(ceil(double(-x)/double(dx))));

	if(y<0)	c=max(c,ll(ceil(double(-y)/double(dy))));

	x+=c*dx;

	y+=c*dy;

	ll c1=0,c2=0;

	if(x>0)	c1=ll(ceil(double(-x)/double(dx)));

	if(y>0)	c2=ll(ceil(double(-y)/double(dy)));

	c=max(c1,c2);

	x+=c*dx;

	y+=c*dy;

//	cout<<x<<" "<<y<<endl;

	ll t=f(x);

//	cout<<t<<endl;

	if(t<L)t+=ceil(double(L-t)/double(lcm))*lcm;

//	cout<<t<<endl;

	if(t>R){

		printf("0\n");

		return 0;

	}

	ll ans=(R-t)/lcm;

	printf("%lld",ans+1);

	return 0;

}