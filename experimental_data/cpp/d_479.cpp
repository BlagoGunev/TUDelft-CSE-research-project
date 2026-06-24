#include <bits/stdc++.h>

#define print(s) puts(s)

using namespace std;

int a[100005];





int main(){





    int n ;

    int l , x , y;

    scanf("%d%d%d%d",&n,&l,&x,&y);

    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);





    int bx = 0 , by = 0 ;

    for(int i = 0; i < n ; i++){

        int t = lower_bound(a , a + n , x + a[i]) - a;

        if(t != n && a[t] == x + a[i]){

            bx = 1;

        }

        t = lower_bound(a , a + n ,y + a[i]) - a ;

        if(t != n && a[t] == y + a[i]){

            by = 1;

        }

    }

    if(bx && by) return puts("0") , 0 ;

    if(bx || by) {

        puts("1");

        if(!bx) printf("%d\n",x);

        else printf("%d\n", y);

        return 0;

    }

    for(int i =0 ; i < n ; i++){





        int t ;

        if(a[i] + x <= l){

                int r = a[i] + x - y ;

                int rr = a[i] +x + y ;

            t = lower_bound(a , a + n , r) -a ;

            if(t != n && a[t] == r){

                printf("1\n%d\n",a[i] + x);

                return 0;

            }

            t = lower_bound(a , a + n , rr) - a;

            if(t != n && a[t] == rr){

                printf("1\n%d\n",a[i] + x);

                return 0;

            }



        }

        if(a[i] - x >= 0){



             int r = a[i] - x - y ;

            int rr = a[i] -x + y ;

            t = lower_bound(a , a + n , r) -a ;

            if(t != n && a[t] == r){

                printf("1\n%d\n",a[i] - x);

                return 0;

            }

            t = lower_bound(a , a + n , rr) - a;

            if(t != n && a[t] == rr){

                printf("1\n%d\n",a[i] - x);

                return 0;

            }



        }



    }

    puts("2");

    printf("%d %d \n",x,y);



    return 0;

}