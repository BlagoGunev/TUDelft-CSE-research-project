//In the name of Allah

#include<bits/stdc++.h>



using namespace std;



#define F first

#define S second

#define PB push_back

#define MP make_pair

#define int long long



main(){

    ios::sync_with_stdio(0);cin.tie(0);

    int n;

    string s;

    cin>>n;

    cin>>s;



    int tmp=0;

    int k=1;

    for(int i=0;i<n;i++){

        if(s[i]=='B'){

            tmp+=k;

        }

        k*=2;

    }

    cout<<tmp<<"\n";

    return  0;

}