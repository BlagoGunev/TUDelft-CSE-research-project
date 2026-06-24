#include<stdio.h>

#include<bitset>

#include<algorithm>

#include<iostream>

#include<vector>

#define pb push_back

#define mp make_pair

#define fs first

#define sc second

#define MOD 1000000007

using namespace std;

int S,a,b,c;



int main() {

    scanf("%d%d%d%d",&S,&a,&b,&c);

    if(a+b+c == 0) {

        printf("%.12lf %.12lf %.12lf\n",S,0,0);

        return 0;

    }

    double t = S*1.0 / (a+b+c);

    printf("%.12lf %.12lf %.12lf\n",t*a,t*b,t*c);

    return 0;

}