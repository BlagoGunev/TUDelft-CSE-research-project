#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
 
using namespace std;

#define forn(i,n) for (int i=0; (int)i<n; i++)
#define forn1(i,n) for (int i=1; (int)i<=n; i++)

const int inf=1000000;

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int w;
    cin>>w;
    if ((w%2==0)&&(w>2)) cout<<"YES"; else cout<<"NO";

    return 0;
}