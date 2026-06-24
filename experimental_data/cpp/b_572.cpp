#include <iostream>

#include <vector>

#include <cmath>

#include <map>

#include <stdio.h>

#include <algorithm>

#include <queue>

#include <string>

using namespace std;



typedef long long ll;

typedef unsigned long long ull;



#define fi(n) for(int i=0;i<n;i++)

#define fj(n) for(int j=0;j<n;j++)



bool cmp(pair<ll, ll> a, pair<ll, ll> b)

{

	if (a.first != b.first)

		return a.first < b.first;

	else

		return a.second > b.second;

}



bool cmp1(pair<ll, ll> a, pair<ll, ll> b)

{

	if (a.first != b.first)

		return a.first > b.first;

	else

		return a.second > b.second;

}







int main()

{

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);



	map <ll, ll> B;

	map <ll, ll> S;



	ll n, s;

	cin >> n >> s;



	char c;

	ll q, p;



	fi(n)

	{

		cin >> c >> q >> p;

		if (c == 'B')

		{

			B[q] += p;

		}

		else

		{

			S[q] += p;

		}

	}



	vector < pair<ll,ll> > arr (B.begin(), B.end());

	vector < pair<ll, ll> > arr1 (S.begin(), S.end());



	sort(arr.begin(), arr.end(), cmp1);

	sort(arr1.begin(), arr1.end(), cmp);

	

	vector < pair<ll, ll> > arr2;

	for(int i = 0; i < s; i++)

	{

		if(i == arr1.size())

		break;

		arr2.push_back(arr1[i]);

	}

	sort(arr2.begin(), arr2.end(), cmp1);

	

	fi(s)

	{

		if(i == arr2.size())

		break;

		cout << "S " << arr2[i].first << " " << arr2[i].second << endl;

		

	}

	fi(s)

	{

		if(i == arr.size())

		break;

		cout << "B " << arr[i].first << " " << arr[i].second << endl;

	}



	return 0;

}