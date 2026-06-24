#include <bits/stdc++.h>

using namespace std;



char op[1];



struct Point{

	

	int x,y;

	Point (int x, int y)

	{

		this-> x = x;

		this-> y = y;

	}

	long long operator *(const Point &P) const{

		return 1LL*x*P.y-1LL*y*P.x;

	}

	Point operator -(const Point &P) const{

		return Point (x-P.x,y-P.y);

	}

};



int main()

{

	int x1,y1,x2,y2,x3,y3;

	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	Point A = {x1,y1};

	Point B = {x2,y2};

	Point C = {x3,y3};

	

	Point BC = C-A;

	Point BA = B-A;

	

	if (BA*BC == 0) puts("TOWARDS");

	else if (BA*BC < 0) puts("RIGHT");

	else puts("LEFT");

}