#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100500;
const int MAXM = 100500;

inline int read(){
	int k = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){k = k*10 + ch - '0'; ch = getchar();}
	return k * f;
}

int a[MAXN];
int buk[100];

int main(){
	int t = read();
	while(t--){
		int n = read();
		for(int i = 1; i <= n; i++){
			a[i] = read();
		}
		int ans = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] == a[i - 1]){
				ans++;
				a[i]++;
			}
			else if(a[i] > a[i - 1]){
				ans++;
			}
			else{
				a[i]++;
			}
		}
		
		printf("%d\n", ans);
	}
	return 0;
}