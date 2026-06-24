#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <set>
#define LL long long
#define mp make_pair

using namespace std;

const int maxn=100010;
const int oo=1000000000;

struct node{
	int cnt,ch[2];	
};

node trie[maxn*30];
int n,m;

void input(){
	
}

void init(){
	m = 1;
}

int get(int val, int x){
	return (val >> x) & 1;	
}

void trie_push(int pos, int x, int val){
	trie[pos].cnt++;
	if (x==31) return;
	int tmp = get(val,30-x);
	if (trie[pos].ch[tmp]==0){
		m++;
		trie[pos].ch[tmp] = m;
	}
	trie_push(trie[pos].ch[tmp], x+1, val);
}

void trie_pop(int pos, int x, int val){
	trie[pos].cnt--;
	if (x==31) return;
	int tmp = get(val,30-x);
	trie_pop(trie[pos].ch[tmp], x+1, val);
}

int count(int pos, int x, int p, int l){
	if (x==31) return 0;
	if (pos==0) return 0;
	int re = 0;
	int tmp = get(p,30-x);
	if (get(l,30-x) == 1){
		re += trie[trie[pos].ch[tmp]].cnt;
		re += count(trie[pos].ch[1-tmp], x+1, p, l);
	} else re += count(trie[pos].ch[tmp], x+1, p, l);
	return re;
}

void solve(){
	scanf("%d",&n);
	for (int c=0; c<n; c++){
		int k;
		scanf("%d",&k);
		if (k==1){
			int p;
			scanf("%d",&p);
			trie_push(1,1,p);
		} else if (k==2){
			int p;
			scanf("%d",&p);
			trie_pop(1,1,p);
		} else{
			int p,l;
			scanf("%d %d",&p,&l);
			printf("%d \n",count(1,1,p,l));
		}
	}
	//for (int i=1; i<=m; i++) cout << i << ' ' << trie[i].cnt << ' ' << trie[i].ch[0] << ' ' << trie[i].ch[1] << endl;
}

void output(){

}

int main(){
	//freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	input();
	init();
	solve();
	output();

	return(0);
}