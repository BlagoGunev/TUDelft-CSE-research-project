#include <bits/stdc++.h>

using namespace std;

#define lp(i,n) for (int i = 0; i < int(n); ++i)

#define lp1(i,n) for (int i = 1; i <= int(n); ++i)

#ifdef ONLINE_JUDGE

#define eprintf(...)

#else

#define eprintf(...) fprintf(stderr,__VA_ARGS__);fflush(stderr);

#endif // ONLINE_JUDGE

typedef long long ll;

typedef long double dbl;

const int inf = 1e9+7;

const ll llinf = 1e18+7;

const int N = 1505;

int cnt[N];





string a,bad;

int isGood(int l,int r,int k){

	int c = cnt[r] - (l?cnt[l-1]:0);

	return int(c <= k);

}

vector<int> kmp(const string& a){

 	int m = a.size();

 	vector<int> f(m);

 	for (int i = 1,k = 0; i < m; ++i){

 		while (k > 0 && a[k] != a[i])k = f[k-1];

 		if(a[k] == a[i])f[i] = ++k;

 		else f[i] = k;

	 }

	 return f;

}

int main(){

	

	

	cin >> a >> bad;

	lp(i,26)bad[i] = (bad[i] - '0')^1;

	int k;

	cin >> k;

//	vector<int> f = kmp(a);

//	for (int i = 0; i < f.size(); ++i)cout << f[i] << " ";

//	return 0;



	int n = a.size();

	for (int i = 0; i < n; ++i)cnt[i]  = (i?cnt[i-1]:0) + bad[a[i]-'a'];

	int ans = 0;

	for (int i = 0; i < n; ++i){

		string cur(a.begin(),a.begin()+i+1);

		

		reverse(cur.begin(),cur.end());

		vector<int> f = kmp(cur);

		int r = i;

		vector<int> unique(cur.size(),1);

		for (int j = 0; j < f.size(); ++j){

			if(f[j] > 0)unique[f[j]-1] = 0; 

		}

		for (int j = 0; j < unique.size(); ++j)

			if(unique[j] == 1){

				int l = i-j;

				if(isGood(l,r,k))ans++;

			}

			

		

	}

	cout << ans << endl;

}