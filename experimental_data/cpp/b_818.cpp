#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	
	int a[m + 1], res[n+1];
	memset(res, -1, sizeof(res));
	for(int i=1; i<=m; i++){
		cin >> a[i];
	}
	int flag = 1;
	int cnt = 0;
	int rep[n+1] ;
	memset(rep, 0, sizeof(rep));
	for(int i=1; i<m; i++){
		int x = (n + a[i + 1] - a[i]);
		if(x>n){
			x = x % n;
		}
		if(res[a[i]] == -1){
			res[a[i]] = x;
			cnt++;
			rep[x]++;
			if(rep[x] == 2)
				flag = 0;
		}
		else{
			if(res[a[i]] == x)
				continue;
			else
				flag = 0;
		}
	}
	if(flag){
		memset(rep, 0, sizeof(rep));
		vector< int > v;
		for(int i=1; i<=n; i++){
			if(res[i] != -1){
				rep[res[i]] = 1;
			}
		}
		for(int i=1; i<=n; i++){
			if(rep[i] == 0){
				v.push_back(i);
			}
		}
		int idx = 0;
		for(int i=1; i<=n; i++){
			if(res[i] == -1){
				res[i] = v[idx++];
			}
		}
		for(int i=1; i<=n; i++)
			cout << res[i] << " ";
		cout << endl;
	}
	else
		cout << -1 << endl;
	return 0;
}