#include<bits/stdc++.h>

using namespace std;

void solve(){
	long long int n, k, b, s;
	cin >> n >> k >> b >> s;
	long long int p[n+1]{0};
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
	}
	long long int a[n+1]{0};
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	long long int ansb = 0, anss = 0, curb = 0, curs = 0;
	for (int i = 1; i <= min(n, k); i++)
	{
		curb += a[b];
		ansb = max(ansb, curb + a[b]*(k-i));
		b = p[b];
		curs += a[s];
		anss = max(anss, curs + a[s]*(k-i));
		s = p[s];
	}
	if (ansb > anss) cout << "Bodya";
	else if (ansb == anss) cout << "Draw";
	else cout << "Sasha";
	//cout << " " << ansb << " " << anss;
}

int main(){
	int t = 1;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
}