#include <iostream>

#include <cstdio>

#include <algorithm>

using namespace std;



int arr[110];

main()

{

    int n , ans = 0 , in = 0;

    cin>>n;



    for(int i=0 ; i<n ; i++) cin>>arr[i];

    sort(arr,arr+n);



    int cnt = 0;

    if(n==1)

    {

        cout<<arr[0]<<"\n";

        return 0;

    }

    for(int i=0 ; i<n ; i++)

    {

        if(arr[i] > 0)

            cout<<arr[i]<<" " , cnt++;

        else if( arr[i] < 0 && arr[i+1] < 0)

            cout<<arr[i]<<" "<<arr[i+1]<<" " , i++ , cnt++;

    }

    if(cnt==0)

        cout<<0<<"\n";

}