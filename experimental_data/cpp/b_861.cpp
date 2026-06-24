#include <bits/stdc++.h>

using namespace std;

#define ii pair<int, int>
#define ll long long
#define fi first
#define se second
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define endl '\n'

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin>>n>>m;
	int mi=1, M=1000;
	for(int i=0; i<m; i++){
		int k, f;
		cin>>k>>f;
		while((k-1)/mi+1>f)mi++;
		if(f!=1){while((k-1)/M+1<f)M--;}
	}
	if((n-1)/mi+1==(n-1)/M+1)cout<<(n-1)/mi+1;
	else cout<<-1;
}