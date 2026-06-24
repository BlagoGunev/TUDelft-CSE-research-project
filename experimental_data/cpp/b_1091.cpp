/*
   Author : Samael42,
   BITS Pilani, Hyderabad.
   Don't give up ;)
   */
#include <bits/stdc++.h>
#include <stdint.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n";

int a[100005];

int32_t main()
 {
	IOS;
	vector<pair<int,int> >v;
	int n;
	cin >> n;
	for(int i = 0 ;i < 2*n;i++)
	{
		int x,y;
		cin >> x >> y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end());
	cout << v[0].first+v[2*n-1].first <<" " <<v[0].second + v[2*n-1].second;
	return 0;
  }