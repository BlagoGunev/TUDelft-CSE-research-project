#include <iostream>



using namespace std;







int niza[101];

int main()

{

    int n,k;

    cin>>n>>k;

    for(int i=0;i<n;i++){

        int t;

        cin>>t;

        niza[t]++;

    }

    int rez=0;

    while(niza[k]!=n){



        for(int i=k-1;i>=1;i--){

            if(niza[i]){

                niza[i]--;

                niza[i+1]++;

            }

        }

        rez++;

    }

    cout<<rez;

    return 0;

}