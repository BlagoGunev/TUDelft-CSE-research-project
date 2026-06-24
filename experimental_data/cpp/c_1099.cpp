#define  _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define read freopen("in.in","r",stdin)
#define write freopen("out.out","w",stdout)
using namespace std;

typedef long long ll;



int main(){
	ios::sync_with_stdio(false);
	//read; write;
	string s;
	int k;
	cin >> s >> k;
	int n = s.size();
	int candy = 0, snow = 0;
	for (int i = 0; i < n; i++){
		if (s[i] == '?') candy++;
		else if (s[i] == '*') snow++;
	}

	int len = s.size() - candy - snow;
	if (k < len - candy - snow || (k > len && snow == 0)) {
		cout << "Impossible";
		return 0;
	}
	if (k < len){
		string r;
		int c = len - k;
		for (int i = 0; i < n; i++){
			if (s[i] != '?' && s[i] != '*') r += s[i];
			else if (c > 0){
				r.pop_back();
				c--;
			}
		}
		cout << r;
	}
	else {
		string r;
		int c = k - len;
		for (int i = 0; i < n; i++){
			if (s[i] != '?' && s[i] != '*') r += s[i];
			else if (s[i] == '*' && c > 0){
				while (c--){
					r += s[i - 1];
				}
			}
		}
		cout << r;

	}
	return 0;
}