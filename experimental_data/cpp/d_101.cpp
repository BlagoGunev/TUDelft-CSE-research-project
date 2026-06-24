#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cassert>

using namespace std;

const int MAXN = 100005, MAXE = 2 * MAXN;

int N;
int parent[MAXN];

int eadj[MAXE], eprev[MAXE], ecost[MAXE], elast[MAXN], eind;
inline void addedge(int a, int b, int c) {
	eadj[eind] = b; ecost[eind] = c; eprev[eind] = elast[a]; elast[a] = eind++;
}

long long num[MAXN], sum[MAXN], trav[MAXN];
bool vis[MAXN];

#define ll long long

struct state {
	long long n, s, t;
};

inline bool comp(int a, int b) {
	return (num[b] * trav[a] < num[a] * trav[b]);
}

inline state make_state(int ind) {
	return ((state){num[ind], sum[ind], trav[ind]});
}

inline state cram(state x, state y) {
	return ((state){x.n + y.n, x.s + y.s + x.t * y.n, x.t + y.t});
}

inline void DFS(int v) {
	assert(vis[v] == false);
	vis[v] = true;
	
	num[v] = 1;
	sum[v] = trav[v] = 0;
	
	bool isLeaf = true;
	vector< int > nei;
	
	for(int e = elast[v]; e != -1 ; e = eprev[e]) {
		if (!vis[eadj[e]]) {
			parent[eadj[e]] = v;
			DFS(eadj[e]);
			
			nei.push_back(eadj[e]);
			
			num[v] += num[eadj[e]];
			trav[eadj[e]] += (ecost[e] * 2);
			isLeaf = false;
		}
	}
	
	if (!isLeaf) {
		long long add = 0;
		for(int e = elast[v] ; e != -1 ; e = eprev[e]) {
			if (eadj[e] != parent[v]) {
				add += (num[eadj[e]] * ecost[e]);
			}
		}
		
		//printf("add %d : %d\n", v, add);
		
		sort(nei.begin(), nei.end(), comp);
		int L = nei.size();
		
		state z = make_state(nei[0]);
		for(int i = 1 ; i < L ; i++) {
			z = cram(z, make_state(nei[i]));
		}
		sum[v] = z.s + add;
		trav[v] = z.t;
	}
}

int main() {
	memset(parent, -1, sizeof(parent));
	memset(elast, -1, sizeof(elast));
	scanf("%d",&N);
	for(int a, b, c, i = 1 ; i < N ; i++) {
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		addedge(a, b, c);
		addedge(b, a, c);		
	}
	DFS(0);
	/*for(int i = 0 ; i < N ; i++) {
		cout << i << " " << num[i] << " " << sum[i] << " " << trav[i] << endl;
	}*/
	double ans = ((double)sum[0]) / ((double)(N - 1));
	printf("%.9lf\n",ans);
	return 0;
}