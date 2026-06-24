#include <iostream>

using namespace std;



int main() {

long long int x,y,z,b=0,c=1,j=-1;

cin >>x;

long long int w[x];

for (int i=0;i<x;i++)

{

	cin >>w[i];

	if (w[i]==1)

	b++;

}

int a[b];

if (b==1)

cout <<1;

else if (b==0)

cout <<0;

else {

for (int i=0;i<x;i++)

{

	if (w[i]==1)

	{

		j++;

		a[j]=1;

	}

	else a[j]++;

}

a[b-1]=1;

for (int i=0;i<b;i++)

{c=c*a[i];

}

cout <<c;}



	return 0;

}