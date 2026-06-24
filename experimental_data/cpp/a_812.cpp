#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define itr iterator
#define ritr reverse_iterator
#define pint pair<int, int>
#define pll pair<ll, ll>
#define S second
#define F first
#define v(a) vector<a>
#define mk(a, b) make_pair(a, b)
#define psh(a) push_back(a)
#define mem(arr, a) memset(arr, a, sizeof(arr))
#define pr(n) printf("%d\n", n)
#define sc(n) scanf ("%d", &n)
#define scll(n) scanf ("%lld", &n)
#define prll(n) printf("%lld\n", n)
#define MOD 1000000007ll
#define inf 1000000000ll

int main (void) {
//	freopen ("input.in", "r", stdin);
	int arr[4][4];
	int i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			sc (arr[i][j]);
		}
	}

	for (i = 0; i < 4; i++) {
		if (arr[i][3] == 1){
			for (j = 0; j < 3; j++) {
				if (arr[i][j] == 1){
					cout<<"YES"<<endl;
					return 0;
				}
			}
			int pre, next;
			if (i == 0){
				pre = 3;
			}else {
				pre = i-1;
			}
			next = (i+2)%4;
			int t = (i+1)%4;
			if (arr[t][0] || arr[pre][2] || arr[next][1]){
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}

	cout<<"NO"<<endl;
	return 0;
}