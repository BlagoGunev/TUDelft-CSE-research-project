#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	 cin>>arr[i];
	sort(arr,arr+n);
	int l=0,r=n-1,mid;
	mid=l+((r-l)/2);
	cout<<arr[mid];
	return 0;
	
}