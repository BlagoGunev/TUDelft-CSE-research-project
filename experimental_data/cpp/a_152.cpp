#include <bits/stdc++.h>



using namespace std;



int main()

{

    int n,m;

    cin>>n>>m;

    char arr[n][m];

    char mx[m];

    for(int i=0;i<m;i++){

        mx[i]='0';

    }

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            cin>>arr[i][j];

            mx[j]=max(arr[i][j],mx[j]);

        }

    }

    int cnt=0;

    for(int i=0;i<n;i++){

        bool check=0;

        for(int j=0;j<m;j++){

            if(arr[i][j]==mx[j]){

                check=1;

                break;

            }

        }

        cnt+=check;

    }

    cout<<cnt<<endl;

    return 0;

}