#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int n;
    while(cin>>n){
        int sc1=0, sc2=0; vector<int>cards;
        while(n--){
            int num;
            cin>>num;
            cards.push_back(num);
        }
        int i=1;
        while(cards.size()!=0){
            if(cards[0]>cards[cards.size()-1]){
                if(i%2==0)
                    sc2+=cards[0];
                else
                    sc1+=cards[0];

                cards.erase(cards.begin());
            }
            else{
                if(i%2==0)
                    sc2+=cards[cards.size()-1];
                else
                    sc1+=cards[cards.size()-1];

                cards.erase(cards.begin()+cards.size()-1);
            }
            i++;
        }
        cout<<sc1<<" "<<sc2<<endl;
    }
    return 0;
}