//

//  main.cpp

//  B. Nuclear Fusion

//

//  Created by Ahmed on 6/28/16.

//  Copyright © 2016 Abdellah. All rights reserved.

//



#include <iostream>

#include <vector>

#include <bits/stdc++.h>

#include <map>

#include <algorithm>

#include <set>



#define vi vector<int>

#define pb push_back

#define f first

#define s second

#define lp(i,n) for(int i=0;i<n;i++)



using namespace std;

int n,k;

vi elements , res ;

struct node {

    vi mask;

    int lastIndex = -1;

    

};

vector<node> masks;

//void getMasks(int i,int mask,int sum){

//    if(sum == res[0]){

//        node temp ;

//        temp.mask.pb(mask);

//        temp.flag = true;

//        masks.pb(temp);

//        return;

//    }

//    

//    if(i==n)

//        return ;

//    

//    getMasks(i+1, mask , sum);

//    getMasks(i+1, mask | (1<<i) , sum + elements[i]);

//}

bool check (  int i , int mask ,int exception=-1) {

    bool ret = true;

    lp(j,(masks[i].mask).size()) {

        if(exception != masks[i].mask[j])

            if(masks[i].mask[j] & mask)

                ret = false;

    }

    if(i==0 &&  masks[i].mask.size()==1 && masks[i].mask[0]==0 )

        masks[i].mask.pop_back();

    return ret;

}

string cmp[100]={"H","He","Li","Be","B",

    "C","N","O","F","Ne",

    "Na","Mg","Al","Si","P",

    "S","Cl","Ar","K","Ca",

    "Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr",

    "Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La",

    "Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl",

    "Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm"};

int find(string t){

    bool found=false;

    int ret = -2;

    for(int i=0;i<100 && !found;i++)

        if(t == cmp[i])

            found  = true , ret = i ;

    

    return ret+1;

}

bool comp(int a,int b){

    

    if(b>=masks.size())

        return false;

    lp(i,masks[a].mask.size())

        if(masks[a].mask[i]!=masks[b].mask[i])

            return false;

    

    return true;

}

int main(int argc, const char * argv[]) {

    cin>>n>>k;

    lp(i,n){

        string t;

        cin>>t;

        elements.pb(find(t));

    }

    lp(i,k){

        string t;

        cin>>t;

        res.pb(find(t));

    }

    

//    memset(memo, -1, sizeof(memo));

//    getMasks(0,0,0);

    sort(res.begin(),res.end());

    node temp;

    masks.push_back(temp);

    masks[0].mask.pb(0);

    lp(i,k){

        int exception = -1;

        lp(mask,(1<<n)){

            int sum = 0;

            lp(j,n){

               if(mask & (1<<j))

                   sum += elements[j];

            }

            if(sum == res[i] ){

                int rep = 0;

                for(int a=0;a<(int)masks.size()-rep;a++){

                    if(i!=masks[a].lastIndex && check(a,mask)){

                        masks[a].lastIndex = i;

                        masks[a].mask.pb(mask);

                        exception = mask;

                    }

                    else if(i==masks[a].lastIndex  && masks[a].mask[masks[a].mask.size()-1] != mask

                            &&check(a,mask,masks[a].mask[masks[a].mask.size()-1])

                            && masks.size()<(17 * 16 *2)){

                        exception = mask;

                        node temp = masks[a];

//                        masks[a].lastIndex = -1;

                        temp.mask.pop_back();

                        temp.mask.pb(mask);

                        masks.pb(temp);

                        ++rep ;

                        if(0 == i)

                            break;

                    }

                }

            }

        }

//        cout<<masks.size()<<endl;

//        masks.erase( unique(masks.begin(), masks.end()), masks.end());

        

//        set< struct node > s(masks.begin(),masks.end());

//        masks.assign(s.begin(), s.end());

        if(masks.size() > 17*17)

            lp(b,masks.size())

                if(masks[b].mask.size() < i-1 || comp(b,b+1))

                    masks.erase(masks.begin()+b);

            

    }

    

    

//    cout<<endl<<masks.size()<<endl;

    bool found = false;

    int index=0;

    for(int i=0;i<masks.size()&&!found ;i++) {

//        lp(j,masks[0].mask.size())

//            cout<<masks[i].mask[j]<<" ";

//        cout<<endl;

        if(masks[i].mask.size() == k){

            index = i, found =true;

        }

            

    }

    if(found){

        cout<<"YES"<<endl;

        lp(i,k){

            string out[20];

            int sz=0;

            lp(j,n)

                if(masks[index].mask[i] & (1<<j) ){

                    out[sz++] = cmp[elements[j]-1] ;

                }

            

            lp(a,sz-1)

                cout<<out[a]<<"+";

            cout<<out[sz-1]<<"->"<<cmp[res[i]-1]<<endl;

        }

    }

    else

        cout<<"NO"<<endl;

    //    cout<<  <<endl;

    return 0;

}