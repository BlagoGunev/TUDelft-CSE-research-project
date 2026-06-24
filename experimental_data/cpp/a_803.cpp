#include <bits/stdc++.h>

using namespace std;

bool g[100][100];
int k, n;

int main()
{
	int nn, kk;
	cin >> nn >> kk;
	k = kk, n = nn;
	if (k > n * n)
	{
		cout << -1;
		return 0;
	}
	for (int i = 0; i < n; i++)
	    for (int j = 0; j < n; j++) g[i][j] = 0;
	int d = 0, i = 1;
	if (k == 1) g[0][0] = 1;
	else if (k == 2) g[0][0] = 1, g[1][1] = 1;
	else 
	{
		while (k > 2)
	    {
	    	if (!g[d][d]) k--;
		    g[d][d] = 1;
		    g[i][d] = 1;
		    g[d][i] = 1;
		    k -= 2;
		    if (k > 2 && i == n - 1)
		    {
		    	d++;
	    		i = d + 1;
	    	}
		    else if (k > 2 && i != n - 1) i++;
	    } 
	    if (k == 1) g[d + 1][d + 1] = 1;
	    else if (k == 2)
	    {
		    if (i == n - 1) g[d + 1][d + 1] = 1, g[d + 2][d + 2] = 1;
		    else g[i + 1][d] = 1, g[d][i + 1] = 1;
	    }
	}
	for (int i = 0; i < n; i++)
	{
	    for (int j = 0; j < n; j++)
	    {
	    	cout << g[i][j] << ' ';
	    	if (j == n - 1) cout << endl;
	    }
	}
	return 0;
}