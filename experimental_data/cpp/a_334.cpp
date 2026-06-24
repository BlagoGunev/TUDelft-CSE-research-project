#include<iostream>

using namespace std;
int main()
{
    int n,i,nr,k,j;
    cin >> n;
    nr=n;
    for(i=1;i<=n;i++)
    {
        k=0;
        for(j=1;j<=n/2;j++)
        {
            cout << i+k << " " << n*n-i-k+1 <<" ";
            k+=nr;
        }
        cout << endl;
    }
    return 0;
}