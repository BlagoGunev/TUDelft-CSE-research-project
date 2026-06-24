// :)

#include <iostream>

#include <string>

#include <vector>

#include <queue>



#define pb push_back



using namespace std;



int n;

string s[107];

vector < int > adj[30];

vector < char > sol;

int deg[30];

queue < int > Q;



pair < char, char > check(string word1, string word2)

{

	pair < char, char > u;

	for (int i = 0; i < min(word1.size(), word2.size()); i++) {

		if (word1[i] != word2[i]) {

			u.first = word1[i];

			u.second = word2[i];

			return u;

		}

	}

	u.first = u.second = '+';

	return u;

}



int main()

{

	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> s[i];

	}

	for (int i = 0; i < n - 1; i++) {

		pair < char, char > c = check(s[i], s[i + 1]);

		if (c.first == '+' &&  s[i].size() > s[i + 1].size()) {

			cout << "Impossible\n";

			return 0;

		}

		if (c.first == '+') {

			continue;

		}

		adj[c.first - 'a'].pb(c.second - 'a');

		deg[c.second - 'a']++;

	}

	for (int i = 0; i < 26; i++) {

		if (deg[i] == 0) {

			Q.push(i);

		}

	}

	while (!Q.empty()) {

		int u = Q.front();

		Q.pop();

		sol.pb((char)(u + ((int)'a')));

		for (int i = 0; i < adj[u].size(); i++) {

			deg[adj[u][i]]--;

			if (deg[adj[u][i]] == 0)

				Q.push(adj[u][i]);

		}

	}

	if (sol.size() != 26) {

		cout << "Impossible\n";

	}

	else {

		for (int i = 0; i < 26; i++) {

			cout << sol[i];

		}

		cout << endl;

	}

	return 0;

}