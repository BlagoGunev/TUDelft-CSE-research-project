#include <iostream>

#include <cmath>

#include <algorithm>

using namespace std;



int main()

{

    int r1,r2,c1,c2,d1,d2;

    cin>>r1>>r2>>c1>>c2>>d1>>d2;

    for(int i=1;i<=9;i++){

        int x=c1-i;

        if(x>0 && x<10&&r2-x<10&&r2-x>0 && r1-i<10&& r1-i>0 && (r2-x)!=(r1-i)){

            if((r2-x)+i==d1 && (r1-i)+x==d2 && (r1-i)+(r2-x)==c2 && x!=i && x!=(r1-i) && x!=(r2-x) && i!=(r1-i) && i!=(r2-x)){

                cout<<i<<" "<<r1-i<<endl<<x<<" "<<r2-x<<endl;

                break;

            }

        }

        if(i==9){cout<<"-1";}

    }

    return 0;

}