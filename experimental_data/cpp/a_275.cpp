#include <iostream>

#include <cstring>



using namespace std;



int a[5][5],b[5][5];

int linie[4]={-1,0,1,0}, coloana[4]={0,1,0,-1};

int main(){

    int i,j;



    for(i=1;i<=3;i++)

        for(j=1;j<=3;j++)

            cin>>a[i][j];



    for(i=1;i<=3;i++)

        for(j=1;j<=3;j++)

            b[i][j]=1;



    for(i=1;i<=3;i++)

        for(j=1;j<=3;j++)

            if(a[i][j]%2==0)

                a[i][j]=0;

            else

                a[i][j]=1;



    for(i=1;i<=3;i++)

        for(j=1;j<=3;j++)

            if(a[i][j]==1){

                b[i][j]^=1;

                for(int k=0;k<=3;k++)

                    b[i+linie[k]][j+coloana[k]]^=1;

            }



    for(i=1;i<=3;i++){

        for(j=1;j<=3;j++)

            cout<<b[i][j];

        cout<<"\n";

    }



    return 0;

}