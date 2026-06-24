#include<bits/stdc++.h>
using namespace std;
int data[5][15];
int pp;

bool check(int n)
{


    int res2 = -1;
    int res1 = n%10;
    n/=10;

    if(n){
        res2 = n%10;
    }
    if(res2 != -1 && pp == 3){
        if((data[0][res1] && data[1][res2]) || (data[0][res1] && data[2][res2]) || (data[1][res1] && data[0][res2]) || (data[1][res1] && data[2][res2]) || (data[2][res1] && data[1][res2]) || (data[2][res1] && data[0][res2]) )
            return true;
        else
            return false;
    }
    else if(res2 != -1 && pp == 2){
        if((data[0][res1] && data[1][res2]) ||  (data[1][res1] && data[0][res2]))
            return true;
        else
            return false;
    }
    else if((res2 != -1 && pp == 2))
        return false;
    else{
        for(int i = 0; i < pp; i++){
            if(data[i][res1])
                return true;
        }
    }
    return false;

}

int main()
{
    int n,x,maxi;

    cin >> n;
    pp = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            cin >> x;

            data[i][x]++;
        }
    }

    for(int i = 1; ; i++) {
        if(check(i))
            continue;
        else {
            cout << i-1 << endl;
            return 0;
        }
    }


}