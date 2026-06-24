#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<iomanip>
#include<utility>
#include<stack>
#include<list>
#include<fstream>
#define SYNC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define F(i,m,n) for(int i=m;i<=n;i++)
#define f(i,m,n) for(int i=m;i>=n;i--)
#define debug(n) if(deb==1) cout<<#n<<"="<<n<<endl
#define deb(n) if(deb==1) cout<<#n<<"="<<n<<"   "
#define div(ch) if(deb==1) { for(int i=1;i<=40;i++) cout<<#ch; cout<<endl; }
#define mm(A,n) memset(A,n,sizeof(A))
#define lowbit(x) (x&(-x))
#define PII pair<int,int>
typedef long long LL;
const int maxn = 2e5+ 10;
const int maxm = 3e7 + 10;
const int mod = 998244353;
const double eps = 1e-9;
const bool deb = 1;
using namespace std;

int B[maxn], R[maxn];
int A[maxn];

int oper() {
	int n;
	cin >> n;
	F(i, 1, n) cin >> A[i];
	char c;
	int b = 0, r = 0;
	F(i, 1, n) {
		cin >> c;
		if (c == 'B') B[++b] = A[i];
		else R[++r] = A[i];
	}
	sort(B + 1, B + b + 1);
	sort(R + 1, R + r + 1);
	int numr = 0;
	F(i, 1, r) {
		if (R[i] > b + i) return -1;
	}
	int numb = 0;
	F(i, 1, b) {
		if (B[i] < i) return -1;
	}
	return 1;
}

int main() {
	SYNC;
	int t = 1;
	cin >> t;
	while (t--) {
		if (oper() == -1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}
/*Avoid Stereotypes, Think More, and Code Less.*/
/*Instead of focusing on troublesome old ideas, it's
better to learn or think about efficient new methods*/