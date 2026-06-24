#include <iostream>

using namespace std;

typedef long long ll;
#define x first
#define y second
#define mp make_pair

string s;
int n;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int temp;
cin >> temp;
while(temp--){
	cin >> s;
	n = (int)s.size();
	if(s[0] == '?'){
		if((int)s.size() == 1 || s[1] != 'a'){
			s[0] = 'a';
		}
		else{
			s[0] = 'b';
		}
	}
	if(s[n - 1] == '?'){
		if((int)s.size() == 1 || s[n - 2] != 'a'){
			s[n - 1] = 'a';
		}
		else{
			s[n - 1] = 'b';
		}
	}
	for(int i = 1 ; i < n - 1 ; ++i){
		if(s[i] != '?')
			continue;
		for(int j = 'a' ; j <= 'c' ; ++j){
			if(j != s[i - 1] && j != s[i + 1]){
				s[i] = j;
			}
		}
	}
	bool p = 1;
	for(int i = 0 ; i < n - 1 ; ++i){
		if(s[i] == '?' || s[i] == s[i + 1]){
			p = 0;
			break;
		}
	}
	if(s[n - 1] == '?'){
		p = 0;
	}
	if(p){
		cout << s << endl;
	}
	else{
		cout << -1 << endl;
	}
}

return 0;
}