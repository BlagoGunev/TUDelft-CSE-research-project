#include <iostream>

#include <stdio.h>

#include <algorithm>

using namespace std;



int arr[100001];



int main()

{

	#ifndef ONLINE_JUDGE

		freopen("inp.txt","r",stdin);

	#endif

	int n,ctr=0;

	long long sum = 0;



	scanf("%d",&n);

	

	for(int i=0;i<n;i++)

		scanf("%d",&arr[i]);



	sort(arr,arr+n);



	sum = arr[0];

	for(int i=1;i<n;i++)

	{

		if(sum>arr[i])

			ctr++;

		else

			sum+=arr[i];

	}

	cout<<(n-ctr);

	return 0;

}