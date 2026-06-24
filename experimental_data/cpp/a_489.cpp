//#include <bits/stdc++.h>

#include <stdio.h>

#include <iostream>

#include <string.h>

#include <stack>

#include <vector>

#include <algorithm>

#include <queue>

#include <map>

#include <set>

#include <cmath>

#define eps 0.000001

#define pi acos(-1,0)

#define pr 999983

#define ll long long

using namespace std;

const int maxn = 4000;





// E - BerSU Ball

//string s;

//int a[126],b[126];

//bool cmp(const int &a,const int &b) {

//    return a<b;

//}

//int f(int x) {

//    if(x>0) return x;

//    else return -x;

//}

//int main(){

//    int n; cin>>n;

//    for(int i=1; i<=n; i++) cin>>a[i];

//    int m; cin>>m;

//    for(int i=1; i<=m; i++) cin>>b[i];

//    sort(a+1,a+n+1,cmp);

//    sort(b+1,b+m+1,cmp);

//    int indx = 1,indy = 1;

//    int sum = 0;

//    while(indx<=n && indy<=m) {

//        if(f(a[indx]-b[indy])<=1) {

//            sum++; indx++; indy++;

//        }

//        else if(a[indx] < b[indy]) {

//            indx++;

//        }

//        else indy++;

//    }

//    cout<<sum<<endl;

//    return 0;

//}

//









//F - Given Length and Sum of Digits...

//int a[110],b[110];

//

//int main(){

//    int n,s;

//    cin>>n>>s;

//    int k = s/n;

//

//    if(k>9) {

//        printf("-1 -1\n"); return 0;

//    }

//    if(n == 1) {

//        if(s>9) printf("-1 -1\n");

//        else printf("%d %d\n",s,s);

//        return 0;

//    }

//

//    if(s == 0) {

//        if(n>1)

//            printf("-1 -1\n");

//        else printf("0 0\n");

//    }else {

//        int ss=s;

//        a[1] = 1; s= s-1;

//

//        int m = n;

//        while(s>0 && m>=2) {

//            if(s>=9) {

//                a[m] = 9;

//                s-=9;

//            }else {

//                a[m] = s;

//                s=0;

//            }

//            m--;

//        }

//        if(a[1] + s > 9) {

//            printf("-1 -1\n"); return 0;

//        }

//        a[1] += s;

//        for(int i=1; i<=n; i++) {

//            printf("%d",a[i]);

//        }printf(" ");

//        m=1;

//        while(ss>0 && m<=n) {

//            if(ss>=9) {

//                b[m] = 9; ss-=9;

//            }else {

//                b[m] = ss; ss=0;

//            }

//            m++;

//        }

//        for(int i=1; i<=n; i++) {

//            printf("%d",b[i]);

//        }printf("\n");

//    }

//    return 0;

//}



















//G - zxa and set

//ll a[50];

//bool cmp(const ll &a, const ll &b) {

//    return a<b;

//}

//ll C(ll a,ll b){

//    ll s=1;

//    for(int i=1; i<=a; i++){

//        s=s*(b-i+1)/i;

//    }

//    return s;

//}

//

//int main(){

//    int t;scanf("%d",&t);

//    while(t--) {

//        int n; scanf("%d",&n);

//        for(int i=1; i<=n; i++) {

//            cin>>a[i];

//        }

//        sort(a+1,a+n+1,cmp);

//        ll so=0,se=0;

//        for(int i=1;i<=n; i++) {

//            so += a[i];

//            int k1 = 2,k2 = 1;

//            ll c1 = 0,c2 = 0;

//            while(k1 <= n-i) {

//                c1+=C(k1,n-i);

//                k1+=2;

//            }

//            while(k2<=n-i) {

//                c2+=C(k2,n-i);

//                k2+=2;

//            }

//            so += c1*a[i];

//            se += c2*a[i];

//        }

////        cout<<so<<endl<<se<<endl;

//        cout<<so-se<<endl;

//    }

//    return 0;

//}

















//J - KK's Steel

//ll a[110];

//void init(){

//    a[1] = 1; a[2] = 2; a[3] =3;

//    for(int i=4; i<=90; i++) {

//        a[i] = a[i-1] + a[i-2];

//    }

//}

//

//int main(){

//    init();

//    int t; scanf("%d",&t);

//    while(t--) {

//        ll n; cin>>n;

//        ll ans = 0;

//        int num = 0,tp = 1;

//

//        while(true) {

//            if(n < a[tp]) {

//                break;

//            }

//            if(n == 0) break;

//            n -= a[tp];

//            num++;

//            tp++;

//        }

//        cout<<num<<endl;

//    }

//    return 0;

//}



//  A - SwapSort

int a[maxn],b[maxn];

bool cmp(const int &a, const int &b) {

    return a<b;

}

int g[maxn];

int main(){

    int n; scanf("%d",&n);

    for(int i=1; i<=n; i++) {

        scanf("%d",&a[i]);

        b[i] = a[i];

    }

    sort(a+1,a+n+1,cmp);

//    for(int i=1; i<=n; i++) {

//        printf("%d ",a[i]);

//    }cout<<endl;

    int top=0;

    int ans = 0;

    for(int i=1;i<=n; i++) {

        if(a[i] != b[i]) {

            ans++;

            g[++top] = i;;

            for(int j=i; j<=n;j++) {

                if(a[i] == b[j]) {

                    g[++top] = j;

                    swap(b[i],b[j]);

                    break;

      //              int t = b[j]; b[j] = b[i]; b[i] = t;

                }

            }

        }

    }

    cout<<ans<<endl;

  //  cout<<g.size()<<endl;

    for(int i=1; i<=top; i++) {

        if(i%2==0) {

            printf(" %d\n",g[i]-1);

        }

        else printf("%d",g[i]-1);

    }

    return 0;

}