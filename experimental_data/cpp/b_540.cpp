#include <iostream>

#include <fstream>

#include <vector>

#include <string>

#include <cstring>

#include <algorithm>

#define pb push_back

#define NMAX 1005

#define INF 0x3f3f3f3f



using namespace std;



typedef pair<int, int> pii;



//ifstream fin("fisier.in");

//ofstream fout("fisier.out");



int v[NMAX];



int main() {

	int n,k,p,x,y,lessThanY=0,i,ramas,sum=0,toAdd;



	cin>>n>>k>>p>>x>>y;



	for(i=1;i<=k;++i) {

		cin>>v[i];

		if(v[i]<y) ++lessThanY;

	}



	if(lessThanY>(n-1)/2) {

		cout<<-1;

		return 0;

	}



	for(i=k+1;i<=(n-1)/2;++i) v[i]=y;

	for(;i<=n;++i) v[i]=1;



	for(i=1;i<=n;++i) sum+=v[i];



	ramas=x-sum;

	for(i=k+1;i<=n;++i) {

		toAdd=max(0,min(ramas,y-v[i]));

		ramas-=toAdd;

		v[i]+=toAdd;

	}



	lessThanY=0;

	for(i=1;i<=n;++i)

		if(v[i]<y) ++lessThanY;



	if(lessThanY>(n-1)/2) {

		cout<<-1;

		return 0;

	}



	if(ramas<0) cout<<-1;

	else for(i=k+1;i<=n;++i) cout<<v[i]<<' ';



	return 0;

}