#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<cstring>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main()
{
	int arr[302][2];
	arr[0][0]=0;
	for(int i=1000000;i>=1;i--)
	{   
		arr[0][1]=i;
		for(int j=1;j<=300;j++)
		{   
			arr[j][1]=300-j+1;              //radius
			arr[j][0]=arr[j-1][0]+ 1+(int)ceil( (int )(sqrt(4.0*arr[j][1]*arr[j-1][1])));
		}   
		int x1=arr[0][0],r1=arr[0][1];
		int x2=arr[300][0],r2=arr[300][1];
		int x3=1000000,r3=1000000;

		r3=min(r3,(int)(( (x3-x2)*(x3-x2)) / (4.0*r2)) )-1;

//		r3=min(r3,(int)(( (x3-x1)*(x3-x1)) / (4.0*r1)) );

		if(r3>0 )
		{
			cout<<302<<endl;
			rep(i,301)
				cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
			cout<<x3<<" "<<r3<<endl;
			return 0;
		}



	}   

	return 0;
}