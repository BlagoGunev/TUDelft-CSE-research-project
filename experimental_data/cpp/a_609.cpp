#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;

int main(){

    

    vector <int> v;   

    int n,m, x;

    cin>>n >> m;

    

    for(int i= 0 ; i<n ;i++){

            cin>> x;

            v.push_back(x);

            }

            

       sort(v.begin(),v.end());          

    

    int sum=0 , counter= 0 , pointer= n-1;

    

    while(sum < m && counter<n){

              sum+= v[pointer];

              pointer--;

              counter++;    

              }

    cout<<counter;

    

    

    

    

}