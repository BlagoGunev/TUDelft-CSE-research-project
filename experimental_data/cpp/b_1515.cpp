//	Code by Sahil Tiwari (still_me)



#include<bits/stdc++.h>

#define still_me main

#define endl "\n"

#define int long long int

#define all(a) (a).begin() , (a).end()

#define print(a) for(auto TEMPORARY: a) cout<<TEMPORARY<<" ";cout<<endl;

#define tt int TESTCASE;cin>>TESTCASE;while(TESTCASE--)

#define arrin(a,n) for(int INPUT=0;INPUT<n;INPUT++)cin>>a[INPUT]



using namespace std;

const int mod = 1e9+7;

const int inf = 1e18;



set<int> s;



void chal_bsdk() {

    int n;

    cin>>n;

    if(n%2) {

        cout<<"NO\n";

        return;

    }

    while(n%2 == 0)

        n >>= 1;

    if(s.find(n) != s.end()) {

        cout<<"YES\n";

    }

    else {

        cout<<"NO\n";

    }

}



signed still_me()

{

    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);



    for(int i=0;i<100000;i++) {

        s.insert(i*i);

    }



    tt{

        chal_bsdk();

    }

    return 0;

}