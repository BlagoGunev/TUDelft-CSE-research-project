#include <bits/stdc++.h>

#define ll long long



int main(){

    int x;

    std::cin >> x;

    while(x--){

        int c = 0,y;

        for (int i = 0; i < 4;i++){

            std::cin >> y;

            if (y == 1) c++;

        }

        if (c == 4) std::cout << 2 << "\n";

        else if (c == 0) std::cout << 0 << "\n";

        else std::cout << 1 << "\n";

    }

}