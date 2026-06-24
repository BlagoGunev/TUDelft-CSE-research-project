#include <iostream>

#include <string>

#include <stdio.h>

#include <algorithm>

#include <cmath>

#include <math.h>

#include <set>

#include <vector>

#include <map>

#include <queue>

#include <stack>

#include <sstream>

#include <iomanip>

#include <cstdio>

#include <list>

#include <fstream>

#define ull unsigned long long

#define ll long long

#define ld long double

#define pi 3.1415926536

#define lp(i,n,a) for(ll i=a;i<=n;i++)

#define pl(i,n) for(ll i=n-1;i>=0;i--)

#define w while

#define re return

using namespace std;

int n,arr[101],color,maxi,mini=101;

int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);

    cin >> n >> color;

    for(int i=0;i<n;i++){

        cin >> arr[i];

        mini=min(mini,arr[i]);

        maxi=max(maxi,arr[i]);

    }

    if(maxi-mini>color){

        cout << "NO\n";

        re 0;

    }

    cout << "YES\n";

    for(int i=0;i<n;i++){

        int j=1;

        while(arr[i]--){

            cout << j << " ";

            if(j==color)

                j=0;

            j++;

        }

        cout << endl;

    }

    re 0;

}