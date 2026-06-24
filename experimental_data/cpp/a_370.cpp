#include <bits/stdc++.h>

using namespace std;



int rook(int a,int b,int c,int d){

    if (a==c || d==b) return 1;

    return 2;

}



int bishop(int a,int b,int c,int d){

    int z = abs(a-c);

    int y = abs(b-d);

    if ((z+y)%2==0){

        if (z==y) return 1;

        return 2;

    }

    return 0;

}



int king(int a,int b,int c,int d){

    int z = abs(a-c);

    int y = abs(b-d);

    if (z>y) return z;

    return y;

}



int main(){

    int x1,y1,x2,y2;

    cin >> x1 >> y1 >> x2 >> y2;

    int a = rook(x1,y1,x2,y2);

    int b = bishop(x1,y1,x2,y2);

    int c = king(x1,y1,x2,y2);

    cout << a << " " << b << " " << c << endl;

    return 0;

}