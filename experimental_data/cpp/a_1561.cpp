#include <bits/stdc++.h>

using namespace std;



using ll = long long;

using ld = long double;

const int INF = 1e9;



void f(int arr[],int i);

void f_even(int arr[],int n);

void f_odd(int arr[],int n);

bool check(int arr[],int n);



void solve(){

    int n; cin>>n;

    int res = 0;

    int arr[n+1];

    for(int i = 1;i<=n;i++){

        cin>>arr[i];

    }

    if(check(arr,n)){

        cout << "0\n";

        return;

    } else {

        for(int i = 1;i<=n;i++){

            if(!check(arr,n)){

                res++;

                if(i % 2 == 0){

                    f_even(arr,n);

                } else {

                    f_odd(arr,n);

                }

            } else {

                break;

            }

        }

    }

    cout << res << "\n";

}



int main(){

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin>>t;

    while(t--){

        solve();

    }

    return 0;

}



bool check(int arr[],int n){

    for(int i = 1;i<=n-1;i++){

        if(arr[i] > arr[i+1]){

            return false;

        }

    }

    return true;

}



void f(int arr[],int i){

    if(arr[i] > arr[i+1]){

        swap(arr[i],arr[i+1]);

    }

}



void f_odd(int arr[],int n){

    for(int i = 1;i<=n-2;i+=2){

        f(arr,i);

    }

}



void f_even(int arr[],int n){

    for(int i = 2;i<=n-1;i+=2){

        f(arr,i);

    }

}