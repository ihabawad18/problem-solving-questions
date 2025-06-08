#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;
typedef vector<vll> vvll;
typedef vector<pair<int, int>> vpi;
typedef vector<vpi> vvpi;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
const long long mod = 1000000007;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define all(c) (c).begin(), (c).end()
#define srt(c) sort(all(c))
#define all_r(c) (c).rbegin(), (c).rend()
#define reverse_sort(c) sort(all_r(c))
#define sf(a) scanf("%d", &a)
#define pf(a) printf("%d\n", a)
#define unique(a) a.erase(unique(all(a)), a.end()) // ssseeesss would be ses
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Check cout << "Done in " << clock() / CLOCKS_PER_SEC << " sec" << endl;
#define FastRead ios_base::sync_with_stdio(false);
/*int const N = 1001, M = int(1e5) + 5;

ll dpp(int i, int sum, vvll &dp, int n, vi &w, vi &p) {
  if (i == n) {
    return 0;
  }
  ll &ret = dp[i][sum];
  if (ret != -1) {
    return ret;
  }
  ll choice1 = dpp(i + 1, sum, dp, n, w, p);
  if (sum - w[i] >= 0) {
    return ret = max(choice1, p[i] + dpp(i + 1, sum - w[i], dp, n, w, p));
  }
  return ret = choice1;
}*/
void solve() {

  int n, b;
  cin >> n >> b;
  vi w(n);
  vi p(n);
  vvi dp(n + 1, vi(b + 1, 0));

  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  for (int j = 0; j < n; j++) {
    cin >> p[j];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= b; j++) {
      dp[i][j] = dp[i - 1][j];
      int left = j - w[i - 1];
      if (left >= 0) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][left] + p[i - 1]);
      }
    }
  }
  cout << dp[n][b];
}

int main() {
  // FastRead;
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}