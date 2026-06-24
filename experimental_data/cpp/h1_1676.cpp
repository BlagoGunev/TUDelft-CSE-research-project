#include<bits/stdc++.h>

using namespace std;

int main(){

    int cases;

    cin>>cases;

    while(cases--){

        int num;

        cin>>num;

        vector<int> arr;

        arr.emplace_back(0);

        int input;

        for(int i = 1; i <= num; i++){

            cin>>input;

            arr.emplace_back(input);

        }

        int sum = 0;

        for(int i = 1; i <= num; i++){

            for(int j = i + 1; j <= num; j++){

                if(arr[i] >= arr[j])

                    sum++;

            }

        }

        cout<<sum<<endl;

    }

}