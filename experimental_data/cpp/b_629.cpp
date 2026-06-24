#include <bits/stdc++.h>

#define LL long long

using namespace std;



int n;

int manst[444], maned[444];

int womanst[444], womaned[444];

int man, woman;

int ans;



int main(){

    int n;

    scanf("%d", &n);

    char c;

    int l, r;

    for(int i=1; i<=n; i++){

        scanf(" %c%d%d", &c, &l, &r);

        if(c == 'M'){

            manst[l]++;

            maned[r+1]--;

        }

        else if(c == 'F'){

            womanst[l]++;

            womaned[r+1]--;

        }

    }

    for(int i=0; i<=366; i++){

        man += manst[i] + maned[i];

        woman += womanst[i] + womaned[i];

        ans = max(ans, 2*min(man, woman));

    }

    cout<<ans<<endl;

    return 0;

}