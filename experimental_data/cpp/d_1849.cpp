#include <bits/stdc++.h>
using namespace std;
const int LONGUEUR_MAX = 300000;
const int INF = 10000000;

int longueur;
int valeur [LONGUEUR_MAX];

int dp[LONGUEUR_MAX][3];

int coutMin (int pos, int relationGauche)	{
	if (dp[pos][relationGauche] != -1)	return dp[pos][relationGauche];

	if (pos == longueur)	{
		if (relationGauche == 1) return INF;
		return 0;
	}
	if (relationGauche == 1 && valeur[pos] == 0)	return INF;
	
	int credit = valeur[pos];
	if (relationGauche == 1)	credit--;

	if (relationGauche == 2)	{
		// je me suis fait colorier
		int cout;
		if (credit > 0)
			cout = coutMin(pos+1, 2);
		else
			cout = coutMin(pos+1, 0);
		dp[pos][relationGauche] = cout;
		return cout;
	} else {
		int coutLui = coutMin(pos+1, 1);
		int coutMoi = INF;
		if (credit > 0)	coutMoi = coutMin(pos+1, 2) + 1;
		else coutMoi = coutMin(pos+1, 0) + 1;
		dp[pos][relationGauche] = min(coutMoi, coutLui);
		return min(coutMoi, coutLui);
	}
}

int main() 	{
	ios:: sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	cin >> longueur;
	for (int i = 0; i < longueur; i++)
		cin >> valeur[i];
	for (int i = 0; i < LONGUEUR_MAX; i++)	{
		dp[i][0] = -1;
		dp[i][1] = -1;
		dp[i][2] = -1;
	}
		
	cout << coutMin(0,0) << "\n";
}