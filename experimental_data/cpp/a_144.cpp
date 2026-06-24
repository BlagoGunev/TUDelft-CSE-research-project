#include<iostream>

using namespace std;

int main()
{
    int n,a[102]={0},maxi=-1,mini=55555,maxin,minin;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(maxi<a[i])
        {
            maxi=a[i];maxin=i;
        }
        if(mini>=a[i])
        {
            mini=a[i];minin=i;
        }
    }
    if(maxin>minin)
        cout << maxin+(n-minin-2) << endl;
    else
        cout << maxin+(n-minin-1) << endl;
	return 0;
}