#include <bits/stdc++.h>

//#include <Folka_Solve.STEM>

using namespace std;

#define P1 first

#define P2 second

#define _Tloops int T;cin>>T;while(T){

#define _Tloope T--;}

#define finish goto endd;

#define stop break;

#define cont continue;

#define _YNQs_ cout << (BOL?"YES":"NO") << '\n';

/**                            Checker                              **/

bool ISdistinct(long long x){

    set<long long >fnd;

    long long sz=trunc(log10(x))+1;

    while(x){

        fnd.insert(x%10);

        x/=10;

    }

    if(fnd.size()==sz){return true;}

    else{return false;}

}

/**                            Functions                            **/

void Folka_Fast(){

    std::ios_base::sync_with_stdio(0);cin.tie(NULL);

}

/**                              CODE                               **/

int main(){

//cout << "صلى على النبى";

Folka_Fast();

_Tloops

    int n; cin >> n; pair<int,char>folka[n]; bool BOL=true;

    for(int i=0; i<n; i++){

        cin >> folka[i].P1;

    }

    for(int i=0; i<n; i++){

        cin >> folka[i].P2;

    }

    sort(folka,folka+n);

    for(int i=1; i<n; i++){

        if(folka[i].P1 == folka[i-1].P1 && folka[i].P2 != folka[i-1].P2){

            BOL = false;

            stop

        }

    }

    _YNQs_

_Tloope

return 0;

}