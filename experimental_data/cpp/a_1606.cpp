#include <bits/stdc++.h>

using namespace std;



typedef long long ll;

const ll N=1e9;



    int main(){

int t;



cin>>t;

while(t--){

    char arr[2]={'b','a'};

    string s;

    cin>>s;

    if(s[0]!=s[s.size()-1])s[0]=arr[s[0]-'a'];

        cout<<s<<'\n';

}



    return 0;

}