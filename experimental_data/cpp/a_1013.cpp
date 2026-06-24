#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    map<int,int>M;
    cin>>n;

    M[0] = 1;

    int sum1=0,sum2=0;
    int a[500],b[500];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum1+= a[i];
    }

    int cnt = 0;
    for(int j=1;j<=n;j++){
        cin>>b[j];
        sum2+= b[j];
    }

    if(sum1>=sum2)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;



}