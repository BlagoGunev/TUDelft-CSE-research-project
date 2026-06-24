#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long unsigned llu;
typedef long double ld;

const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

int possibleCnt[26];

int main(){
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int n;
	cin >> n;
	cin.ignore();
	int elecCnt = 0;
	int ans = 0;
	while(n--){
		string str;
		getline(cin, str);
		int sz = str.size(); 
		if(str[0] == '!'){
			int chk = 0;
			bool isUsed[26] = {0};
			for(int i = 0; i < 26; i++){
				if(possibleCnt[i] == elecCnt){
					chk++;
				}
			}
			if(chk == 1) ans++;
			for(int i = 2; i < sz; i++){
				if(!isUsed[str[i] - 'a']){
					isUsed[str[i] - 'a'] = true;
					possibleCnt[str[i] - 'a']++;
				}
			}
			elecCnt++;
		}
		if(str[0] == '.'){
			for(int i = 2; i < sz; i++) possibleCnt[str[i] - 'a'] = -inf;
		}
		if(str[0] == '?'){
			int chk = 0, p = -1;
			for(int i = 0; i < 26; i++){
				if(possibleCnt[i] == elecCnt){
					chk++;
					p = i;
				}
			}
			if(chk == 1 && str[2] - 'a' != p) ans++;
			possibleCnt[str[2] - 'a'] = -inf;
		}
	}
	printf("%d", ans);
	return 0;
}