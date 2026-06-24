#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int i,m;
    int a[105],b[105],c[105];
    int init[105];
    cin >> n;
    char arr[105];
    scanf("%s",arr);
    for(i=0;i<n;i++)
    {
        if(arr[i]=='0')
        {
            init[i]=0;
        }
        else
            init[i]=1;
    }
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        cin >> b[i];
        c[i]=a[i]+b[i];
    }
    int maxi=-1;
    for(i=0;i<=5000;i++)
    {
        int total=0;
        for(m=0;m<n;m++)
        {
            int d = (i-b[m])/a[m];
            if(i<b[m])
            {
                total =total+init[m];
            }
            else if(d%2==1)
            {
                total = total+init[m];
            }
            else
            {   
                total=total+1-init[m];
            }
        }
        // cout << i << endl;
        // cout << total << endl;
        maxi = max(maxi,total);
    }
    cout << maxi << endl;




    return 0;
}