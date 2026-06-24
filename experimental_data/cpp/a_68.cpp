#include<bits/stdc++.h>



using namespace std;



int main()

{

    int p1,p2,p3,p4,a,b,i,cnt=0,t;



    cin>>p1>>p2>>p3>>p4>>a>>b;



    for(i=a; i<=b; i++)

    {

        t=((((i%p1)%p2)%p3)%p4);



        if(t==i) cnt++;

    }



    cout<<cnt<<endl;



    return 0;

}