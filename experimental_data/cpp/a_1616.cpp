#include<iostream>

using namespace std ;



int main(){

    int t;

    cin>>t;

    while (t--){

        int n;

        cin>>n;

        int arr[n];

        for (int i=0;i<n;i++){

            cin>>arr[i];

        }

        int counter=0;

        for (int i=0;i<=100;i++){

            int count=0;

            for (int j=0;j<n;j++){

                if (abs(arr[j])==i){

                    count++;

                }

            }

            if (count>=2 && i!=0){

                counter+=2;

            }

            else if (i==0 && count>=2){

                counter+=1;

            }

            else {

                counter+=count;

            }

        }

        cout<<counter<<endl;

    }

    return 0;

}