#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

char s[110][110];

int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int len1 = strlen(s[i]);
			int len2 = strlen(s[j]);
			if (len2 < len1)
				swap(s[i], s[j]);
		}
	}


	for (int i = 0; i < n - 1; i++)
	{
		bool okk = 0;
		for (int j = 0; j < strlen(s[i + 1]); j++)
		{
			if (s[i + 1][j] == s[i][0])
			{
				bool ok = 1;
				for (int k = 0; k < strlen(s[i]); k++)
				{
					if (s[i + 1][j + k] == s[i][k])
						continue;
					else
					{
						ok = 0;
						break;
					}
				}
				if (ok == 1)
					okk = 1;
			}
		}
		if (okk == 0)
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << s[i] << endl;
	//system("pause");
	return 0;
}