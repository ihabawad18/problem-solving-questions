#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const long long mod = 1000000007;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define Check cout << "Done in " << clock() / CLOCKS_PER_SEC << " sec" << endl;
#define FastRead ios_base::sync_with_stdio(false);
int const N = 1e5 + 5;
int const B = 105;
int n, b;
int v[N];
/*int dpp(int i, int prev) {
  if (i == n) {
    return 1LL;
  }
  if (v[i] != 0 && i != 0 && abs(v[i] - prev) > 1) {
    return 0LL;
  }
  int &ans = dp[i][prev];
  if (ans != -1) {
    return ans % mod;
  }
  ans = 0;
  if (v[i] == 0) {
    for (int j = 1; j <= b; j++) {
      if ((i == 0) || ((j == prev - 1 || j == prev || j == prev + 1))) {
        ans += (dpp(i + 1, j) % mod);
        ans %= mod;
      }
    }
  } else {
    ans += (dpp(i + 1, v[i]) % mod);
    ans %= mod;
  }
  return (ans % mod);
}
*/
void solve() {
  ll c, d;
  cin >> n >> b;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  vector<vector<int>> dp(n + 2, vector<int>(b + 2, 0));
  // Base case: when i = n, dp[i][prev] = 1
  for (int prev = 1; prev <= b; prev++) {
    dp[n][prev] = 1;
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int prev = 1; prev <= b; prev++) {
      if (v[i] != 0 && i != 0 && abs(v[i] - prev) > 1) {
        dp[i][prev] = 0;
      } else {
        if (v[i] == 0) {

          if ((i == 0)) {
            dp[i][prev] += dp[i + 1][prev];
            dp[i][prev] %= mod;

          } else {
            for (int j = -1; j <= 1; j++) {
              int curr = prev + j;
              dp[i][prev] += dp[i + 1][curr];
              dp[i][prev] %= mod;
            }
          }
        } else {
          dp[i][prev] = dp[i + 1][v[i]];
        }
      }
    }
  }
  int sum = 0;
  if (v[0] != 0) {
    sum += dp[0][v[0]];
  } else {
    for (int prev = 0; prev <= b; prev++) {
      sum += dp[0][prev];
      sum %= mod;
    }
  }

  cout << sum << endl;
}

int main() {
  FastRead;
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}