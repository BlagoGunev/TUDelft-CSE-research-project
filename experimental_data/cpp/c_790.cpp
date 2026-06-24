#include <bits/stdc++.h>

using namespace std;

int i,j,l,n;
char c;
vector<int> x,v,k;
int mem[77][77][77][2];
int itung_k[77],itung_v[77],itung_x[77];

int off(int pos, int pos_x, int pos_v, int pos_k) {
	int ret = 0;
	if (pos_x > pos) {
		int a = (pos_x >= 0 ? itung_x[pos_x] : 0); 
		int b = (pos >= 0 ? itung_x[pos] : 0); 
		ret += a - b;
	}
	
	if (pos_v > pos) {
		int a = (pos_v >= 0 ? itung_v[pos_v] : 0); 
		int b = (pos >= 0 ? itung_v[pos] : 0); 
		ret += a - b;
	}
	
	if (pos_k > pos) {
		int a = (pos_k >= 0 ? itung_k[pos_k] : 0); 
		int b = (pos >= 0 ? itung_k[pos] : 0); 
		ret += a - b;
	}
	
	//printf("OM %d\n",ret);
	return ret;
}

int DP(int pos, int pos_v, int pos_k, int last_v) {
	int pos_x = pos - pos_v - pos_k;
	if (pos == n) {
		return 0;
	}
	if (mem[pos][pos_v][pos_k][last_v] != -1) return mem[pos][pos_v][pos_k][last_v];
	
	//printf("%d %d %d %d\n",pos,pos_v,pos_k,pos_x);
	
	int ans = 999999999;
	
	if (pos_x < x.size()) {
		int offset = off(x[pos_x],pos_x > 0 ? x[pos_x - 1] : -1, pos_v > 0 ? v[pos_v - 1] : -1, pos_k > 0 ? k[pos_k - 1] : -1);
		//printf("%d %d %d %d -- %d\n",pos,pos_v,pos_k,pos_x, offset);
		ans = min(ans,abs(pos - offset - x[pos_x]) + DP(pos+1,pos_v,pos_k,0));
	}
	
	//printf("TWT\n");
	
	if (pos_v < v.size()) {
		int offset = off(v[pos_v],pos_x > 0 ? x[pos_x - 1] : -1, pos_v > 0 ? v[pos_v - 1] : -1, pos_k > 0 ? k[pos_k - 1] : -1);
		//printf("%d %d %d %d -- %d\n",pos,pos_v,pos_k,pos_x, offset);
		ans = min(ans,abs(pos - offset - v[pos_v]) + DP(pos+1,pos_v+1,pos_k,1));
	}
	
	if (last_v == 0 && pos_k < k.size()) {
		int offset = off(k[pos_k],pos_x > 0 ? x[pos_x - 1] : -1, pos_v > 0 ? v[pos_v - 1] : -1, pos_k > 0 ? k[pos_k - 1] : -1);
		//printf("%d %d %d %d -- %d\n",pos,pos_v,pos_k,pos_x, offset);
		ans = min(ans,abs(pos - offset - k[pos_k]) + DP(pos+1,pos_v,pos_k+1,0));
	}
	
	//printf("%d %d %d %d == %d\n",pos,pos_v,pos_k,pos_x, ans);
	
	return mem[pos][pos_v][pos_k][last_v] = ans;
}

int main() {
	scanf("%d\n",&n);
	for (i=0 ; i<n ; i++) {
		scanf("%c",&c);
		if (c == 'V') v.push_back(i); else
		if (c == 'K') k.push_back(i); else
		x.push_back(i);
	}
	
	for (i=0 ; i<v.size() ; i++) {
		itung_v[v[i]]++;
	}
	for (i=0 ; i<k.size() ; i++) {
		itung_k[k[i]]++;
	}
	for (i=0 ; i<x.size() ; i++) {
		itung_x[x[i]]++;
	}
	
	for (i=1 ; i<=75 ; i++) {
		itung_v[i] += itung_v[i-1];
		itung_k[i] += itung_k[i-1];
		itung_x[i] += itung_x[i-1];
	}
	
	for (i=0 ; i<=75 ; i++) {
		for (j=0 ; j<=75 ; j++) {
			for (l=0 ; l<=75 ; l++) {
				mem[i][j][l][0] = -1;
				mem[i][j][l][1] = -1;
			}
		}
	}
	
	printf("%d\n",DP(0,0,0,0));
}