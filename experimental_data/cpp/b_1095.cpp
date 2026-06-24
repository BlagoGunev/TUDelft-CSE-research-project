/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define pb push_back
typedef long long ll;

using namespace std;


int main()
{
    int p,q,mx,mn,i,n,a[100001];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);

    p=a[n-2]-a[0];
    q=a[n-1]-a[1];

    printf("%d\n",min(p,q));

    return 0;
}