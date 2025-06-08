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
int n, m;
void generate_next_masks(int i, int current_mask, int next_mask,
                         vi &next_masks) {
  if (i == n) {
    next_masks.pb(next_mask);
    return;
  }
  if ((current_mask & (1 << i))) {
    generate_next_masks(i + 1, current_mask, next_mask, next_masks);
  } else {
    if (i < n - 1) {
      if ((current_mask & (1 << (i + 1))) == 0) {
        generate_next_masks(i + 2, current_mask, next_mask, next_masks);
      }
    }
    generate_next_masks(i + 1, current_mask, next_mask | (1 << i), next_masks);
  }
}

int dp[1005][1 << 11];
int dpp(int i, int mask) {
  if (i == m) { // Base case
    if (mask == 0) {
      return 1;
    }
    return 0;
  }
  int &ans = dp[i][mask];
  if (ans != -1) {
    return ans % mod;
  }
  ans = 0;
  vi next_masks;
  generate_next_masks(0, mask, 0, next_masks);
  for (auto masks : next_masks) {
    ans = (ans + dpp(i + 1, masks)) % mod;
    ans % mod;
  }
  return ans % mod;
}
void solve() {
  cin >> n >> m;
  MEM(dp, -1);
  cout << dpp(0, 0) % mod;
}

int main() {
  FastRead;
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}