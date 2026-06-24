#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int arr[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int m,d;
	cin>>m>>d;
	int ans = 1;
	arr[m-1] -= 7-d+1;
	ans += ceil(arr[m-1]/7.0);
	cout<<ans<<endl;
	return 0;
}