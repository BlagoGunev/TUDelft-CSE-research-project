#include <bits/stdc++.h>
using namespace std;
int I, J;
char V;
char c[100001];
int T[400000];
void init(int N,int L,int R) {
	if(L == R)
		T[N] = 1 << (c[R] - 'a');
	else{
		int a = N << 1, m = (L+R) >> 1;
		init(a, L, m);
		init(a|1, m+1, R);
		T[N] = T[a] | T[a|1];
	}
}
void update(int N,int L,int R){
	if(L == R)
		T[N] = 1 << (c[R] - 'a');
	else {
		int a = N << 1,m = (L+R) >> 1;
		if(I<=m) update(a, L, m);
		else if(I>m) update(a|1, m+1, R);
		else update(a, L, m),update(a|1, m+1, R);
		T[N] = T[a] | T[a|1];
	}
}
int query(int N,int L,int R){
	if(I<=L && R <= J)
		return T[N];
	else {
		int a = N << 1,m = (L+R) >> 1;
		if(J<=m) return query(a, L, m);
		else if(I>m) return query(a|1, m+1, R);
		else return query(a, L, m) | query(a|1, m+1, R);
	}
}
int main(int argc, char const *argv[]){
	int n,v,q;
	char op[3];
	scanf("%s %d",c, &q);
	n = strlen(c);
	init(1,0,n-1);
	while(q--){
		scanf("%d",&v);
		if(v==1){
			scanf("%d %s",&v, op);
			v--;
			I = v;
			c[v] = op[0];
			update(1,0,n-1);
			}
		else {
			scanf("%d %d", &I,&J);
			I--;
			J--;
			printf("%d\n" , __builtin_popcount(query(1,0,n-1)));
			}
		}
	return 0;
}