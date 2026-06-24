#include <bits/stdc++.h>



using namespace std;



int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    //freopen ("input.txt","r",stdin);

    //freopen ("output.txt","w",stdout);

    string notes[]={"C","C#","D","D#","E","F","F#","G","G#","A","B","H"};

    string s,s2,s3;

    cin>>s>>s2>>s3;

    int x[3];

    for(int i=0;i<12;i++){

        if(notes[i]==s){x[0]=i; break;}

    }

    for(int i=0;i<12;i++){

        if(notes[i]==s2){x[1]=i; break;}

    }

    for(int i=0;i<12;i++){

        if(notes[i]==s3){x[2]=i; break;}

    }

    for(int i=0;i<3;i++){

        for(int j=0;j<3;j++){

            for(int k=0;k<3;k++){

                if(i!=j && j!=k && i!=k){

                    int d1,d2;

                    if(x[j]>x[i]){

                        d1=x[j]-x[i];

                    }

                    else{

                        d1=(12-x[i])+x[j];

                    }

                    if(x[k]>x[j]){

                        d2=x[k]-x[j];

                    }

                    else{

                        d2=(12-x[j])+x[k];

                    }

                    if(d1==4 && d2==3){

                        cout<<"major\n";

                        return 0;

                    }

                    else if(d1==3 && d2==4){

                        cout<<"minor\n";

                        return 0;

                    }

                }

            }

        }

    }

    cout<<"strange\n";

    return 0;

}