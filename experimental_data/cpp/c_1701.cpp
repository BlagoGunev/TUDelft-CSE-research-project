//

//  main.cpp

//  codeforces

//

//  Created by pavlo on 16.04.2022.

//



#include <iostream>

#include <cmath>

#include <vector>

#include <set>

#include <cstring>

#include <queue>

#include <map>

#include <algorithm>

#include <stack>



#define ll long long

#define pi pair<ll,ll>

#define all(a) (a).begin(), (a).end()

#define mod (1000000000+7)

#define _ cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);

using namespace std;

int m,n;



bool done(int time,vector<int> workers){

    ll done = 0;

    ll q = 0;

    for(int i=1;i<=n;i++){

        q = min(workers[i],time);

        done+=q;

        done+=(time - q)/2;

        

    }

    if(done >= m)return true;

    else

    return false;

}



void solve(){

    cin>>n>>m;

    vector<int> v(m);

    vector<int> workers(n+1,0);



    for(int i=0;i<m;i++){

        cin>>v[i];

        workers[v[i]]++;

    }

    int l = 0,r = 2000000;

    while (r - l > 1) {

        int mid = (l+r)/2;

        if(done(mid, workers)){

            r = mid;

        }else l = mid;

    }

    if(done(l, workers))cout<<l;

    else

        cout<<r;

    cout<<endl;

}



int main(int argc, const char * argv[]) {

    _

    int n;

    cin>>n;

    while (n--) {

        solve();

    }

}