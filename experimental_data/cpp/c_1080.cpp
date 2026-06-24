#include <bits/stdc++.h>
using namespace std;

struct REC {
	long long x1,x2,y1,y2;
	long long sum1, sum2;
} a,b,c;



int t;
long long n,m,sumB, sumW;

void cal(REC &a)
{
	long long l = a.x2-a.x1 +1,
			  r = a.y2-a.y1 +1;
	a.sum1 = l*r /2; 
	a.sum2 = a.sum1;

	if (l%2 && r%2) {
		if ((a.x1+a.y1)%2) ++a.sum1;
		else ++a.sum2;
	}

}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%lld%lld", &n, &m);
		scanf("%lld%lld%lld%lld", &a.x1, &a.y1, &a.x2, &a.y2);
		scanf("%lld%lld%lld%lld", &b.x1, &b.y1, &b.x2, &b.y2);
		
		sumB = n*m/2; sumW = sumB;
		if (n%2 && m%2) ++sumW;

		cal(a);
		cal(b);

		c.x1 = max(a.x1, b.x1);
		c.y1 = max(a.y1, b.y1);
		c.x2 = min(a.x2, b.x2);
		c.y2 = min(a.y2, b.y2);

		if (c.x1 <= c.x2 && c.y1 <= c.y2) {
			cal(c);
			sumB += c.sum1;
			sumW -= c.sum1;
		}
		//cout << c.sum1 << " " << c.sum2 << endl;
		
		sumB = sumB - a.sum1 + b.sum2;
		sumW = sumW - b.sum2 + a.sum1; 

		printf("%lld %lld\n", sumW, sumB);
	}

	return 0;
}