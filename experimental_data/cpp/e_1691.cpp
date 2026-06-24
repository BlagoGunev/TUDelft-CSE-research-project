#include "bits/stdc++.h"

using namespace std;



using ll = long long;



int tt,n;

set<tuple<int,int,int>>gz,gk;

vector<tuple<int,int,int>>arr;



int main(){

	ios::sync_with_stdio(false);

	cin.tie(0);



	cin >> tt;

	while(tt--){



		cin >> n;

		arr.clear();

		gz.clear();

		gk.clear();

		int ans = 0;

		for(int i = 1;i <= n;i++){

			int c,l,r; cin >> c >> l >> r;

			arr.push_back({l,r,c});

		}

		sort(arr.begin(),arr.end());

		for(int i = 0;i < (int)arr.size();i++){

			int c = get<2>(arr[i]);

			int l = get<0>(arr[i]);

			int r = get<1>(arr[i]);

			

			if(!c){

				auto t = gk.lower_bound({l,-1e9,-1e9});

				vector<tuple<int,int,int>>v;

				while(t != gk.end()){

					v.push_back(*t);

					t++;

				}

				if((int)v.size() == 0){

					gz.insert({r,-1,i});

					gk.insert({-1,r,i});

					



					ans++;

					continue;

				}

				ans -= (int)v.size()-1;

				int mxr = -1,mxb = -1;

				for(auto j : v){

					int bl = get<0>(j);

					int rd = get<1>(j);

					int idx = get<2>(j);

					

					mxr = max(mxr,rd);

					mxb = max(mxb,bl);

					gk.erase(j);

					gz.erase({rd,bl,idx});

				}

				mxr = max(mxr,r);

				gz.insert({mxr,mxb,i});

				gk.insert({mxb,mxr,i});

			}

			else {

				auto t = gz.lower_bound({l,-1e9,-1e9});

				vector<tuple<int,int,int>>v;

				while(t != gz.end()){

					v.push_back(*t);

					t++;

				}

				if((int)v.size() == 0){

					gk.insert({r,-1,i});

					gz.insert({-1,r,i});

					

					ans++;



					continue;

				}

				ans -= (int)v.size()-1;

				int mxr = -1,mxb = -1;

				for(auto j : v){

					int rd = get<0>(j);

					int bl = get<1>(j);

					int idx = get<2>(j);

					

					mxr = max(mxr,rd);

					mxb = max(mxb,bl);

					gz.erase(j);

					gk.erase({bl,rd,idx});

				}

				mxb = max(mxb,r);

				gz.insert({mxr,mxb,i});

				gk.insert({mxb,mxr,i});

			}

		}

		cout<<ans<<'\n';

	}

}