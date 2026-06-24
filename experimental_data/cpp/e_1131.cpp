#include<bits/stdc++.h>
using namespace std;
#ifndef d
#define d(...)
#endif
#define st first
#define nd second
#define pb push_back
#define siz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
typedef long long LL;
typedef long double LD;
constexpr int INF=1e9+7;
constexpr LL INFL=1e18;
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.st << "," << P.nd << ")";
}

constexpr int maxn = 100005;

int n;
LL cnt[30], pom[30];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		//cerr << i << "; ";
		//for(int j=0; j<3; j++)
		//	cerr << cnt[j] << " ";
		//cerr << endl;
		string s; cin >> s;
		bool iden = true;
		for(int j=0; j<siz(s)-1; j++)
			if(s[j] != s[j+1]) iden = false;
			
		
		int pref = 0;
		for(int j=0; j<siz(s); j++) {
			if(s[j] == s[0]) pref++;
			else break;
		}
		int suf = 0;
		for(int j=siz(s)-1; j>=0; j--) {
			if(s[j] == s[siz(s)-1]) suf++;
			else break;
		}
		
		if(s[0] == s[siz(s)-1]) {
			if(iden) {
				pom[s[0]-'a'] = LL(cnt[s[0]-'a'] + 1) * siz(s) + cnt[s[0]-'a'];
			} else {
				pom[s[0]-'a'] = suf + pref + (cnt[s[0]-'a'] > 0);
			}	
		}
		
		pom[s[0]-'a'] = max(pom[s[0]-'a'], (LL) pref + (cnt[s[0]-'a'] > 0));
		pom[s[siz(s)-1] - 'a'] = max(pom[s[siz(s)-1] - 'a'], (LL) suf + (cnt[s[siz(s)-1] - 'a'] > 0));
		
		for(int j=0; j<siz(s);) {
			int k = j;
			while(k < siz(s) and s[j] == s[k]) k++;
			pom[s[j]-'a'] = max(pom[s[j]-'a'], (LL)k-j);
			j = k;
		}
		
		for(int i=0; i<26; i++) {
			if(cnt[i] > 0) pom[i] = max(pom[i], 1LL);
			cnt[i] = pom[i];
			pom[i] = 0;
		}
	}
	
	int res = 0;
	for(int i=0; i<26; i++)
		res = max(res, (int)cnt[i]);
	
	
	cout << res << "\n";
}