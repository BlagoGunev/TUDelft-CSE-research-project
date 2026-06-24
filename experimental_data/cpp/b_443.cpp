#include<bits/stdc++.h>

using namespace std;



int n, t1;

string st;



bool tdm(int ix, int jx){

	int dif = jx-ix;

	if(dif+jx-1 >= n+t1) return false;

	

	for(int i=0; i<dif && jx+i<n; i++){

		if(st[ix+i]!=st[jx+i]) return false;

	}

	return true;

}



int main(){

	cin>>st;

	n=st.length();

	cin>>t1;

	

	int mx=2*t1;

	if(t1>=n) mx = 2*((n+t1)/2);

	for(int i=0; i<n; i++){

		for(int j=i+1; j<n; j++){

//			cout<<i<<"=i, j="<<j<<" tdm="<<tdm(i, j)<<endl;

			if(tdm(i, j)){

				mx = max(mx, 2*(j-i));

			}

		}

	}

	cout<<mx<<endl;

}