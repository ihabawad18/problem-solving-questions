#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod = 1000000007;
#define FastRead ios_base::sync_with_stdio(false);

void solve() {
  int n, b, c, d;
  cin >> n >> b;
  int v[n + 1];
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }
  int dp[n + 1][b + 1];
  for (int i = 1; i <= n; i++) {
    for (int s = 0; s <= b; s++) {
      if (s == 0) {
        dp[i][s] = 1;
      } else {
        int op1 = (v[i] > s) ? 0 : dp[i][s - v[i]];
        int op2 = (i == 1) ? 0 : dp[i - 1][s];
        dp[i][s] = (op1 + op2) % mod;
      }
    }
  }
  cout << dp[n][b] % mod;
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