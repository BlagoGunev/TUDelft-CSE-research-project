#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;



const long long maxx = (long long) 4444444444 + 1;

long long l, r, javab = 0;

vector<long long> v;



void f(long long x)

{

	if(x >= maxx)

		return;

	if(x > 0)

		v.push_back(x);

	x *= 10;

	x += 4;

	f(x);

	x -= 4;

	x += 7;

	f(x);

}



int bin(long long x)

{

	int s = 0, e = v.size(), javab = -1;

	while(s < e)

	{

		int mid = (s + e) / 2;

		if(v[mid] >= x)

		{

			javab = mid;

			e = mid;

		}

		else 

			s = mid + 1;

	}

	return javab;

}



int binery(long long x)

{

	int s = 0, e = v.size(), javab = -1;

	while(s < e)

	{

		int mid = (s + e) / 2;

		if(v[mid] <= x)

		{

			javab = mid;

			s = mid + 1;

		}

		else 

			e = mid;

	}

	return javab;

}



int main()

{

	int x, y;

	cin >> l >> r;

	f(0);

	sort(v.begin(), v.end());

	x = bin(l);

	y = binery(r);

	if(x > y)

	{

		javab = (r - (l - 1)) * v[x];

		cout << javab << endl;

		return 0;

	}

	javab += (v[x] - (l - 1)) * v[x];

	for(int i = x + 1; i <= y; i++)

		javab += (v[i] - v[i - 1]) * v[i];

	javab += (r - v[y]) * v[y + 1];

	cout << javab << endl;

	return 0;

}