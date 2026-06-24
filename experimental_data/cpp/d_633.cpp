#include <bits/stdc++.h>
using namespace std;
typedef long long               ll;
const int mod = 1e9+7;
#ifndef M_PI
#define M_PI acos(-1.0)
#endif

int n;
unordered_map<int, int> a;

int main(){
	cin>>n;
	for(int i=0; i<n; ++i){
		int t;
		cin>>t;
		a[t]++;
	}
	vector<unordered_map<int, int>::iterator> ch;
	ch.reserve(n);
	int res=0;
	for(auto it1=a.begin(); it1!=a.end(); ++it1){
		for(auto it2=a.begin(); it2!=a.end(); ++it2){
			if(it1==it2 && it1->second<2){
				continue;
			}
			ch.push_back(it1);
			ch.push_back(it2);
			int x=it1->first, y=it2->first;
			--it1->second;
			--it2->second;
			while(true){
				auto it3=a.find(x+y);
				if(it3==a.end() || it3->second==0){
					break;
				}
				--it3->second;
				ch.push_back(it3);
				int z=x+y;
				x=y;
				y=z;
			}
			res=max(res, (int)ch.size());
			for(auto c : ch){
				++c->second;
			}
			ch.clear();
		}
	}
	cout<<res<<'\n';
	return 0;
}