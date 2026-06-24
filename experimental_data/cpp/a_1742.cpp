#include <iostream>

#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout<<#x<<" :: "<<x<<endl;

#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;

#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;

#define boost ios::sync_with_stdio(0); cin.tie(0) 

#define fi first

#define se second

#define pb(x) push_back(x)

#define mp(x,y) make_pair(x,y)

typedef long long ll;

typedef long double ld;

typedef pair<int, int> pii;

typedef unsigned long long ull;

#define YES cout<<"YES"<<"\n";

#define NO cout<<"NO"<<"\n";



/***************************************************************************/





int main(){

    boost; 

    int T=0;cin>>T;

    for(int test=1;test<=T;test++){

        int a[3];

        cin>>a[0]>>a[1]>>a[2];

        sort(a,a+3);

        if(a[0]+a[1]==a[2]){

            YES

        }

        else{

            NO

        }

    }

    return 0;

}