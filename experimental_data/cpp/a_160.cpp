/*Gowtham Chilamakuri*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <queue>
#include <cassert>
using namespace std;
bool myfunction (int i,int j) { return (i>j); }
main()
{
	int n,i;
	cin>>n;
	vector <int> a(n);
	vector <int> sum(n,0);
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a.begin(),a.end(),myfunction);
	sum[0]=a[0];
	for(i=1;i<n;i++)
	{
		sum[i]=a[i]+sum[i-1];
	}
	for(i=0;i<n;i++)
	{
		//cout<<sum[n-1]-sum[i]<<sum[i]<<endl;
		if(sum[n-1]-sum[i]<sum[i])
			break;
	}
	cout<<i+1<<endl;

	return 0;
}