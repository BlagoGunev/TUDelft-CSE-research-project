#pragma region header

/*
This code is exclusive property of Anant Simran Singh.
Any use without his consent will result in copyright violation.
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGSs
#endif
#ifndef __linux__
#define getchar_unlocked() getchar()
#endif
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<set>
#include<map>
#include<utility>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<string>
#include<climits>
#include<bitset>
#include<cfloat>
#include<sstream>
#include<iomanip>
#include<unordered_set>
#include<unordered_map>
#include<limits>
#include<numeric>
#include<functional>
using namespace std;

inline void in(char &d)
{
	d = getchar_unlocked();
	while ((d<33) || (d>126))
	{
		d = getchar_unlocked();
	}
}

int maxStringLength = 1005;
inline void in(string &str)
{
	str.clear();
	str.reserve(maxStringLength);
	char c = getchar_unlocked();
	while ((c<33) || (c>126))
	{
		c = getchar_unlocked();
	}
	while ((c >= 33) && (c <= 126))
	{
		str.push_back(c);
		c = getchar_unlocked();
	}
	return;
}

void setMaxStringLength(int length)
{
	maxStringLength = length;
}

template<typename T>
inline void in(T & t){
	char c, m = 0;
	t = 0;
	c = getchar_unlocked();
	while ((c<'0' || c>'9') && c != '-')
		c = getchar_unlocked();
	if (c == '-')
		m = 1,
		c = getchar_unlocked();
	while (c >= '0' && c <= '9'){
		t = (t << 3) + (t << 1) + c - '0';
		c = getchar_unlocked();
	}
	if (m)
		t = 0 - t;
}

void debugHere()
{
	char d = 'e';
}

#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

#pragma endregion

const double PI  =3.141592653589793238463;


double maxDistance=0,minDistance=numeric_limits<ll>::max();

double getDistance(ll x1, ll y1,ll x2, ll y2)
{
	return (x2-x1)*(x2-x1)+ (y2-y1)*(y2-y1);
}

double getDistance(double x1, double y1,double x2, double y2)
{
	return (x2-x1)*(x2-x1)+ (y2-y1)*(y2-y1);
}

bool isBetween(ll a, ll b , double c)
{
	ll d=min(a,b);
	ll e=max(a,b);
	if (c>e)
	{
		return false;
	}
	if (c<d)
	{
		return false;
	}
	return true;

}


void setDistance(ll x1, ll y1,ll x2, ll y2)
{
	double d1=getDistance(x1,y1,0,0);
	maxDistance=max(maxDistance,d1);
	double d2= getDistance(x2,y2,0,0);
	maxDistance=max(maxDistance,d2);
	double d=getDistance(x1,y1,x2,y2);
	double k= ((x2-x1)*y1 - (y2-y1)*x1)/d;
	double xp = - k * (y2-y1);
	double yp =  k * (x2-x1);
	if (isBetween(x1,x2,xp))
	{
		minDistance=min(minDistance,getDistance(xp,yp,0.0,0.0));
	}
	else
	{
		minDistance= min(minDistance,min(d1,d2));
	}

}

const int maxn=100009;

int main()
{
	int n;
	ll cx,cy;
	ll xPoints[maxn],yPoints[maxn];
	in(n);
	in(cx);
	in(cy);
	for (int i = 0; i < n; ++i)
	{
		in(xPoints[i]);
		in(yPoints[i]);
		xPoints[i]-=cx;
		yPoints[i]-=cy;	
	}
	for (int i = 0; i < n; ++i)
	{
		int next=i+1;
		if(next==n)
		{
			next=0;
		}
		setDistance(xPoints[i],yPoints[i],xPoints[next],yPoints[next]);
	}

	double ans= PI* (maxDistance-minDistance);
	cout<<setprecision(15)<<ans;




}