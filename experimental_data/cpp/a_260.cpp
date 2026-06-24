//============================================================================

// Date        : Sep 5, 2016

// Time        : 1:05:24 PM

// Name        : A. 260.cpp

// Author      : YoussofKamal

// Version     :

// Copyright   : ©opyRights

// Description : Hello World in C++, Ansi-style

//============================================================================



#include <iostream>

using namespace std;



int main() {



	int a, b, n, ans; cin>>a>>b>>n; n--;



	for (int i=0;i<10;++i) {

		int aa=a*10+i;

		if (aa%b == 0) {ans=aa; break;}

		else if (i==9) {cout<<"-1\n"; return 0;}

	}



    for (cout<<ans;n--;cout<<'0'); cout<<'\n';

	return 0;

}