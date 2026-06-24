#include<iostream>
//{
	#include<algorithm>
	#include<fstream>
	#include<vector>
	#include<cstdlib>
	#include<queue>
	#include<deque>
	#include<set>
	#include<map>
	typedef long long ll;
	using namespace std;

	#define PII pair<int,int>
	#define F first
	#define S second
	#define show(x) cerr << #x << " " << x << endl;

	struct TH
	{
		int F,S,T;
		TH(int a=0,int b=0,int c=0){ F = a; S = b; T = c; };
		friend bool operator<(TH a,TH b)
		{
			if( a.F != b.F )
				return a.F < b.F;
			if( a.S != b.S )
				return a.S < b.S;
			return a.T < b.T;
		}
		friend bool operator>(TH a,TH b)
		{
			if( a.F != b.F )
				return a.F > b.F;
			if( a.S != b.S )
				return a.S > b.S;
			return a.T > b.T;
		}
	};
//}

const int MAX = 100*1000;
PII a[MAX+10];
int t[2][MAX+10];
int head[2];
int sum[2];

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> a[i].F;
		a[i].S = i;
	}
	sort(a,a+n,greater<PII>());
	/**/for(int i=0; i<n-1; i+=2)
	{
		if( sum[0] > sum[1] )
		{
			t[1][head[1]++] = a[i].S ;
			t[0][head[0]++] = a[i+1].S ;
			sum[1] += a[i].F;
			sum[0] += a[i+1].F;
		}
		else
		{
			t[1][head[1]++] = a[i+1].S ;
			t[0][head[0]++] = a[i].S ;
			sum[1] += a[i+1].F;
			sum[0] += a[i].F;
		}
	}
	if( n&1 )
	{
		if( sum[0] > sum[1] )
			t[1][head[1]++] = a[n-1].S ;
		else
			t[0][head[0]++] = a[n-1].S ;
	}
	for(int i=0; i<2; i++)
	{
		cout << head[i] << endl;
		for(int j=0; j<head[i]; j++)
			cout << t[i][j]+1 << " ";
		cout << endl;
	}/**/
	return 0;
}