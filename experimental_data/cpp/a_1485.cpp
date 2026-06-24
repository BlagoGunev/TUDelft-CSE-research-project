#include<iostream>

#include<string>

#include<map>

#include<math.h>

#include<set>

#include<vector>

#include<climits>

#include<algorithm>

using namespace std;

int main(){

    int t;

    cin>>t;

    while(t--){

        int a,b,min,x,i,d;

        cin>>a>>b;

        min=INT32_MAX;

        if(b>a){

            cout<<1<<endl;

            continue;

        }

        for(i=0;i<=sqrt(a);i++){

            x=i;

            if(i==0 && b==1){

                continue;

            }

            d=a;

            while(true){

                d/=(b+i);

                x++;

                if(d==0)break;

            }

            if(x<min)min=x;

        }

        // if(a!=1)min--;

        cout<<min<<endl;



    }

}