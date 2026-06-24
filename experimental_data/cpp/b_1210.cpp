#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long ll;

pair <ll, ll> mas[7005];
bool used[7005];

int main()
{
 	ios_base::sync_with_stdio(0); cin.tie(0);
 	int n;
 	cin >> n;
 	for (int i = 1; i <= n; i++) cin >> mas[i].x;
 	for (int i = 1; i <= n; i++) cin >> mas[i].y;
 	sort(mas + 1, mas + n + 1);
 	
 	ll ans = 0;
 	int lef = 1, rig = 0;
 	while (lef <= n)
 	{
 	 	rig = lef;
 	 	while (rig + 1 <= n && mas[rig + 1].x == mas[lef].x) rig++;
 	 	if (rig > lef)
 	 	{
 	 		for (int i = 1; i <= rig; i++)
 	 			if ((mas[i].x & mas[lef].x) == mas[i].x && !used[i])
 	 			{
 	 			 	used[i] = true;
 	 			 	ans += mas[i].y;
 	 		  	}
 	 	}
 	 	lef = rig + 1;
 	}
 	cout << ans;
 	return 0;
}