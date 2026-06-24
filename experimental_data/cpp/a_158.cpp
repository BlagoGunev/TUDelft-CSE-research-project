#include <iostream>
using namespace std;


int main()  {
    int n=0;
    int k=0;
    int res = 0;
    cin>>n; 
    cin>>k;
    int *mas = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin>>mas[i];
        if((mas[i] > 0) && (i < k - 1))
            res++;
        else if((mas[i] > 0) && (mas[i] == mas[k - 1]))
            res++;
    }
    cout<<res<<endl;
    return 0;
}