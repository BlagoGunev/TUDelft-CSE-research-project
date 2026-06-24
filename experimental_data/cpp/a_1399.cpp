#include<bits/stdc++.h>



using namespace std;



const int mxn=52;

int a[mxn];

int main(){

    int t;

    cin>>t;

    

    while(t--){

        int n;

        scanf("%d",&n);

        

        for(int i=1;i<=n;++i)

            scanf("%d",a+i);

        

        sort(a+1,a+n+1);

        bool flag=true;

        for(int i=1;i<n;++i){

            if(a[i+1]-a[i]>1){

                puts("NO");

                flag=false;

                break;

            }

        }

        

        if(flag)puts("YES");

    }

    

    return 0;

}