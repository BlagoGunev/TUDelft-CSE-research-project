#include<iostream>

using namespace std;

int main()

{

	int n;

	cin>>n;

	unsigned long long int a[n];

	for(int i=0;i<n;i++)

	cin>>a[i];

	int flag=1;

	unsigned long long int temp;

	while(flag)

	{

		flag=0;

		for(int i=0;i<n-1;i++)

		{

			if(a[i]>a[i+1])

			{

				temp=a[i];

				a[i]=a[i+1];

				a[i+1]=temp;

				flag=1;

				cout<<i+1<<" "<<i+2<<"\n";

			}

		}

	}

}