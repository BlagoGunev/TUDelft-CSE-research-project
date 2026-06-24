#include<bits/stdc++.h>



using namespace std;



long long int n,m;



long long int getMod(long long int num)

{

    if(num==0) return 1;

    long long int f1=getMod(num/2);

    long long int f2=(f1*f1)%m;

    if(num%2==1) f2=(f2*3)%m;

    return f2;



}



int main()

{

    cin>>n>>m;



    long long int uu=(getMod(n)-1+m)%m;



    cout<<uu<<endl;



    return 0;

}