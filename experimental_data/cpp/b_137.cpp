#include <bits/stdc++.h>



using namespace std ;







typedef unsigned long long ULL;

//ULL n,m,t,y,h,g,k,l,u,j,pmin,pmax;



int n,i,a,num = 0 ,b[5006]={0};











int main()

{

    ios::sync_with_stdio(false);



    cin >> n ;



    for(i=0;i<n;i++)

    {

        cin >> a;

        b[a]++;

    }



    for(i=1;i<=n;i++)

        if(!b[i])

         num++;

    cout << num  ;





    return 0;

}