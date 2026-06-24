#include<bits/stdc++.h>

#include <numeric>

using namespace std;

#define ll long long int

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)



int main()

{

  fast;

  ll t=1;

 cin>>t;

  while(t--){

    ll n,p=0,q=0;

    string s1,s2;

    char ans='.';

    // map<char,ll> m;

    vector<vector<char>> a(8);

   	char g[8][8];

	vector<int> r;

	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < 8; j++) {

			cin >> g[i][j];

			if (g[i][j] == 'R') {r.push_back(i);}

		}

	}

	for (int i : r) {

	    bool ok = true;

	    for (int j = 0; j < 8; j++) {

	        if (g[i][j] != 'R') {ok = false; break;}

	    }

	    if (ok) {cout << "R\n"; q=1; break;}

	}

	if(!q)cout << "B\n";



  }

}