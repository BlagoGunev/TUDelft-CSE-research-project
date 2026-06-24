/*
 * 2011-06-16  Martin  <Martin@Martin-desktop>

 * 
 */
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

#define MaxiN 5005

int N, M, Tot, Ans, Count;
char Map[MaxiN][MaxiN];
int Mark[MaxiN][MaxiN];
char Arrow[MaxiN];
int LPrev[MaxiN], LNext[MaxiN], RPrev[MaxiN], RNext[MaxiN];
int LPCpy[MaxiN], LNCpy[MaxiN], RPCpy[MaxiN], RNCpy[MaxiN];

inline void Update(int Val)
{
	if (Val > Ans)
	{
		Ans = Val;
		Count = 0;
	}
	if (Val == Ans)
		++ Count;
}

inline int Goes(int V)
{
	memcpy(LPrev, LPCpy, sizeof(LPrev));
	memcpy(LNext, LNCpy, sizeof(LNext));
	memcpy(RPrev, RPCpy, sizeof(RPrev));
	memcpy(RNext, RNCpy, sizeof(RNext));
	int Result = 0;
	for (int W = 0; V != 0; V = W, W = 0, ++ Result)
	{
		if (Arrow[V] == 'L')
			W = LPrev[V];
		if (Arrow[V] == 'R')
			W = LNext[V];
		if (Arrow[V] == 'U')
			W = RPrev[V];
		if (Arrow[V] == 'D')
			W = RNext[V];
		LPrev[LNext[V]] = LPrev[V];
		LNext[LPrev[V]] = LNext[V];
		RPrev[RNext[V]] = RPrev[V];
		RNext[RPrev[V]] = RNext[V];
	}
	return Result;
}

int main()
{
	scanf("%d%d", &N, &M);
	Tot = 0;
	for (int i = 1; i <= N; ++ i)
		for (int j = 1; j <= M; ++ j)
		{
			char Ch = getchar();
			while (Ch != '.' && !isupper(Ch))
				Ch = getchar();
			Map[i][j] = Ch;
			if (isupper(Ch))
			{
				Mark[i][j] = ++ Tot;
				Arrow[Tot] = Ch;
			}
		}
	for (int i = 1; i <= N; ++ i)
	{
		int Last = 0;
		for (int j = 1; j <= M; ++ j)
			if (isupper(Map[i][j]))
			{
				LPCpy[Mark[i][j]] = Last;
				LNCpy[Last] = Mark[i][j];
				Last = Mark[i][j];
			}
		LNCpy[Last] = 0;
	}
	for (int j = 1; j <= M; ++ j)
	{
		int Last = 0;
		for (int i = 1; i <= N; ++ i)
			if (isupper(Map[i][j]))
			{
				RPCpy[Mark[i][j]] = Last;
				RNCpy[Last] = Mark[i][j];
				Last = Mark[i][j];
			}
		RNCpy[Last] = 0;
	}
	Ans = 0, Count = 0;
	for (int i = 1; i <= Tot; ++ i)
		Update(Goes(i));
	printf("%d %d\n", Ans, Count);
	return 0;
}