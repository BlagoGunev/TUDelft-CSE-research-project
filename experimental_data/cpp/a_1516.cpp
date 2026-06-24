#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<unordered_set>
#include<map>
#include<algorithm>
#include<cmath>

#define ll long long
#define hilight(x) std::cout << "==========" << (x) << "==========\n"
#define hilight1(x) std::cout << (x) << "\n"
int arr[105];

using namespace std;
void sol()
{
	int n,k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int ind = 0;
	while (k > 0)
	{
		if (ind == n - 1)
			break;
		if (k >= arr[ind])
		{
			k -= arr[ind];
			arr[n - 1] += arr[ind];
			arr[ind] = 0;
			ind++;
		}
		else
		{
			arr[ind] -= k;
			arr[n - 1] += k;
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int main()
{
	//freopen("input.txt", "rt", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		sol();
	}
	return 0;
}