#include <bits/stdc++.h>

using namespace std;



typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;


typedef priority_queue<int, vector<int> , greater<int> > min_heap;

typedef priority_queue<int> max_heap;
typedef stringstream ss;

string do_this()
{
	int x, y;

	cin>>x>>y;

	if (x == 1 && y == 1)
		return "YES";
	if (x == 1)
		return "NO";
	if (x == 2 && y <= 3)
		return "YES";
	if (x == 2)
		return "NO";
	if (x == 3 && y <= 3)
		return "YES";
	if (x == 3)
		return "NO";

	return "YES";
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;

	while (t--)
		cout<<do_this()<<"\n";
	
	return 0;
}