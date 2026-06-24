#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
	vector<bool> s;
	while (1)
	{
		while (s.size() > 1 && s[s.size() - 2] == s.back())
		{
			s.pop_back();
			s.pop_back();
		}
		int c = getchar();
		if (c == '+') s.push_back(true);
		else if (c == '-') s.push_back(false);
		else break;
	}
	if (s.size() == 0)
		printf("Yes\n");
	else
		printf("No\n");
    return 0;
}