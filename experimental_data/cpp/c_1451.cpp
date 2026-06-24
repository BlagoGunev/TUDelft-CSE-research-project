#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 50;
int T,n,k,cnt,flag,a[maxn],b[maxn];
int read(){
	int x = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + (c ^ 48),c = getchar();
	return x;
}
int main(){
	T = read();
	while(T --){
		n = read(),k = read();
		for(int i = 0; i <= 30; i ++) a[i] = b[i] = 0;
		for(int i = 1; i <= n; i ++) a[getchar() - 'a'] ++;
		getchar();
		for(int i = 1; i <= n; i ++) b[getchar() - 'a'] ++;
		cnt = 0,flag = 0;
		for(int i = 0; i < 26; i ++){
			cnt += a[i] / k,a[i] %= k;
			if(a[i] + cnt * k < b[i] || a[i] != b[i] % k){
				flag = 1;
				break;
			}
			cnt -= b[i] / k;
		}
		if(flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}