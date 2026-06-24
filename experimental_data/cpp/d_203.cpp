#include <bits/stdc++.h>

using namespace std;

double a,b,m,x,y,z;

int main() {

	cin >> a >> b >> m;

	cin >> x >> y >> z;

	double t = -m/y;

	double p = a/2 + x*t;

	double q = z*t;

	while(p < 0)

	p += 2.000000*a;

	while(p > 2.0000000*a)

	    p -= 2*a;

	if(p > a)

	    p = 2*a - p;

	while(q < 0)

	q += 2.00000000*b;    

    while(q > 2.0000000*b)

	    q -= 2*b;

	if(q > b)

	    q = 2*b - q;

	printf("%.9lf %.9lf",p,q);

	return 0;

}