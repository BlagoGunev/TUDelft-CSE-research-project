#include <iostream>

#include <algorithm>

using namespace std;

const int max_n=1000+20;

int a[max_n],b[max_n];

int n;

void merge(int st,int en){

	for(int i=st;i<en;i++) 

		b[i]=a[i]; 

	int mid=(st+en)/2;

	int i=st,j=mid,pointer=st; 

	while(i<mid && j<en){

		if(b[i]<=b[j])

			a[pointer++]=b[i++]; 

		else if(b[i]>b[j])

		    a[pointer++]=b[j++];

	}

	while(i<mid) 

		a[pointer++]=b[i++];

	while(j<mid) 

	    a[pointer++]=b[j++];

}

void merge_sort(int st,int en){

	if(en-st<=1)

		return;

	int mid=(st+en)/2;

	merge_sort(st,mid);  

	merge_sort(mid,en); 

	merge(st,en);

}

int main()

{

	int n;

	cin>>n;

	for(int i=0;i<n;i++)

		cin>>a[i];

	int l=a[0];

	merge_sort(1,n);

	while(a[0]<=a[n-1]){

		a[0]++;

		a[n-1]--;

		merge_sort(1,n);

	}

	cout<<a[0]-l;

	return 0;

}