#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define EPS 1e-7
typedef long long int LL;

using namespace std;

struct P{
	double x,y;
	P(){}
	P(double xx,double yy):x(xx),y(yy){}
	void input(){scanf("%lf%lf",&x,&y);}
	void print(){printf("%lf,%lf\n",x,y);}
	P operator+(P b){return P(x+b.x,y+b.y);}
	P operator-(P b){return P(x-b.x,y-b.y);}
	P operator*(double t){return P(x*t,y*t);}
	P operator/(double t){return P(x/t,y/t);}
};

struct Line{
	P p,q;
	Line(){}
};

int n;
P c[110];

double dot(P a,P b){return a.x*b.x+a.y*b.y;}
double cross(P a,P b){return a.x*b.y-a.y*b.x;}
double cross(P o,P a,P b){return cross(a-o,b-o);}
double dis(P a){return sqrt(a.x*a.x+a.y*a.y);}
double dis(P a,P b){return dis(a-b);}

P ret(P a){return P(a.y,-a.x);}

int bad(P p,P q,P r){
	//return abs(cross(p,q,r))<EPS;
	double t = min(dot(q-p,r-p),min(dot(p-q,r-q),dot(p-r,q-r)));
	if(t<-EPS)return -1;
	else if (t<EPS)return 0;
	return 1;
}

P itp(P a,P b,double ta,double tb){
	return (a*tb+b*ta)/(ta+tb);
}

P intersect(Line l1,Line l2){
	double ta=cross(l1.p,l2.p,l2.q);
	double tb=cross(l1.q,l2.p,l2.q);
	return itp(l1.p, l1.q, ta, -tb);
}

P get(P p,P q,P r){
	Line la,lb;
	la.p = (p+q)/2;
	la.q = la.p + ret(p-q);
	lb.p = (p+r)/2;
	lb.q = lb.p + ret(p-r);

	return intersect(la,lb);
}

bool shik(P o,P a,P b){
	return dis(a+b,o+o)<EPS;
}

double go(int p,int q,int r){
	int cd = bad(c[p],c[q],c[r]);
	if(cd==-1)return -1;

	P tar = get(c[p],c[q],c[r]);

	//printf("%d %d %d\n",p,q,r); tar.print();
	double d = dis(tar,c[p]);
	for(int i=0;i<n;i++){
		if(dis(tar,c[i])+EPS<d) return -1;
	}
	if(cd ==0 ){
		bool has[3];
		for(int i=0;i<3;i++)has[i]=false;
		for(int i=0;i<n;i++){
			if(shik(tar,c[i],c[p]))has[0]++;
			if(shik(tar,c[i],c[q]))has[1]++;
			if(shik(tar,c[i],c[r]))has[2]++;
		}	
		if(!has[0] || !has[1] || !has[2])return -1;
	}
	//cout << d << endl;
	return d;
}

int main(){

	scanf("%d",&n);
	for(int i=0;i<n;i++)c[i].input();
	double mx=-1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				mx = max(mx,go(i,j,k));
			}
		}
	}
	if(mx<-0.5)puts("-1");
	else printf("%.8lf\n",mx);
	return 0;
}