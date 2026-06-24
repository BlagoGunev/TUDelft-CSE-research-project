#include <iostream>

#include <fstream>

#include <stdlib.h>

#include <math.h>

#include <iomanip>

#include <string>

#include <cstring>

#include <cstdlib>

#include <sstream>

#include<algorithm>



#define fi first

#define se second

#define mp make_pair

#define rep(i,a,b) for(int (i)=(a);(i)<(b);++(i))

#define per(i,a,n) for (int i=(n)-1;i>=(a);i--)



typedef long long ll;

typedef long double ld;



using namespace std;



const int maxn=(int)3e5+10;

const int inf=(int)1e9+5;

const ll llinf=(ll)1e18+5;



int a[5005];

int  n,m,i,F,S,T,mn,k;

int main()

{

        //freopen("input.txt", "r", stdin);

        //freopen("output.txt", "w", stdout);

        //ios_base::sync_with_stdio(false);

        cin>>n>>m;

        rep(i,0,n) cin>>a[i];

        mn=0;

        k=0;

        rep(i,0,n-1){

            if (a[i]-a[i+1]-m>0) mn=max(mn,a[i]-a[i+1]-m);

            else k++;

        }

        cout<<mn;

        return 0;

}