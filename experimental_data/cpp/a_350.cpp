#include <bits/stdc++.h>



#define ll long long



using namespace std;



int a[101], b[101];

int main(){

    int n, m;

    cin>>n>>m;

    for (int i=0; i<n; ++i){

        cin>>a[i];

    }

    for (int i=0; i<m; ++i){

        cin>>b[i];

    }

    sort(a, a+n);

    sort(b, b+m);

    if (a[n-1] >= b[0]){

        cout<<-1;

    }

    else {

        if (a[0]*2<=a[n-1]){

            cout<<a[n-1];

        }

        else if (a[0]*2 < b[0]){

            cout<<a[0]*2;

        }

        else {

            cout<<-1;

        }

    }



	return 0;

}