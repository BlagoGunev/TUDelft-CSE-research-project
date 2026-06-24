#include <bits/stdc++.h>

using namespace std;

string res[11];

void change(int l,int k,int n){

    if(n==0)return;

    int m=0;

    while (m*m<n) m++;

    if (m*m-2==n) m++;

    int re=0;

    for(int j=k;j<k+m;j++){

        res[l][j]='o';

        res[j][l]='o';

        re+=2; 

        }

    re--;

    change(l+1,k+1,n-re);

}

int main(){

    int n; cin>>n;

    if(n==2)    { cout<<-1; }

    else{

        int k=0;

        while(k*k<n){

            k++;

            }

        if(k*k==n+2){

            k++;

            }

    for(int i=k-1;i>=0;i--){

        string s="";

        for(int j=0;j<k;j++){

            s+='.';

            }

        res[i]=s;

        } 

    cout<<k<<endl;

    change(0,0,n);

        for(int i=k-1;i>=0;i--)

        {

            cout<<res[i]<<endl;

        }

    }

}