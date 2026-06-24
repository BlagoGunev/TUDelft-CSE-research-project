#include<iostream>

using namespace std;

int n, m, x, y, a, b;

int gcd(int a, int b){

	return b==0?a:gcd(b,a%b);

}

int x1, x2, y1, y2, dx, dy;

int main(){

	cin>>n>>m>>x>>y>>a>>b;

	int t=gcd(a,b);

	a/=t;b/=t;

	t=min(n/a, m/b);

	dx=a*t;dy=b*t;

	x1=x-(dx+1)/2;

	x2=x+dx/2;

	y1=y-(dy+1)/2;

	y2=y+dy/2;

	if(x1<0){

		x2+=-x1;

		x1=0;

	}

	if(y1<0){

		y2+=-y1;

		y1=0;

	}

	if(x2>n){

		x1-=x2-n;

		x2=n;

	}

	if(y2>m){

		y1-=y2-m;

		y2=m;

	}

	cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;

	return 0;

}