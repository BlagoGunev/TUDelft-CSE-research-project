#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int n,m,k,x = 1,y = 1,dir = 1,cnt = 0;;
	scanf("%d %d %d",&n,&m,&k);
	while(k--){
        if(k == 0){
            printf("%d",n * m - cnt);
            while(1){
                ++cnt;
                printf(" %d %d",x,y);
                if(dir == 1) ++y;
                else --y;
                if(y > m){
                    y = m;
                    ++x;
                    dir = 2;
                }
                if(y < 1){
                        y = 1;
                        ++x;
                        dir = 1;
                }
                if(cnt == n * m)
                    break;
            }
            puts("");
            break;
        }
        cnt += 2;
        printf("2 %d %d",x,y);
        if(dir == 1) ++y;
        else --y;
        if(y > m){
            y = m;
            ++x;
            dir = 2;
        }
        if(y < 1){
            y = 1;
            ++x;
            dir = 1;
        }
        printf(" %d %d\n",x,y);
         if(dir == 1) ++y;
        else --y;
        if(y > m){
            y = m;
            ++x;
            dir = 2;
        }
        if(y < 1){
            y = 1;
            ++x;
            dir = 1;
        }
	}
	return 0;
}