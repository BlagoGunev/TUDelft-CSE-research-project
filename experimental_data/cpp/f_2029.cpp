#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while (t--){
		int n;cin>>n;
		vector<int> arr;
		string str;cin>>str;
		bool boolean=false;
		bool red = false, blue = false;
		for (int i = 0; i < n; i++){
			if (str[i]==str[(i+1)%n]){
				if (str[i]=='R') red=true;
				else blue=true;
			}
		}
		if (red==blue){
			cout<<"NO"<<endl;
			continue;
		}
		if (blue){
			for (int i = 0; i < n; ++i)
			{
				if (str[i]=='B') str[i]='R';
				else str[i]='B';
			}
		}
		for (int i = 0; i < n; i++){
			if (str[i]=='B'){
				for (int j = 0; j < n; j++){
					if (str[(i+j)%n]=='B') arr.push_back(0);
					else arr.back()++;
				}
				break;
			}
		}
		if (arr.size()<=1){
			cout<<"YES"<<endl;
			continue;
		}
		boolean=false;
		bool hh = false;
		for (int i = 0; i < arr.size(); ++i)
		{
			if (arr[i]%2==0){
				if (hh){
					boolean=true;
					break;
				}
				hh=true;
			}
		}
		if (boolean) {
			cout<<"NO"<<endl;
			continue;
		}
		if (!hh){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
	}
}