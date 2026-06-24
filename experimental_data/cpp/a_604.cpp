#include <iostream>

#include <algorithm>





using namespace std;



int main()

{

    float res=0, m[5],w[5],ac,wrg,t[]={500, 1000, 1500, 2000, 2500};

    for(int i=0;i<5;i++)cin>>m[i];

    for(int i=0;i<5;i++)cin>>w[i];

    cin>>ac>>wrg;



    for(int i=0;i<5;i++)

    {

        float x1=t[i]*0.3;

        float x2=((1-(m[i]/250))*t[i])-(50*w[i]);

        //cout<<x1<<' '<<x2<<'\n';

        res+=max(x1,x2);

    }

    res+=ac*100-wrg*50;

    cout<<(long)res;

    return 0;

}