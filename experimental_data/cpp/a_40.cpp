#include <bits/stdc++.h>

using namespace std;



int dis(int x,int y)

{

    return x*x + y*y;

}



int main()

{

    double x,y;

    cin >>x >> y;

    double vv = dis(x,y);

    vv = sqrt(vv);

    int me = vv;

    if(me == vv)

    {

        cout << "black";

        return 0;

    }

    if(me&1)

    {

        if((x<=0 && y<=0) || (x>=0 && y>=0)) cout << "white";

        else cout << "black";

    }

    else

    {

        if((x<=0 && y<=0) || (x>=0 && y>=0))cout << "black";

        else cout << "white";

    }

    return 0;

}