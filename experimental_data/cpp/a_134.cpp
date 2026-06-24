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

#define pi 3.14159265358979323846

#define lp(i,n,a) for(ll i=a;i<=n;i++)

#define pl(i,n) for(ll i=n-1;i>=0;i--)

#define w while

#define re return

using namespace std;

int n,arr[1002],brr[200002],cnt;

int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);cout.tie(0);

    cin >> n;

    for(int i=0;i<n;i++){

        cin >> brr[i];

        arr[brr[i]]++;

        cnt+=brr[i];

    }

    if(cnt%n || (!arr[cnt/n]&&(cnt%n==0))){

        cout << "0\n";

        re 0;

    }

    cnt/=n;

    cout << arr[cnt] << endl;

    for(int i=0;i<n;i++){

        if(cnt==brr[i])

            cout << i+1 << " " ;

    }

    cout << endl;

    re 0;

}