#include <bits/stdc++.h>
using namespace std;

inline void fastRead_int(int &x) {
    register int c = getchar();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar());

    if(c=='-') {
        neg = 1;
        c = getchar();
    }

    for(; c>47 && c<58 ; c = getchar()) {
        x = (x<<1) + (x<<3) + c - 48;
    }

    if(neg)
        x = -x;
}

int main(){
		
	int n, bat, acc;
	fastRead_int(n); fastRead_int(bat); fastRead_int(acc);

    int light[n];
    for(int i = 0; i < n; i++) {
        fastRead_int( light[i] );
    }
    
    int len = 0, curr_b = bat, curr_a = acc;
    for(int i = 0; i < n; i++) {
        if(light[i]) {
            if(curr_a == acc) {
                curr_a--;
                len++;
                //cout << i << " a " << curr_b << " " << curr_a << endl; 
            }
            else {
                if(curr_b > 0) {
                    curr_a++;
                    curr_a = min(curr_a, acc);
                    len++;
                    curr_b--;
                }
                else if(curr_b == 0) {
                    len++;
                    curr_a--;
                }
                //cout << i << " b " << curr_b << " " << curr_a << endl; 
            }
        }
        else {
            if(curr_a > 0) {
                curr_a--;
                len++;
                //cout << i << " a " << curr_b << " " << curr_a << endl; 
            }
            else {
                if(curr_b > 0) {
                    len++;
                    curr_b--;
                    //cout << i << " b " << curr_b << " " << curr_a << endl; 
                }
            }
        }
        if(curr_a == 0 and curr_b == 0)break;
    }

    printf("%d\n", len);
	
	return 0;
}