#include<iostream>

#include<math.h>

using namespace std;

long long abss(long long a);

int main(){

	

	long long x1, y1 , x2, y2;

	cin>>x1 >> y1 >> x2 >> y2;

	

	long long x= abss(x1-x2);

	long long y= abss(y1-y2);

	long long sum = min(x,y) + abss(x-y);

	

	cout<<sum;



}

long long abss(long long a){

	if(a<0)

		return a*(-1);

	else

		return a;	

}