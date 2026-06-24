#include <iostream>

#include <string>

#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);



using namespace std;



int n,x,y,dir,ans;

string pal,train;



int main(){

optimizar_io

    cin>>n>>x>>y>>pal>>pal>>train;

    if (x<y){

        x=1;

    }else x=n;

    if (pal=="head"){

        dir=-1;

    }else dir=1;

    for (int i=0;i<train.size();i++){

        y+=dir;

        if (y==1){

            dir=1;

        }else if (y==n) dir=-1;

        if (train[i]=='0'){

            if (x==y) ans=i+1,i=train.size();

        }else if (y==1){

            x=n;

        }else if (y==n){

            x=1;

        }else if (dir==-1){

            x=n;

        }else x=1;

    }

    if (ans){

        cout<<"Controller "<<ans;

    }else cout<<"Stowaway";

}