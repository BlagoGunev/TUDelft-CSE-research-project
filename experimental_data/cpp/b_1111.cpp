#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cstring>
#include <fstream>
#define ll long long int
using namespace std;
const double _pi = acos(-1.0);
int main()
{
    //freopen("in.txt", "r", stdin);
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);
	vector<int> v(n);
	for(int i = 0;  i < n; i++) scanf("%d", &v[i]);
	sort(v.begin(), v.end(), greater<int>());
	double mx = 0.0;
	double sum = 0.0;
	for(int i = 0; i < n; i++)
	{
		sum += v[i];
		if(n - i - 1 <= m)
		{
			double t = m - (n - i - 1);
			double t2 = (sum + min(double(i + 1) * double(k), t)) / double(i + 1);
			mx = max(mx, t2);
		}
	}
	printf("%.20lf\n", mx);
	return 0;
}