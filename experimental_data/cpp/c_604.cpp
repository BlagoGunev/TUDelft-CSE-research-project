#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1 << 30;
char buf[100010];
int dp[3][2];
int basis[3][2];
const int ex[2] = { 1,0 };

int main() {
				int n;
				scanf("%d", &n);
				scanf("%s", buf);
				int tmp = (buf[0] == '0' ? 0 : 1);

				dp[0][tmp] = basis[0][tmp] = 1;
				dp[1][ex[tmp]] = basis[1][ex[tmp]] = 1;

				for (int i = 1; i < n; i++) {
								int now = (buf[i] == '0' ? 0 : 1);
								//0
								dp[0][now] = basis[0][ex[now]] + 1;
								//1
								dp[1][ex[now]] = max(basis[0][now], basis[1][now]) + 1;
								//2
								dp[2][now] = max(basis[2][ex[now]], basis[1][ex[now]]) + 1;
								for (int j = 0; j < 3; j++) {
												for (int k = 0; k < 2; k++) {
																basis[j][k] = dp[j][k];
												}
								}
				}

				tmp = 0;
								for (int j = 0; j < 3; j++)
												for (int k = 0; k < 2; k++)
																tmp = max(tmp, dp[j][k]);

				printf("%d\n", tmp);
				return 0;
}