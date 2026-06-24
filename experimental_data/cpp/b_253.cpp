#include<bits/stdc++.h>

using namespace std;



int main () {

    freopen("input.txt","r",stdin);

    freopen("output.txt","w",stdout);

    int n;

    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++) {

        scanf("%d",arr+i);

    }



    sort(arr,arr+n);



    int mx=0;



    for(int i=0,j=0;i<n,j<n;) {

        if(arr[i]*2>=arr[j]) {

            j++;

        }else {

            i++;

        }

        mx=max(mx,j-i);

    }

    printf("%d",n-mx);

}