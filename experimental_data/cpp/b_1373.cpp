#include <iostream>

using namespace std;

void solve(){

    string s;

    cin>>s;

    int one=0,zero=0;

    for(int i=0;i<s.length();i++){

        if(s[i]=='1'){

            one++;

        }else{

            zero++;

        }

    }

    if(one>=zero){if(zero&1)cout<<"DA"<<endl; else cout<<"NET"<<endl;}



    else if(one<zero){if(one&1)cout<<"DA"<<endl; else cout<<"NET"<<endl;}

}

int main(){

    int t;

    cin>>t;

    while(t--){

        solve();

    }

    return 0;

}