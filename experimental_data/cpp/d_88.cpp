#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define mp make_pair
#define pb push_back
#define sqr(x) (x)*(x)

using namespace std;

const double eps = 1e-9;
const double PI = acos(-1.0);
const int INF = 1e9+7;
const int MAXN = int (2e5+7);

int n;
map <string, string> m;

string go(string s)  {
	int l = 0, r = s.size() - 1;
	while(s[l] == '&') l ++;
	while(s[r] == '*') r --;
	if(m.find(s.substr(l, r - l + 1)) == m.end())
		return "errtype";
	string t = m[s.substr(l, r - l + 1)];
	if(t == "errtype")
		return "errtype";
	for(int i = 0; i < l; i ++)
		t = '&' + t;
	for(int i = r + 1; i < s.size(); i ++)
		t = t + '*';
	l = 0, r = t.size() - 1;
	while(t[l] == '&' && t[r] == '*')
		l ++, r --;
	if(t[l] == '&')
		return "errtype";
	return t.substr(l, r - l + 1);
}

int main () { 
   	//freopen("input.in", "r", stdin);
   	//freopen("output.txt", "w", stdout);  

   	cin >> n;
   	m["void"] = "void";
   	m["errtype"] = "errtype";
   	for(int i = 0; i < n; i ++) {
   		string s, a, b;
   		cin >> s;
   		if(s[4] == 'd') {
   			cin >> a >> b;
   			a = go(a);
   			m[b] = a;		
   		} else {
   			cin >> a;
   			cout << go(a) << endl;
   		}
   	} 
   	return 0;
}