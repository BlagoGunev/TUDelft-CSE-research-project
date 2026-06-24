#include <bits/stdc++.h>

using namespace std;



int main() {

    int t;

    cin>>t;

    while(t--){

        int n,ans=0;

        cin>>n;

        string s;

        cin>>s;

        char arr[n];

        for(int i=0;i<n;i++){

            arr[i] = s[i];

        }

        for(int i=0;i<n;i++){

            if(arr[i]>ans){

                ans = arr[i];

            }

            else{

                continue;

            }

        }

        cout<<ans-96<<endl;   

    }

    return 0;

}