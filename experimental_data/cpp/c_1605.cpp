#include<bits/stdc++.h>

#define ll long long

using namespace std;



void akdbc(){

    ll n;

    cin>>n;

    string s;

    cin>>s;

    for(ll i=0;i<n-1;i++){

        if(s[i]=='a' && s[i+1]=='a'){

            cout<<2<<"\n";

            return;

        }

    }

    for(ll i=0;i<n-2;i++){

        if(s[i]=='a'&& s[i+2]=='a'){

            cout<<3<<"\n";

            return;

        }

    }

    for(ll i=0;i<n-3;i++){

        if(s[i]=='a' && s[i+3]=='a' && s[i+1]!=s[i+2]){

            cout<<4<<"\n";

            return;

        }

    }

    for(ll i=0;i<n-6;i++){

        if(s[i]=='a'&&s[i+3]=='a'&&s[i+6]=='a'&&s[i+1]==s[i+2]&&s[i+4]==s[i+5]&&s[i+1]!=s[i+4]){

            cout<<7<<"\n";

            return;

        }

    }

    cout<<-1<<"\n";

    return;

}



int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    ll t;

    cin>>t;

    while(t--) akdbc();

    return 0;

}