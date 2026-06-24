#include <bits/stdc++.h>
#include <bits/stdc++.h>

#define sys system("pause");





const int INF=1000000009;


using namespace std;

int64_t fir =1,last=1;

int64_t var1 = 0;



int main()
{
    int64_t n, m, i, a[100], l=1, r, k=1;

    cin>>n>>m;
    r=n;
    for(i=2; i<=n; i++,last*=2);
    for(i=1; i<=n; i++,k++)
    {
        if(m<=(last+fir)/2)
            a[l]=k,last=(last+fir)/2,l++;
        else
            a[r]=k,fir=(fir+last)/2,r--;
    }
    for(i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<endl;

    return 0;
}