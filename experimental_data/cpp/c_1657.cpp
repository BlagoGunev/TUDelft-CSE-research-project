#include<bits/stdc++.h>
using namespace std;


int next_index(char arr[],int N,int prev_i)
{
	
	if(prev_i==N)return -1;
	if(arr[prev_i]=='('&&arr[prev_i+1]==')')return prev_i+2;
	if(arr[prev_i]=='('&&arr[prev_i+1]=='(')return prev_i+2;
	if(arr[prev_i]==')'&&arr[prev_i+1]==')')return prev_i+2;
	if(arr[prev_i]==')'&&arr[prev_i+1]=='(')
	{
		int index=prev_i+2;
		while(index<=N&&arr[index]=='(')
		index++;
		if(index>N)return -1;
		else return index+1;
	}
}

void solver()
{
	int n;
	cin>>n;
	char arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	int prev_index=0;
	int count=0;
	int next_ind=0;
	while(next_ind!=-1&&next_ind!=n)
	{
		count++;
		prev_index=next_ind;
		next_ind=next_index(arr,n-1,next_ind);
	}
	if(next_ind==-1)
	cout<<count-1<<" "<<(n-prev_index)<<"\n";
	else if(next_ind==n)
	cout<<count<<" "<<0<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	solver();

   	return 0;
}