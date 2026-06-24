#include <bits/stdc++.h>

#define maxn 100005

#define MOD 1000000007

using namespace std;

typedef long long ll;



struct Node{

	int l, r;

	friend bool operator < (const Node&a, const Node&b){

		return a.l < b.l;

	}

}node[1005];

vector<int> v;

int main(){

	

//	freopen("in.txt", "r", stdin);

	int n, t = 0;

	

	scanf("%d", &n);

	for(int i = 0; i < n; i++){

	 scanf("%d%d", &node[i].l, &node[i].r);

	 if(node[i].l > node[i].r)

	  swap(node[i].l, node[i].r);

   }

	sort(node, node+n);

	int ans = 0;

	int mins = node[0].r;

	for(int i = 1; i < n; i++){

		if(node[i].l > mins){

			ans++;

		    v.push_back(mins);

			mins = node[i].r;

		}

		else{

			mins = min(mins, node[i].r);

		}

	}

	v.push_back(mins);

	ans++;

	printf("%d\n", ans);

	printf("%d", v[0]);

	for(int i = 1; i < ans; i++)

	 printf(" %d", v[i]);

	puts("");

	

	return 0;

}