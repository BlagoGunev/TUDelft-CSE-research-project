#pragma comment(linker, "/STACK:1024000000,1024000000")

#include <iostream>

#include<ctime>

#include <stdio.h>

#include <fstream>

#include <iomanip>

#include <cmath>

#include <string>

#include <string.h>

#include <sstream>

#include <cctype>

#include <climits>

#include <set>

#include <map>

#include <deque>

#include <queue>

#include <vector>

#include <iterator>

#include <algorithm>

#include <stack>

#define _clr(x,y) memset(x,y,sizeof(x))//

#define _inf(x) memset(x,0x3f,sizeof(x))

#define pb push_back

#define mp make_pair

using namespace std;

const int INF = 0x3f3f3f3f;

const double eps = 1e-8;

const double delta=0.9;

typedef long long LL;

const int maxn=100+5;

int cmp(double x)

{

	if(fabs(x)<eps)return 0;

	if(x>0)return 1;return -1;

}

const double pi=acos(-1.0);

inline double sqr(double x){return x*x;}

struct point

{

	double x,y;

	point(){}

	point(double a,double b):x(a),y(b){}

	friend point operator + (const point &a,const point &b){return point(a.x+b.x,a.y+b.y);}

	friend point operator - (const point &a,const point &b){return point(a.x-b.x,a.y-b.y);}

	friend bool operator == (const point &a,const point &b){return cmp(a.x-b.x)==0&&cmp(a.y-b.y)==0;}

	friend point operator * (const point &a,const double &b){return point(a.x*b,a.y*b);}

	friend point operator * (const double &a,const point &b){return point(a*b.x,a*b.y);}

	friend point operator / (const point &a,const double &b){return point(a.x/b,a.y/b);}

	double norm(){return sqrt(sqr(x)+sqr(y));}

}tp[105];

double det(const point &a,const point &b){return a.x*b.y-a.y*b.x;}

double dot(const point &a,const point &b){return a.x*b.x+a.y*b.y;}

double dist(const point &a,const point &b){return (a-b).norm();}

struct line

{

	point a,b;

	line(){}

	line(point x,point y):a(x),b(y){}

};

double dis_point_segment(const point p,const point s,const point t)

{

	if(cmp(dot(p-s,t-s))<0) return (p-s).norm();

	if(cmp(dot(p-t,s-t))<0) return (p-t).norm();

	return fabs(det(s-p,t-p)/dist(s,t));

}

bool PointOnSegment(point p,point s,point t) {return cmp(det(p-s,t-s))==0 && cmp(dot(p-s,p-t))<=0;}

struct polygon

{

	int n;

	point a[maxn];

	polygon(){}

	int Point_In(point t)

	{

		int num=0,i,d1,d2,k;

		a[n]=a[0];

		for(i=0;i<n;i++)

		{

			if(PointOnSegment(t,a[i],a[i+1])) return 2;

			k=cmp(det(a[i+1]-a[i],t-a[i]));

			d1=cmp(a[i].y-t.y);

			d2=cmp(a[i+1].y-t.y);

			if(k>0&&d1<=0&&d2>0) num++;

			if(k<0&&d2<=0&&d1>0) num--;

		}

		return num!=0;

	}

}pol;

double val[105];

point p[3],ans;double r[3];

double cal(point &cur)

{

    double ret=0.0,val[3];

    for(int i=0;i<3;i++)

    {

    	val[i]=acos(r[i]/sqrt((p[i].x-cur.x)*(p[i].x-cur.x)+(p[i].y-cur.y)*(p[i].y-cur.y)));

	}

	for(int i=0;i<3;i++) ret+=(fabs(val[(i+1)%3]-val[i%3]));

    return ret;

}

int main()

{

	srand(time(NULL));

	for(int i=0;i<3;i++) cin>>p[i].x>>p[i].y>>r[i];pol.n=3;

	for(int i=0;i<3;i++) pol.a[i]=p[i];pol.a[3]=p[0];

	ans.x=(p[0].x+p[1].x+p[2].x)/3.0;

	ans.y=(p[0].y+p[1].y+p[2].y)/3.0;

	bool flag = 1;

	double step=10.0,val=INF;

	while(flag&&step > eps)

	{

		for(int i=0;i<20&&flag;i++)

		{

			double ang = rand();

	        point z;

	        z.x = ans.x + cos(ang) * step;

	        z.y = ans.y + sin(ang) * step;

	        double tmp=cal(z);

	        if(tmp+eps<val)

	        {

	        	val=tmp;

	        	ans=z;

	        	if(val<1e-6) flag=0;

			}

			//cout<<tmp<<endl;

		}

        step*=0.95;

	}

	if(!flag)cout<<fixed<<setprecision(5)<<ans.x+1e-6<<" "<<ans.y+1e-6<<endl;

    return 0;

}