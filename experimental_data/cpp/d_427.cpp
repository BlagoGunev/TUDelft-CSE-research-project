#include <bits/stdc++.h>



using namespace std;



#define endl '\n'

#define MP make_pair

#define DB(x) cout << #x << "=" << x << endl



typedef long long int64;

typedef pair<int,int> pii;

typedef vector<int> vi;



const int maxn = 100010;

const int oo = 0x3f3f3f3f;



struct suffix_array

{

	int n;

	vector<int> sa, lcp, rank;



	suffix_array(const string &s) : n(s.length() + 1), sa(n), lcp(n), rank(n)

	{

		vector<int> top(max(256, n));

		for (int i = 0; i < n; ++i)

			top[rank[i] = s[i] & 0xff]++;

		partial_sum(top.begin(), top.end(), top.begin());

		for (int i = 0; i < n; ++i)

			sa[--top[rank[i]]] = i;

		vector<int> tmp(n);

		for (int len = 1, j; len < n; len <<= 1)

		{

			for (int i = 0; i < n; ++i)

			{

				j = sa[i] - len;

				if (j < 0)

					j += n;

				tmp[top[rank[j]]++] = j;

			}

			sa[tmp[top[0] = 0]] = j = 0;

			for (int i = 1, j = 0; i < n; ++i)

			{

				if (rank[tmp[i]] != rank[tmp[i - 1]]

				    || rank[tmp[i] + len] != rank[tmp[i - 1] + len])

					top[++j] = i;

				sa[tmp[i]] = j;

			}

			copy(sa.begin(), sa.end(), rank.begin());

			copy(tmp.begin(), tmp.end(), sa.begin());

			if (j >= n - 1)

				break;

		}

		int i, j, k;

		for (j = rank[lcp[i = k = 0] = 0]; i < n - 1; ++i, ++k)

		{

			while (k >= 0 && s[i] != s[sa[j - 1] + k])

				lcp[j] = k--, j = rank[sa[j] + 1];

		}

	}

};



bool ok(int a, int b, int c){

//	return true;

	if (a > b) swap(a, b);

	bool ans = a < c && c < b;



//	cout << "---> " << ans << endl;

	return ans;

}



int main(){

	ios_base::sync_with_stdio(0);

	cin.tie(0);



	string a, b;

	cin >> a >> b;

	string s = a + "#" + b;

	suffix_array sa(s);

	int n = s.length();

//	cout << s << endl;



	int ans = 0x3f3f3f3f;



	for (int i = 1; i <= n; ++i){

//		cout << i << " " << sa.sa[i] << " " << sa.lcp[i] << endl;

		if (ok(sa.sa[i], sa.sa[i - 1], (int)a.length()) &&

			(i == n || sa.lcp[i] > sa.lcp[i + 1]) && sa.lcp[i] > sa.lcp[i - 1]){

			int val = sa.lcp[i] - sa.lcp[i - 1];

			if (i < n) val = min(val, sa.lcp[i] - sa.lcp[i + 1]);

			ans = min(ans, sa.lcp[i] - (val - 1));

//			cout << "HERE" << endl;

		}

	}





	if (ans == 0x3f3f3f3f || ans == 0) ans = -1;

	cout << ans << endl;;



	return 0;

}

/*

testsetses

teeptes

 */