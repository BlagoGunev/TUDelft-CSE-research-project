#include<iostream>

#include<algorithm>

#include<vector>

#include<list>

#include<iterator>

#include<cmath>

#include<array>

#include<string>

#include<cstring>

#include<map>



using namespace std;

typedef long long int llint;

typedef unsigned long long int ullint;

struct node {

	int index, ratio;

};



bool pred(node &a, node &b)

{

	return a.ratio < b.ratio;

}





int main()

{

	size_t n;

	cin >> n;

	vector<node> a(n);

	for (size_t i = 0; i < n; ++i)

	{

		cin >> a[i].ratio;

		a[i].index = i + 1;

	}

	sort(a.begin(), a.end(), pred);

	for (size_t i = 0; i < n / 2; ++i)

		cout << a[i].index << ' ' << a[n - i - 1].index << '\n';

	return 0;

}