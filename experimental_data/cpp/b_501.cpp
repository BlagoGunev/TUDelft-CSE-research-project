#include <bits/stdc++.h>



using namespace std;



map <string, string> oldName;

string s1, s2;

int n;

map<string, string>::iterator it;

int main()

{

	//freopen("IN.txt", "rt", stdin);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)

	{

		cin >> s1 >> s2;

		if (oldName.find(s1) == oldName.end())

		{

			oldName[s2] = s1;

		}

		else

		{

			oldName[s2] = oldName[s1];

			oldName.erase(s1);

		}

	}



	cout << oldName.size() << endl;

	for(it = oldName.begin(); it != oldName.end(); it++)

	{

		cout << it->second << " " << it->first << endl;

	}

	return 0;

}