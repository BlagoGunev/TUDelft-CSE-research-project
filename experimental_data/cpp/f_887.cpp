#include <bits/stdc++.h>
 
using namespace std;

const int INF = 1'000'000'007;

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	int fi = -1, lst = INF;

	multiset<int> st;
	for (int i = n - 1; i >= 0; i--){
		if (n - i <= k){
			st.insert(a[i]);
		}
		else{
			st.insert(a[i]);
			if (*st.begin() >= a[i]){
				fi = max(fi, i);
				lst = min(lst, i);
			}
			st.erase(st.find(a[i + k]));
		}
	}

	if (fi == -1){
		cout << "YES\n";
		return;
	}

	if (lst + k <= fi){
		cout << "NO\n";
		return;
	}

	int l = fi + 1, r = lst + k;
	st.clear();
	set<int> st2;
	for (int i = n - k; i < n; i++){
		st2.insert(a[i]);
	}

	int pos = -1, mn = INF;
	for (int i = n - 1; i >= 0; i--){
		if (i >= l && i <= r){
			if (!st.empty()){
				auto lb = st.upper_bound(*st.begin());
				if (lb != st.end()){
					if (mn > *lb){
						mn = *lb;
						pos = i;
					}
				}
				if (n - i <= k){
					lb = st.begin();
					if (mn > *lb){
						mn = *lb;
						pos = i;
					}
				}
				else{
					auto lb2 = st2.upper_bound(*st.begin());
					if (lb2 != st2.end()){
						if (mn > *lb2){
							mn = *lb2;
							pos = i;
						}
					}
				}
			}
		}
		if (n - i <= k){
			st.insert(a[i]);
		}
		else{
			st.insert(a[i]);
			st.erase(st.find(a[i + k]));
		}
	}

	if (pos == -1){
		cout << "NO\n";
		return;
	}
	a[pos] = mn;
	st.clear();
	for (int i = n - 1; i >= 0; i--){
		if (n - i <= k){
			st.insert(a[i]);
		}
		else{
			st.insert(a[i]);
			if (*st.begin() >= a[i]){
				cout << "NO\n";
				return;
			}
			st.erase(st.find(a[i + k]));
		}
	}	

	cout << "YES\n";
}

int main()
{
#ifdef FELIX
	auto _clock_start = chrono::high_resolution_clock::now();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tests = 1;
	//cin >> tests;
	for (int test = 0; test < tests; test++){
		solve();
	}
#ifdef FELIX
	cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
		chrono::high_resolution_clock::now()
			- _clock_start).count() << "ms." << endl;
#endif
	return 0;
}