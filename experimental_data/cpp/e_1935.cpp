//        Problem: E. Distance Learning Courses in MAC
//        Contest: Codeforces - Codeforces Round 932 (Div. 2)
//            URL: https://codeforces.com/contest/1935/problem/E
//   Memory Limit: 256 MB
//     Time Limit: 2000 ms
//         Author: Moolamp
//        Created: marți 2024-03-05 18:13:40 EEST Iași, Romania


#include <bits/stdc++.h>
#define int long long
#define dbg(x) cerr << (#x) << ": " << x << "\n\n";
using namespace std;
const int NMAX = 3e5 + 5, MOD = 1e9 + 7;

int n, q, sp[31][NMAX], IMI_IAU_VIATA_EU_NU_MAI_SUPORT_ASA_CEVA_TREBUIA_SA_FAC_SI_EU_ABCDE_IN_CONTEST_PT_PRIMA_DATA_DAR_NU_BRO_EU_TREBUIE_SA_GRESESC_ORDINEA_DIMENSIUNILOR_MI_SE_PARE_ABSOLUT_INSANE_ASA_CEVA_SI_DE_CE_DRACU_NU_AM_LUAT_RUNTIME_SI_SINCER_CRED_CA_E_MAI_BINE_CA_DACA_REPARAM_SI_IMI_LUAM_TLE_PE_35_SAU_FST_SAU_CEVA_CACAT_MA_SINUCIDEAM_DAR_TOTUSI_DC_NU_INTRA_N_LOG_PATRAT[31][NMAX], mor[31];
pair<int, int> a[NMAX];

void solve (int tc)
{
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i].first >> a[i].second;
    int sum = 0;
    for (int p = 0; p <= 30; p++)
    {
      sp[p][i] = sp[p][i - 1];
      IMI_IAU_VIATA_EU_NU_MAI_SUPORT_ASA_CEVA_TREBUIA_SA_FAC_SI_EU_ABCDE_IN_CONTEST_PT_PRIMA_DATA_DAR_NU_BRO_EU_TREBUIE_SA_GRESESC_ORDINEA_DIMENSIUNILOR_MI_SE_PARE_ABSOLUT_INSANE_ASA_CEVA_SI_DE_CE_DRACU_NU_AM_LUAT_RUNTIME_SI_SINCER_CRED_CA_E_MAI_BINE_CA_DACA_REPARAM_SI_IMI_LUAM_TLE_PE_35_SAU_FST_SAU_CEVA_CACAT_MA_SINUCIDEAM_DAR_TOTUSI_DC_NU_INTRA_N_LOG_PATRAT[p][i] = IMI_IAU_VIATA_EU_NU_MAI_SUPORT_ASA_CEVA_TREBUIA_SA_FAC_SI_EU_ABCDE_IN_CONTEST_PT_PRIMA_DATA_DAR_NU_BRO_EU_TREBUIE_SA_GRESESC_ORDINEA_DIMENSIUNILOR_MI_SE_PARE_ABSOLUT_INSANE_ASA_CEVA_SI_DE_CE_DRACU_NU_AM_LUAT_RUNTIME_SI_SINCER_CRED_CA_E_MAI_BINE_CA_DACA_REPARAM_SI_IMI_LUAM_TLE_PE_35_SAU_FST_SAU_CEVA_CACAT_MA_SINUCIDEAM_DAR_TOTUSI_DC_NU_INTRA_N_LOG_PATRAT[p][i - 1];
      if (a[i].second & (1ll << p))
      {
        sp[p][i]++;
        int val = a[i].second - (1ll << p);
        val |= sum;
        if (val >= a[i].first && val <= a[i].second)
          IMI_IAU_VIATA_EU_NU_MAI_SUPORT_ASA_CEVA_TREBUIA_SA_FAC_SI_EU_ABCDE_IN_CONTEST_PT_PRIMA_DATA_DAR_NU_BRO_EU_TREBUIE_SA_GRESESC_ORDINEA_DIMENSIUNILOR_MI_SE_PARE_ABSOLUT_INSANE_ASA_CEVA_SI_DE_CE_DRACU_NU_AM_LUAT_RUNTIME_SI_SINCER_CRED_CA_E_MAI_BINE_CA_DACA_REPARAM_SI_IMI_LUAM_TLE_PE_35_SAU_FST_SAU_CEVA_CACAT_MA_SINUCIDEAM_DAR_TOTUSI_DC_NU_INTRA_N_LOG_PATRAT[p][i]++;
        mor[p] = sum;
      }
      sum += (1ll << p);
    }
  }
  cin >> q;
  while (q--)
  {
    int l, r; cin >> l >> r;
    int cnt = 0, ans = 0;
    for (int p = 30; p >= 0; p--)
    {
      int sum = sp[p][r] - sp[p][l - 1];
      if (IMI_IAU_VIATA_EU_NU_MAI_SUPORT_ASA_CEVA_TREBUIA_SA_FAC_SI_EU_ABCDE_IN_CONTEST_PT_PRIMA_DATA_DAR_NU_BRO_EU_TREBUIE_SA_GRESESC_ORDINEA_DIMENSIUNILOR_MI_SE_PARE_ABSOLUT_INSANE_ASA_CEVA_SI_DE_CE_DRACU_NU_AM_LUAT_RUNTIME_SI_SINCER_CRED_CA_E_MAI_BINE_CA_DACA_REPARAM_SI_IMI_LUAM_TLE_PE_35_SAU_FST_SAU_CEVA_CACAT_MA_SINUCIDEAM_DAR_TOTUSI_DC_NU_INTRA_N_LOG_PATRAT[p][r] - IMI_IAU_VIATA_EU_NU_MAI_SUPORT_ASA_CEVA_TREBUIA_SA_FAC_SI_EU_ABCDE_IN_CONTEST_PT_PRIMA_DATA_DAR_NU_BRO_EU_TREBUIE_SA_GRESESC_ORDINEA_DIMENSIUNILOR_MI_SE_PARE_ABSOLUT_INSANE_ASA_CEVA_SI_DE_CE_DRACU_NU_AM_LUAT_RUNTIME_SI_SINCER_CRED_CA_E_MAI_BINE_CA_DACA_REPARAM_SI_IMI_LUAM_TLE_PE_35_SAU_FST_SAU_CEVA_CACAT_MA_SINUCIDEAM_DAR_TOTUSI_DC_NU_INTRA_N_LOG_PATRAT[p][l - 1])
      {
        int bruh = (cnt | mor[p]);
        if (sum > 1)
          bruh |= (1ll << p);
        ans = max(ans, bruh);
      }
      if (sum)
        cnt = (cnt | (1ll << p));
    }
    cout << max(ans, cnt) << ' ';
  }
  cout << '\n';
}

signed main ()
{
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1, cnt = 0;
  cin >> tc;
  while (tc--)
    solve(++cnt);
}