#include <bits/stdc++.h>



using namespace std;



const int Maxn = 101000;



int a[Maxn], cnt[Maxn];

int n;



int main()

{

	//freopen("x.in","r",stdin);



	scanf("%d", &n);

	for (int i=0;i<n;++i)

		scanf("%d", &a[i]);

	sort(a, a+n);



	cnt[0] = 1;

	int tot = n;

	n = 1;

	for (int i=1;i<tot;++i)

		if (a[i] == a[n - 1]) ++ cnt[n - 1];

		else a[n] = a[i], cnt[n ++] = 1;



	long long ans = 0;

	for (long long i=1;i<=(long long)a[n - 1] * 2LL;i *= 2LL)

	{

		for (int j=0,k=n-1;j<n;++j)

		{

			while (i - a[j] < a[k] && k >= 0) --k;

			if (k >= 0 && a[j] + a[k] == i)

			{

				if (j != k) ans += (long long)cnt[j] * cnt[k];

				else ans += (long long)cnt[j] * (cnt[j] - 1);

			}	

		}

	}



	cout << ans/2 << endl;



	return 0;

}