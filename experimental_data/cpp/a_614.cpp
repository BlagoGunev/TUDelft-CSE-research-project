#include <bits/stdc++.h>

#define LL unsigned long long

using namespace std;



LL l, r, k;

double tmp;



int main(){

    cin>>l>>r>>k;

    LL now = 1;

    vector<LL>V;

    for(int i=1; ;i++){

        if(now >=l && now <= r) V.push_back(now);

        tmp = (double)now;

        tmp *= (double)k;

        if(tmp > r) break;

        now *= k;

    }

    if(V.size() == 0){

        puts("-1");

        return 0;

    }

    for(int i=0; i<V.size(); i++)

        cout<<V[i]<<(i==V.size()-1?'\n':' ');

    return 0;

}