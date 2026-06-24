#include <cstdio>
const int N = 3e5+5;
char s[N];
int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", s + 1);
	if(n % 2 == 1){
		printf(":(\n");
		return 0;
	}
	int left = n >> 1;
	for(int i = 1; i <= n; ++i)
		if(s[i] == '(')--left;
	if(left < 0){
		printf(":(\n");
		return 0;
	}
	for(int i = 1; i <= n; ++i)
		if(s[i] == '?'){
			if(left)s[i] = '(', --left;
			else s[i] = ')';
		}
	int cur = 0;
	for(int i = 1; i <= n - 1; ++i){
		if(s[i] == '(')++cur;
		else --cur;
		if(cur < 0){
			printf(":(\n");//永远不合法
			return 0;
		}else if(cur == 0){
			printf(":(\n");//前缀是括号序列，不合法
			return 0;
		}
	}
	if(s[n] == '(')++cur;
	else --cur;
	if(cur == 0)printf("%s", s + 1);
	else printf(":(\n");
	return 0;
}