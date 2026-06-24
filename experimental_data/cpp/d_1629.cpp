#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(){

	set<string>st;

	bool pos = 0;

	int n; cin>>n;

	for(int i=1; i<=n; i++){

		string s; cin>>s;

		if(s[0]==s.back()) pos = 1;

		if(pos) continue;

		if(s.length()==1) pos = 1;

		else if(s.length()==2){

			string ss = s; 

			swap(ss[0],ss[1]);

			if(st.find(ss)!=st.end()) pos = 1;

			else{

				ss.push_back('a');

				for(char ch = 'a'; ch<='z'; ch++){

					ss.back() = ch;

					if(st.find(ss)!=st.end()){

						pos = 1;

						break;

					}

				}

			}

		}

		else{

			string ss = s;

			reverse(ss.begin(),ss.end());

			if(st.find(ss)!=st.end()) pos = 1;

			ss.pop_back();

			if(st.find(ss)!=st.end()) pos = 1;

		}

		st.insert(s);

	}

	if(pos) cout<<"YES"<<'\n';

	else cout<<"NO"<<'\n';

}

int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;

	cin >> t;

	for(int i=1; i<=t; i++) solve();

}