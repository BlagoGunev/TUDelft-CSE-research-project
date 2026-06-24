#include <iostream>



using namespace std;



int a[100];



int main(){

 

    int n,m,x,y,i,p;

    

    cin>>n;

    

    cin>>x;

    

    for(i=0;i<x;i++){

         cin>>m; a[m]=1;

    }

    

    cin>>y;

    

    for(i=0;i<y;i++){

         cin>>m; a[m]=1;

    }

    

    for(i=1;i<=n;i++){

        if(a[i]==0){

            cout<<"Oh, my keyboard!"<<endl;

            return 0;

        }

    }

    

    cout<<"I become the guy."<<endl;

 return 0;



}