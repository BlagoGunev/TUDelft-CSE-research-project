#include <bits/stdc++.h>

using namespace std;

#define ll long long int



void solve(){

    ll n;

    cin>>n;

    if((n/2)%2==1){

        cout<<"NO"<<endl;

    }else{

        cout<<"YES"<<endl;

        int esum=0, osum=0;

        for(int i=0; i<n/2; i++){

            cout<<(i+1)*2<<" ";

            esum+=((i+1)*2);

        }

        for(int i=0; i<(n/2)-1; i++){

            cout<<(i*2)+1<<" ";

            osum+=((i*2)+1);

        }

        cout<<esum-osum<<endl;

    }

}



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    //solve();

    int t;

    cin>>t;

    while(t--){

     solve();

    }

    return 0;

}