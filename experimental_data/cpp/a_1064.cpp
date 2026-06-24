#include<bits/stdc++.h>
using namespace std;

int main()
{

    int a[3];
    for(int i=0;i<3;i++)
    cin>>a[i];

    sort(a,a+3);

    if(a[0]+a[1]>a[2])
    {

        cout<<0;
    }
    else
    {
        int first=a[0]+a[1];
        int second=a[2];
        int answer=second-first+1;

        cout<<answer;
            }
    cout<<"\n";



return 0;
}