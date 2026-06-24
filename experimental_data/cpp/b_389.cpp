#include <bits/stdc++.h>

using namespace std;



typedef long long  ll;

typedef unsigned long long  ull;

#define F  first

#define S  second

#define end return 0



char a[105][105];

int main()

{



    // freopen("input.txt", "r", stdin);

    // freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false), cin.tie(NULL);





int n ;

cin >> n;

int s=0;

for(int i=0 ; i<n ; i++)

{

    for(int j=0 ; j<n ; j++)

    {

        cin >> a[i][j] ;

        if(a[i][j]=='#')s++;

    }

}

for(int i=0 ; i<n ; i++)

{

    for(int j=0 ; j<n ; j++)

    {

        if(a[i][j]=='#')

        {



            char t1=a[i][j];

            char t2=a[i+1][j];

            char t3=a[i+2][j];

            char t4=a[i+1][j+1];

            char t5=a[i+1][j-1];

            if(t1==t2 && t1==t3 && t1==t4 && t1==t5)

            {

                s-=5;

                a[i][j]='.';

                a[i+1][j]='.';

                a[i+2][j]='.';

                a[i+1][j+1]='.';

                a[i+1][j-1]='.';

            }

        }

    }

   // cout<<s<<endl;

}

//cout<<s;

if(!s)cout<<"YES";

else cout<<"NO";



    return 0;

}