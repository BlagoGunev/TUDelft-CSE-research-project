#include <iostream>

#include <algorithm>

#include <cstring>

#include <cstdio>

#include <queue>

#include <map>

#include <vector>

#include <stack>

#include <set>

#include <sstream>

#include <fstream> 

#include <cmath>

#include <iomanip>

#include <unordered_map>

#include <unordered_set>

#define x first

#define y second

#define ios ios::sync_with_stdio(false),cin.tie(0);

#define endl '\n'

#define pb push_back

#define all(x) x.begin(),x.end()

#define all1(x) x.begin()+1,x.end()

#define pi 3.14159265358979323846

using namespace std;

typedef long long LL;

typedef pair<int,int> PII;

 

const int N = 200010,M = 200010,INF = 0x3f3f3f3f,mod = 1e9 + 7;

const double INFF = 0x7f7f7f7f7f7f7f7f;

 

int n,m,k,t;

 

int main()

{

	ios;

	cin >> t;

	while(t --)

	{

		int x;

		vector<int> a(4);

		cin >> x ;

		for(int i = 1;i <= 3;i ++) cin >> a[i];

		int cnt = 0;

		while(x) x = a[x],cnt ++;

		if(cnt >= 3) cout << "YES" << endl;

		else cout << "NO" << endl;

 

	}

	return 0;

}