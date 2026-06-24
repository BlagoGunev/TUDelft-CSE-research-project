#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 2e5+4;

int vertex[Maxn],tail[Maxn],nxt[Maxn],length,num[Maxn];

int q[Maxn],front,rear,deep[Maxn],f[Maxn],small;

int n,x,y;

void add_edge(int x, int y) {
	++num[y];
	vertex[++length] = x;
	nxt[length] = tail[y];
	tail[y] = length;
}

void add_edge2(int x, int y) {
	add_edge(x, y);
	add_edge(y, x);
}

void bfs(int root) {
	bool t[Maxn];
	memset(t,0,sizeof(t));
	memset(deep,0,sizeof(deep));
	front = 0;
	rear = 1;
	q[front] = root;
	small = 0;
	f[root] = 0;
	while (front<rear) {
		int x = q[front];
		t[x] = true;
		int k = tail[x];
		bool p = false;
		while (k) {
			int u = vertex[k];
			if (! t[u]) {
				p = true;
				q[rear] = u;
				deep[rear] = deep[front] + 1;
				f[u] = x;
				rear++;
			}
			k = nxt[k];
		}
		if (!p) {
			if (small==0) small = x;
		}
		front++;
	}
}

int get_force_point() {
	bfs(1);
	return q[rear-1];
}

int get_mid_point(int root) {
	bfs(root);
	int d = deep[rear-1];
	if (d&1) return 0;
	d = d/2;
	int x = q[rear-1];
	for (int i=0;i<d;i++) x = f[x];
	return x;
}

bool judge(int root) {
	bfs(root);
	int i = 0;
	int j = 0;
	while (i<rear) {
		while (j<rear & deep[i]==deep[j]) j++;
		for (int k =i;k<j;k++)
			if (num[q[k]] != num[q[i]]) return false; 
		i = j;
	}
	return true;
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		scanf("%d %d",&x,&y);
		add_edge2(x,y); 
	}
	
	int root = get_force_point();
	//printf("%d\n",root);
	int mid = get_mid_point(root);
	int p1 = small;
	int p2 = root;
	int p3 = q[rear-1];
	if (mid) {
		if (judge(mid)) {
			printf("%d\n",mid);
			return 0;
		}
	}
	int p4 = small;
	if (judge(p1)) {
		printf("%d\n",p1);
		return 0;
	}
	if (judge(p2)) {
		printf("%d\n",p2);
		return 0;
	}
	if (judge(p3)) {
		printf("%d\n",p3);
		return 0;
	}
	if (judge(p4)) {
		printf("%d\n",p4);
		return 0;
	}
	printf("-1\n");
	return 0;
}