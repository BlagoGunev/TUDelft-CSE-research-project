/*.......................................

     .   *BISMILLAHIR RAHMANIR RAHIM*   .

     .       *ALLAH is Almighty*        .

     ....................................

  ********************************************

  *   . . . . . . . . . . . . . . . . . ..   *

  *   .  Solved_by: zitul_mahmud_iu;     .   *

  *   .  Applied_physics & electronics;  .   *

  *   .  Islamic university,kushtia;     .   *

  *   .  zitulmahmud88@gmail.com;        .   *

  *   .  "stay hungry stay foolish"      .   *

  *   . . . . . . . . . . . . . . . . . ..   *

  *********************************************/

#include<bits/stdc++.h>

#include<algorithm>

using namespace std;





///Predefined

#define pi acos(-1)                    //define pi value

#define mod 1000000007                 //modulo value

#define ll long long int               //define long long int

#define ara_small_size 101             //define array_size

#define ara_large_size 100001          //define array_size





int main()

{

    int ara[101],ara1[101],i,j,c=0,m,n;

    cin>>n>>m;

    for(i=0;i<n;i++)

    {

        for(j=0;j<m;j++)

        {

            scanf("%d %d",&ara[j],&ara1[j+1]);

            if(ara[j]==1||ara1[j+1]==1) c++;

        }

    }

    cout<<c<<endl;

    return 0;

}