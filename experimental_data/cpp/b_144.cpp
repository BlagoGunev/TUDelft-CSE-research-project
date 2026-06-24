#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;


#define cuadrado(x) ((x)*(x))


long long x1, y1, x2, y2;
int r[1000][3]; // x y r
int n;

int blanketNeeded(int x, int y){
    for(int i=0; i<n; i++)
        if(cuadrado(x - r[i][0])+cuadrado(y - r[i][1]) <= cuadrado(r[i][2])) return 0;
    return 1;
}

int main(){
    long long nBlankets = 0;

    cin >> x1 >> y1 >> x2 >> y2;
    if( x2 < x1 ){
        int t = x2;
        x2 = x1;
        x1 = t;
    } if( y2 < y1 ){
        int t = y2;
        y2 = y1;
        y1 = t;
    }

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> r[i][0] >> r[i][1] >> r[i][2];

    for(int x=x1; x<=x2; x++)
        nBlankets += blanketNeeded(x, y1) + blanketNeeded(x, y2);
    for(int y=y1+1; y<y2; y++)
        nBlankets += blanketNeeded(x1, y) + blanketNeeded(x2, y);


    cout << nBlankets << endl;

    return 0;
}