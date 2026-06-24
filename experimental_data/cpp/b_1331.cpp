#include<bits/stdc++.h>

#define ll long long

#define yes cout << "YES" << endl

#define no cout << "NO" << endl

#define testing cout << "testing ";

#define mod 1000000007

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;





void do_the_honour(){



    int n;cin >> n;



    for(int i=2;i<=n;i++){



        if(n%i!=0) continue;

        int flag=0;

        for(int j=2;j<i;j++) if(i%j==0) flag=1;

        if(flag) continue;



        flag=0;

        int x=n/i;

        for(int j=2;j<x;j++) if((x)%j==0) flag=1;



        if(flag) continue;

        cout << i << n/i;

        break;



    }







}



int main(){

    optimize();

    int t=1;

    //cin>>t;

    for(int z=1;z<=t;z++){





    do_the_honour();





}

    return 0;

}