#include <bits/stdc++.h>

#define MAXN (1000010)
#define ll long long

int n;
int a[MAXN], l[MAXN], r[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i){
	    scanf("%d", a + i);
	}
	
	a[0] = a[n + 1] = MAXN;
	std::stack<int> stack;
	for(int i = 0; i <= n + 1; ++ i){
		while(!stack.empty() && a[stack.top()] < a[i]){
			r[stack.top()] = i;
			stack.pop();
		}
		if(!stack.empty()){
			l[i] = stack.top();
		}
		stack.push(i);
	}
	
	ll ans = 0;
	for(int i = 1; i <= n; ++ i) ans += 1ll * a[i] * (i - l[i]) * (r[i] - i);
	
	a[0] = a[n + 1] = - MAXN;
	while(!stack.empty()) stack.pop();
	for(int i = 0; i <= n + 1; ++ i){
		while(!stack.empty() && a[stack.top()] > a[i]){
			r[stack.top()] = i;
			stack.pop();
		}
		if(!stack.empty()){
			l[i] = stack.top();
		}
		stack.push(i);
	}
	
	for(int i = 1; i <= n; ++ i) ans -= 1ll * a[i] * (i - l[i]) * (r[i] - i);
	
	printf("%I64d\n", ans);
	return 0;
}