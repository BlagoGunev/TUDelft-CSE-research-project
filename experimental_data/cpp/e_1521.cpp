#include<bits/stdc++.h>
#define ll long long
#define scf scanf
using namespace std;
ll t, m, k, a[300000], b[1000][1000], n, sq[10000], sq2[10000], kiri, kanan, tengah, ind;
bool lebih;
pair<ll,ll>p[300000];
int main()
{
	for (ll i = 0; i < 10000; i++)
	{
		if (i % 2 == 0)
		{
			sq[i] = 3 * i * i / 4;
			sq2[i] = i * i / 2;
		}
		else
		{
			sq[i] = i * i - (i - 1) * (i - 1) / 4;
			sq2[i] = i * (i + 1) / 2;
		}
	}
	scf("%lld", &t);
	for (ll i = 0; i < t; i++)
	{
		scf("%lld%lld", &m, &k);
		kiri = 0; kanan = 9999;
		while (kiri <= kanan)
		{
			tengah = (kiri + kanan) / 2;
			if (sq[tengah] < m)
			{
				kiri = tengah + 1;
			}
			else
			{
				kanan = tengah - 1;
			}
		}
		n = kiri;
		lebih = false;
		for (ll j = 1; j <= k; j++)
		{
			scf("%lld", &a[j]);
			p[j - 1] = make_pair(a[j], j);
		}
		sort(p, p+k);
		if (n % 2 == 0)
		{
			if (p[k - 1].first > n * n / 2)
			{
				lebih = true;
			}
		}
		else
		{
			if (p[k - 1].first > n * (n + 1) / 2)
			{
				lebih = true;
			}
		}
		if (lebih)
		{
			kiri = 0; kanan = 9999;
			while (kiri <= kanan)
			{
				tengah = (kiri + kanan) / 2;
				if (sq2[tengah] < p[k - 1].first)
				{
					kiri = tengah + 1;
				}
				else
				{
					kanan = tengah - 1;
				}
			}
			n = kiri;
		}
		for (ll j = 1; j <= n; j++)
		{
			for (ll l = 1; l <= n; l++)
			{
				b[j][l] = 0;
			}
		}
		ind = k - 1;
		for (ll j = 1; j <= n; j+=2)
		{
			for (ll l = 2; l <= n; l+=2)
			{
				if (ind >= 0)
				{
					b[j][l] = p[ind].second;
					p[ind].first--;
				}
				while (ind >= 0)
				{
					if (p[ind].first > 0)
					{
						break;
					}
					else
					{
						ind--;
					}
				}
			}
		}
		for (ll j = 1; j <= n; j+=2)
		{
			for (ll l = 1; l <= n; l+=2)
			{
				if (ind >= 0)
				{
					b[j][l] = p[ind].second;
					p[ind].first--;
				}
				while (ind >= 0)
				{
					if (p[ind].first > 0)
					{
						break;
					}
					else
					{
						ind--;
					}
				}
			}
		}
		for (ll j = 2; j <= n; j+=2)
		{
			for (ll l = 1; l <= n; l+=2)
			{
				if (ind >= 0)
				{
					b[j][l] = p[ind].second;
					p[ind].first--;
				}
				while (ind >= 0)
				{
					if (p[ind].first > 0)
					{
						break;
					}
					else
					{
						ind--;
					}
				}
			}
		}
		printf("%lld\n", n);
		for (ll j = 1; j <= n; j++)
		{
			for (ll l = 1; l <= n; l++)
			{
				printf("%lld", b[j][l]);
				if (l == n)
				{
					printf("\n");
				}
				else
				{
					printf(" ");
				}
			}
		}
	}
}