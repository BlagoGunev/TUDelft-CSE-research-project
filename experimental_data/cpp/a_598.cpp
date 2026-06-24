#include <bits/stdc++.h>

using namespace std;



typedef long long ll;



int main() 

{

	ios_base::sync_with_stdio(false); cin.tie(0);

	ll n,ans,aux,sub;

	int T;

	cin >> T;

	while(T--)

	{

		cin >> n;

		ans = n * (n + 1) / 2;

		aux = 1; sub = 0;

		while(aux <= n)

		{

			sub += aux;

			aux <<= 1;

		}

		ans -= 2 * sub;

		cout << ans << '\n';

	}

	return 0;

}