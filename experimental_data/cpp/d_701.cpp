#include <cstdio>

#include <cmath>

#include <cstring>

#include <string>

#include <algorithm>

#include <queue>

#include <map>

#include <set>

#include <vector>

#include <iostream>

using namespace std;

double v1,v2,l;

int n,k;



int main()

{



    cin>>n>>l>>v1>>v2>>k;

    int tang=(n+k-1)/k;

    double t1=2*v2/(v1+v2)*(tang-1);

    double tt=t1;

    double t2=l/(t1*v1+v2);

    printf("%.6lf\n",t2+t2*tt);

}