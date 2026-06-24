#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

int t1,t2;

// n = position of free spot
// offset = add this to the position to get the real position
int n,m,offset;

// use a map
std::map<int,long long> mm;
std::set<pair<long long,int>> gone;
std::map<int,long long>::iterator it,it2;

pair<long long,int> getval(std::map<int,long long>::iterator it)
{
    it2=it;
    --it2;
    long long rise=it2->second-it->second;
    int run=it->first-it2->first;
    //printf("(%lld %d)\n",(rise+run-1)/run,it->first);
    return {(rise+run-1)/run,it->first};    // numerator cannot be negative :(
}

long long bb,slant;

int main()
{
    #ifdef NOT_DMOJ
    freopen("data.txt","r",stdin);
    #endif // NOT_DMOJ
    scanf("%d%d",&n,&m);
    mm[0]=0;
    offset=1;
    while (m--) {
        scanf("%d",&t1);
        if (t1==1) {
            scanf("%d",&t1);
            mm.clear();
            mm[0]=0;
            gone.clear();
            bb=slant=0;
            n+=t1;
            offset=1;
        }
        else if (t1==2) {
            scanf("%d",&t1);
            mm[n]=-bb-slant*n;
            gone.insert(getval(mm.lower_bound(n)));
            n+=t1;
        }
        else {
            scanf("%d%d",&t1,&t2);
            bb+=t1;
            slant+=t2;
        }
        while (!gone.empty() && slant>=gone.begin()->first) {
            t1=gone.begin()->second;
            it=mm.lower_bound(t1);
            gone.erase(getval(it));
            ++it;
            if (it!=mm.end()) {
                gone.erase(getval(it));
                mm.erase(t1);
                it=mm.lower_bound(t1);
                gone.insert(getval(it));
            }
            else {
                mm.erase(t1);
            }
        }
        // answer query
        it=mm.end();
        --it;
        printf("%d %lld\n",it->first+offset,it->second+bb+slant*it->first);
    }
}