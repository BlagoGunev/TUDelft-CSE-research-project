#include <iostream>

#include <stdio.h>

#include <algorithm>

#include <string>

#include <string.h>

#include <vector>

#include <memory.h>

#include <set>

#include <stack>

#include <map>

#include <list>

#include <math.h>

#define f(i,x,n) for (int i = x; i < n; ++i)

typedef long long ll;



using namespace std;

int n, m;

string ans;



int main() {

	scanf("%d%d", &n, &m);

	if (m > (n+1)*2 || n-m > 1)

	{

		printf("-1\n");

	}

	else

	{

		while (m > n+1 && n > 0 && m > 0)

		{

			ans += '1';

			ans += '1';

			ans += '0';

			m -= 2;

			n--;

		}

		if (n > m)

		{

			ans += '0';

			--n;

		}

		while (n > 0 || m > 0)

		{

			if (m > 0)

			{

				ans += '1';

				--m;

			}

			if (n > 0)

			{

				ans += '0';

				--n;

			}

		}

	}

	cout << ans << endl;

	return 0;

}