#include <iostream>

#include <math.h>

using namespace std;

long long n,a[4][2],i,otv,j;

int main(){

	cin>>n;

	for (i=0;i<n;i++)

		for (j=0;j<2;j++)

			cin>>a[i][j];

	if (n==1){cout<<"-1";return 0;}

	if (n==4){

		for (i=1;i<4;i++){

			if (a[i][0]!=a[0][0] && a[0][1]!=a[i][1]){

				otv=sqrt(double((a[i][0]-a[0][0])*(a[i][0]-a[0][0])))*sqrt(double((a[i][1]-a[0][1])*(a[i][1]-a[0][1])));

				cout<<otv;

				return 0;

			}

		}

		cout<<"-1";return 0;

	}

	if (n==2){

		if (a[0][0]!=a[1][0] && a[0][1]!=a[1][1]){

			otv=sqrt(double((a[0][0]-a[1][0])*(a[0][0]-a[1][0])))*sqrt(double((a[0][1]-a[1][1])*(a[0][1]-a[1][1])));

			cout<<otv;

			return 0;

		}

		else {cout<<"-1";return 0;}

	}

	{

		for (i=1;i<3;i++){

			if (a[i][0]!=a[0][0] && a[0][1]!=a[i][1]){

				otv=sqrt(double((a[i][0]-a[0][0])*(a[i][0]-a[0][0])))*sqrt(double((a[i][1]-a[0][1])*(a[i][1]-a[0][1])));

				cout<<otv;

				return 0;

			}

		}

		if (a[1][0]!=a[2][0] && a[1][1]!=a[2][1]){

				otv=sqrt(double((a[1][0]-a[2][0])*(a[1][0]-a[2][0])))*sqrt(double((a[1][1]-a[2][1])*(a[1][1]-a[2][1])));

				cout<<otv;

				return 0;

			}

		else {cout<<"-1";return 0;}

	}

}