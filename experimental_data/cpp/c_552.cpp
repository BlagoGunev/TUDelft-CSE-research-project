#include <iomanip>

#include <iostream>

#include <algorithm>

#include <vector>

#include <string>

#include <math.h>

#include<set>



using namespace std;



vector <int> v;



void mabna(long long w, long long m){

	while (m){

		v.push_back(m%w);

		m/=w;

	}

}





int main(){

	long long w, m;

	cin>>w>>m;

	mabna(w, m);

	int sw=1;

	v.push_back(0);

	for(int i=0; i<v.size() && sw; i++){

		if (v[i]>=w){

			v[i]-=w;

			v[i+1]++;

		}

		if(v[i]>1 && v[i]-w!=-1)sw=0;

		else if (v[i]>1 && v[i]-w==-1){

			v[i]-=w;

			v[i+1]++;

			

		}

	}

	if (sw)cout<<"YES";

	else cout<<"NO";

}