#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <string>
#include <deque>
#include <iomanip>
#include <functional>
const double PI = std::atan(1.0) * 4;
using namespace std;
#define mp make_pair
#define all(a) a.begin(),a.end()
//#pragma comment(linker, "/STACK:104857600")
int main()
{
	/*ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");*/
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	int n, a, b, k, maxx = 0, i, count = 0, ans;
	cin >> n >> a >> b >> k;
	string s;
	getline(cin, s);
	getline(cin, s);
	for (i = 0; i < n; i++)
	{
		if (s[i] == '1') 
		{
			maxx += count / b;
			count = 0;
		}
		else count++;
	}
	maxx += count / b;
	count = 0;
	ans = maxx - a + 1; 
	cout << ans << "\n";
	count = 0;
	i = 0;
	while (maxx >= a)
	{
		if (s[i] == '1') count = 0;
		if (s[i] == '0') count++;
		if (count == b)
		{
			cout << i + 1 << " ";
			count = 0;
			maxx--;
		}
		i++;
	}
}