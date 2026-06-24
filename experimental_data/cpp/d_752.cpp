#include <bits/stdc++.h>
#define N 233333
char a[N];
int tot1=1, tot2=1, l, tree1[N][26],tree2[N][26];
std::priority_queue<int> pos[N],neg[N],zero[N];

int go(int &tot, int nxt[][26]) {
	int x=1;
	for (int i=0; i<l; ++i) {
		int &p=nxt[x][a[i]-'a'];
		x=p?p:p=++tot;
	}
	return x;
}

int order() {
	for (int p=0, q=l-1; p<q; ++p, --q)
		if (a[p]<a[q]) return 1; 
		else if (a[p]>a[q]) return -1;
	return 0;
}

int main() {
	int n;
	scanf("%d%d",&n,&l);
	for (int val,i=1; i<=n; ++i) {
		scanf("%s%d",a,&val);
		int t=order();
		if (t==0) zero[go(tot2,tree2)].push(val);
		else if (t==1) pos[go(tot1,tree1)].push(val);
		else std::reverse(a,a+l), neg[go(tot1,tree1)].push(val);
	}
	int ans=0;
	for (int i=0; i<=tot1; ++i)
		while (!pos[i].empty() && !neg[i].empty() &&
			pos[i].top()+neg[i].top()>0)
				ans+=pos[i].top()+neg[i].top(),
				pos[i].pop(), neg[i].pop();
	int max=0;
	for (int i=0; i<=tot2; ++i)
		while (!zero[i].empty()) {
			int t1=zero[i].top(); zero[i].pop();
			if (zero[i].empty()) max=std::max(max,t1);
			else {
				int t2=zero[i].top(); zero[i].pop();
				if (t1+t2>0) ans+=t1+t2, max=std::max(max,-t2);
				else max=std::max(max,t1);
			}
		}
	printf("%d\n",ans+max);
}