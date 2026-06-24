#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define endl "\n"

using namespace std;
const long long M = 100010;
long long a[M], b[M], sum[M];
long long ans=1;
long long  n, m, k, l;
string s[11];

typedef pair<int, int> PII;
struct node {
	long long  a;
	int b;
};
node nn[M];
int con(node nn,node mm) {
	return nn.a > mm.a;
}
int con1(node nn, node mm) {
	return nn.b > mm.b;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> nn[i].a >> nn[i].b;
		}
		int max1 = nn[0].a;
		int max2 = nn[0].b;
			for (int i = 1; i < m; i++) {
				if (nn[i].b>=max2 && max1<=nn[i].a) {
					k = 1;
					break;
				}
				else {
					k = 0;
				}
			}
		if (k == 1) {
			cout << -1 << endl;
		}
		else {
			cout << max1 << endl;
		}
	}
}