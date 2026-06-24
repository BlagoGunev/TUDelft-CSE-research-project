#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 2147483647;
const double EPS = 1e-15;
const double PI = 3.1415926;
const int MOD = 998244353;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

const int MAX_SIZE = 300005;
const int THREASHOLD = 100;



int a[200005];
int inc[200005];

int main() {

#ifdef LOCALLL
	//freopen("out", "w", stdout);
#endif
	int n;
	stack<int> st;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(!st.empty() && (st.top() - a[i]) % 2 == 0){
			st.pop();
		}
		else {
			st.push(a[i]);
		}
	}
	bool ook = true;
	int ddl = -1;
	while(!st.empty()){
		int k = st.top();
		if(ddl == -1){
			ddl = k % 2;
		}
		else{
			if(ddl != k % 2) {
				ook = false;
				break;
			}
		}
		st.pop();
	}
	if(ook)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}