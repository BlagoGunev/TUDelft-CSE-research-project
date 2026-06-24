#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <algorithm>

#include <iostream>

#include <string>

#include <map>



#define MAXN 55

using namespace std;



int main()

{

    int n, w, m;

    scanf("%d%d%d", &n, &w, &m);

    if(m>n&&n%(m-n)){

        puts("NO");

        return 0;

    }

    puts("YES");

    int j=1;

    double re=w, val;

    for(int i=0;i<m;i++){

        val=n*w*1.0/m;

        while(val>0.0000001){

            if(re-val>0.0000001){

                printf("%d %lf ", j, val);

                re-=val;

                val=0;

            }

            else{

                printf("%d %lf ", j, re);

                val-=re;

                j++;  re=w;

            }

        }

        cout << endl;

    }

    return 0;

}