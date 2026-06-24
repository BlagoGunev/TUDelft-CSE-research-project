#include<bits/stdc++.h>
using namespace std;
bool myfn(int i, int j) { return i<j; }
int main()
{
    int n,i,a[105],b[105];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<105;i++)
    {
        b[i]=count(a,a+n,i+1);        
    }
    int *c=max_element(b,b+100);
    cout<<int(*c)<<endl;
    return 0;
}