#include<bits/stdc++.h>

#define max(a,b) a>b?a:b

#define min(a,b) a>b?b:a

//#define fabs(a)

using namespace std;

int a[1010],b[1010];

int cmp(int b, int c) {

    return b < c;

}

int main() {

    int n;

    while(cin >> n) {

        for(int i = 0; i < n; i++)cin >> a[i];





        int ans = 0;int tol;

        here:

        sort(a, a + n, cmp);

         tol=0;

        for(int i = 1; i < n; i++) {

            if(a[i] != a[i - 1]) {

                ans++;

                //cout << i << "   " << a[i] << " " << a[i - 1] << endl;

            }

            else{

                b[tol]=a[i];

                tol++;

            }

        }

        if(tol>1)

        {

            for(int i=0;i<tol;i++)a[i]=b[i];

            n=tol;

            //for(int i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;

            goto here;

        }

        cout << ans << endl;

    }

    return 0;

}