#include <bits/stdc++.h>



using namespace std;



int main(){

    int t;

    cin>>t;

    while(t--){

        int n;

        cin>>n;

        char s[n][n];int x,y,a,b,c=1;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                cin>>s[i][j];

                if(s[i][j]=='*'&&c){

                    a=i;

                    b=j;

                    c=0;

                }

                else if(s[i][j]=='*'){

                    x=i;

                    y=j;

                }

            }

        }

        if(a==x){

                if(x+1==n)s[x-1][b]=s[a-1][y]='*';

                else s[x+1][b]=s[a+1][y]='*';

        }

        else if(b==y){

                if(y+1==n)s[x][b-1]=s[a][y-1]='*';

                else s[x][b+1]=s[a][y+1]='*';

        }

        else s[x][b]=s[a][y]='*';

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                cout<<s[i][j];

            }

            cout<<endl;

        }

    }

    return 0;

}