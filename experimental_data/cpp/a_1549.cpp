#include <bits/stdc++.h>

#define ll long long

#define yes cout << "YES\n"

#define no cout << "NO\n"

#define pb push_back

using namespace std;

int main()

{

    int t;

    cin>>t;

    while(t--){

        int n;

        cin>>n;

        if(n%2)cout<<2<<" "<<n-1;

        else {

            cout<<n%2<<" "<<n/2;

        }

        cout<<endl;

    }

}