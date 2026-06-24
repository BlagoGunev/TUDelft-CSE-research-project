#include<bits/stdc++.h>
using namespace std;
const int nMax = 1e6 + 7;
int main(){
	long long tst = 1;
	cin >> tst;
	while(tst--){
		long long n , m , x , ans;
		ans = 0;
		cin >> n;
		map <long long , long long> mp;
		map <long long , long long> mp1;
		long long a = 0 , b = 0;

		vector <long long> ar;
		for(long long i = 0; n > i; i++){
			cin >> x;
			mp[x]++;
			if(mp[x] == 1){
				a++;
			}
		}
		for(long long i = 0; n > i; i++){
			cin >> x;
			mp1[x]++;
			if(mp1[x] == 1){
				b++;
			}
		}
		if((b * a) >= 3){
			cout << "YES\n";
		}
		else{
			cout <<"NO\n";
		}
	}

	
}