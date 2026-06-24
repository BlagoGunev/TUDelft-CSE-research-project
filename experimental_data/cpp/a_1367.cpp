#include<bits/stdc++.h>



using namespace std;



int main(){

    string b;

    int t;

    cin>>t;

    

    while(t--){

        string a;

        cin>>b;

        

        for(int i=0;i<b.size();i++){

            if(i%2==0||i>=b.size()-2)a=a+b[i];

        }

        

        cout<<a<<endl;

    }

    return 0;

}