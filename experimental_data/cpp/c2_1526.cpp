#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>


using namespace std;



void sol()
{
	priority_queue<long long, vector<long long>, greater<long long>> Q;
	long long n;
	cin >> n;
	long long cnt = 0;
	long long hp = 0;
	for (int i = 0; i < n; i++)
	{
		long long e;
		cin >> e;
		if (e >= 0)
		{
			cnt++;
			hp += e;
		}
		else
		{
			if (hp + e >= 0)
			{
				Q.push(e);
				hp += e;
				cnt++;
			}
			else if(!Q.empty()&&e>Q.top())
			{
				hp -= Q.top();
				Q.pop();
				Q.push(e);
				hp += e;
			}
		}
	}
	cout << cnt;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//int t;
	//cin >> t;
	//while (t--)
	{
		sol();
	}
}