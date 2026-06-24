#include <iostream>

#include <cstdio>



using namespace std;



bool check(int a, int b, int e, int f, int g, int h)

{

    if(a>=e+g && b>=f && b>=h) return true;

    return false;

}

int main()

{

    int  x, y, a, b, c, d;

    cin>>x>>y>>a>>b>>c>>d;



    if(check(x, y, a, b, c, d) || check(x, y, a, b, d, c) ||

       check(x, y, b, a, c, d) || check(x, y, b, a, d, c) ||

       check(y, x, a, b, c, d) || check(y, x, a, b, d, c) ||

        check(y, x, b, a, c, d) || check(y, x, b, a, d, c))

        printf("YES\n");

    else

        printf("NO\n");

    return 0;

}