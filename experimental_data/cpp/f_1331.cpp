#include <bits/stdc++.h>



using namespace std;



using ll = long long;



string s[119]={"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Nh","Fl","Mc","Lv","Ts","Og"};

int dp[11];



int main(){

	ios::sync_with_stdio(false);

	cin.tie(0);



	for (int i=0; i<118; i++){

		if (s[i].size()==2){

			s[i][1]=toupper(s[i][1]);

		}

	}

	string x;

	cin>>x;

	dp[0]=1;

	for (int i=0; i<x.size(); i++){

		if (dp[i]){

			for (auto u : s){

				if (x.substr(i,u.size())==u){

					dp[i+u.size()]=1;

				}

			}

		}

	}

	if (dp[x.size()]){

		cout<<"YES"<<endl;

	}

	else{

		cout<<"NO"<<endl;

	}

	return 0;

}