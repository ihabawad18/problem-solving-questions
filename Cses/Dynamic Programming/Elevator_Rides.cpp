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

pll dp[1 << 21];
vll weights(21);
ll n, w;
pll dpp(ll mask) {
  if (mask == 0) {
    return mp(1, 0);
  }
  pll &ans = dp[mask];
  if (ans.first != -1) {
    return ans;
  }
  auto res = {0, 0};
  ans = {n + 1, 0};
  for (ll i = 0; i < n; i++) {
    if (mask & (1 << i)) {
      auto res = dpp(mask ^ (1 << i));
      if (res.second + weights[i] <= w) {
        ans = min(ans, {res.first, res.second + weights[i]});
      } else {
        ans = min(ans, {res.first + 1, weights[i]});
      }
    }
  }
  return ans;
}

void solve() {
  cin >> n >> w;
  for (int i = 0; i < n; ++i) {
    cin >> weights[i];
  }
  for (int i = 0; i < (1 << n); i++) {
    dp[i].F = -1;
  }
  cout << dpp((1 << n) - 1).F;
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