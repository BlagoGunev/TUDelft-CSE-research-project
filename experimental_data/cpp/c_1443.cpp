#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;





void answer(){

    int n;

    cin>>n;



    vector<pair<ll, ll> > arr(n);



    for(int i = 0; i < n; i++){

        cin>>arr[i].first;

    }

    for(int i = 0; i < n; i++){

        cin>>arr[i].second;

    }









    sort(arr.begin(), arr.end());



    reverse(arr.begin(), arr.end());



    ll petya_time = 0;



    for(int i = 0; i < n; i++){

        if(arr[i].first > arr[i].second + petya_time){

            petya_time += arr[i].second;

        }else{

            cout<<max<ll>(petya_time, arr[i].first)<<"\n";

            return;

        }

    }



    cout<<petya_time<<"\n";

    return;





}







int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);



    int t;

    cin>>t;



    while(t--){

        answer();

    }

}