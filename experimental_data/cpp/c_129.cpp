#include <iostream>

#include <vector>

#include <map>

#include <set>

#include <queue>

#include <stack>

#include <math.h>

#include <sstream>

#include <cmath>

#include <algorithm>

#include <memory.h>

#include <fstream>

using namespace std;

typedef long long ll;







int main() {



	vector<vector<char>> v(8, vector<char>(8));

	pair<int, int> p;

	map<string, bool> mp;

	bool win = false;

	for (int i = 0; i < 8; ++i)

		for (int j = 0; j < 8; ++j) {

			scanf(" %c", &v[i][j]);

			if (v[i][j] == 'M')

				p = { i,j };

		}



	string s = "";

	s.push_back(p.first + '0');

	s.push_back(p.second + '0');



	for (int i = 0; i < 8; ++i)

		for (int j = 0; j < 8; ++j)

			if (v[i][j] == 'S')

			{

				s.push_back(i + '0');

				s.push_back(j + '0');

			}



	queue<string> q;

	q.push(s);

	const int nr[] = { 0, 0, 0, 1, -1, 1, -1, -1, -1 };

	const int nc[] = { 0, 1, -1, 0, 0, 1, 1, -1, -1 };





	bool vis[9][9];

	while (!q.empty())

	{



		string out = q.front();

		q.pop();



		memset(vis, false, sizeof(vis));

		if (out[0] - '0' == 0 && out[1] - '0' == 7)

		{

			win = true;

			break;

		}

		bool flag = false;

		for (int i = 2; i <= out.size() - 2; i += 2)

			if (out[i] == out[0] && out[i + 1] == out[1])

				flag = true;

		if (flag)

			continue;



		string out2 = out;

		for (int i = 2; i <= out.size() - 2; i += 2)

			vis[out[i] - '0'][out[i + 1] - '0'] = true;



		for (int i = 2; i <= out.size() - 2; i += 2)

		{

			if (out[i] - '0' + 1 < 8)

			{

				++out[i];

			}

			else

			{

				out[i] = '8';

			}

		}





	

		pair<int, int> p = { out[0] - '0',out[1] - '0' };

		if (vis[p.first][p.second])

			continue;



		for (int i = 0; i < 8; ++i)

		{

			int r = p.first + nr[i];

			int c = p.second + nc[i];





			if (r >= 8 || c >= 8 || r < 0 || c < 0 || vis[r][c])



				continue;

			out[0] = r + '0';

			out[1] = c + '0';

			if (mp[out])

				continue;

			q.push(out);

			mp[out] = true;

			out[0] = p.first + '0';

			out[1] = p.second + '0';

		}







	}

	if (win)

		puts("WIN");

	else

		puts("LOSE");







	return 0;

}