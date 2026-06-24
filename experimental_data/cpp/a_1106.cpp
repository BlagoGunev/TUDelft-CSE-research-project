#include <bits/stdc++.h>
using namespace std;
#define mkpr make_pair
#define ft first
#define sd second

typedef pair<int, int> PII;
typedef long long LL;
const int MAXN=100011;
char s[1111][1111];
int n;

int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;++i) {
		scanf("%s", s[i]+1);
	}
	int ans=0;
	for(int i=2;i<n;++i) {
		for(int j=2;j<n;++j) {
			if(s[i][j]=='X' && s[i-1][j-1]=='X' && s[i-1][j+1]=='X' && s[i+1][j-1]=='X' && s[i+1][j+1]=='X') {
				++ans;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}