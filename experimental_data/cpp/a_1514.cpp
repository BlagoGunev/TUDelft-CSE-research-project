#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include<bitset>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
set<int>s;
void init(){
	for(int i=1;i<=100;i++){
		s.insert(i*i);
	}
}
void solve(){
	int n;
	cin>>n;
	int a[200];
	int x;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(s.find(x)==s.end()){
			flag=1;
		}
	}
	if(flag==1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	init();
	while(t--) {
		solve();
	}

    
}