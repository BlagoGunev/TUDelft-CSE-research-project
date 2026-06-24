#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <bitset>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <sys/time.h>
using namespace std;
#define li       	int
#define rep(i,to) for(li i=0;i<((li)(to));++i)
#define pb        push_back
#define sz(v)     ((li)(v).size())
#define bit(n)    (1ll<<(li)(n))
#define all(vec)  (vec).begin(),(vec).end()
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define MP        make_pair
#define F         first
#define S         second


#define MAX 200500
li N;
li st_dec[MAX * 4];
li st_LR[MAX * 4];
set<pair<li, li> > L;
set<pair<li, li> > D;

li getLR(li v, li l, li r, li left, li right)
{
	if(left <= l && r <= right) return st_LR[v];
	if(right <= l || r <= left) return 0;
	li mid = (l + r) >> 1;
	li res0 = getLR(v * 2 + 0, l, mid, left, right);
	li res1 = getLR(v * 2 + 1, mid, r, left, right);
	return max(res0, res1);
}

li getDec(li v, li l, li r, li left, li right)
{
	if(left <= l && r <= right) return st_dec[v];
	if(right <= l || r <= left) return 0;
	li mid = (l + r) >> 1;
	li res0 = getDec(v * 2 + 0, l, mid, left, right);
	li res1 = getDec(v * 2 + 1, mid, r, left, right);
	return max(res0, res1);
}

void add(li index, li height, li a)
{
//cout << "add : " << index << " " << height << " " << a << endl;
	index += N;
	height += N;
	st_dec[height] = a;
	st_LR[index] = a;
	while(1 < height){
		height >>= 1;
		st_dec[height] = max(st_dec[height * 2 + 0], st_dec[height * 2 + 1]);
	}
	while(1 < index){
		index >>= 1;
		st_LR[index] = max(st_LR[index * 2 + 0], st_LR[index * 2 + 1]);
	}
}


int main()
{
	li n, q;
	cin >> n >> q;
	for(N = 1; N * 2 < MAX * 2; N *= 2);
	rep(i, q){
		li t;
		cin >> t;
		if(t == 1){
			li index, height;
			cin >> index >> height;
			height += (q - i);
			vector<pair<li, li> > V;
			while(sz(D) && D.begin()->F < height){
				V.pb(*D.begin());
				L.erase(MP(D.begin()->S, D.begin()->F));
				add(D.begin()->S, D.begin()->F, 0);
				D.erase(*D.begin());
			}
			V.pb(MP(height, index));
			reverse(all(V));
			rep(j, sz(V)) add(V[j].S, V[j].F, getLR(1, 0, N, V[j].S + 1, N) + 1);
			rep(j, sz(V)) L.insert(MP(V[j].S, V[j].F));
			rep(j, sz(V)) D.insert(MP(V[j].F, V[j].S));
		}else{
			li k;
			cin >> k;
			vector<pair<li, li> > V;
			while(sz(V) < k){
				V.pb(*L.begin());
				D.erase(MP(L.begin()->S, L.begin()->F));
				add(L.begin()->F, L.begin()->S, 0);
				L.erase(*L.begin());
			}
			V.pop_back();
			reverse(all(V));
			rep(j, sz(V)) add(V[j].F, V[j].S, getDec(1, 0, N, V[j].S + 1, N) + 1);
			rep(j, sz(V)) L.insert(MP(V[j].F, V[j].S));
			rep(j, sz(V)) D.insert(MP(V[j].S, V[j].F));
		}
		cout << getLR(1, 0, N, 0, N) << endl;
	}
}