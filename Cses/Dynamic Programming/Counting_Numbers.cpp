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

ll memo[20][2][2][11];
ll dp(int in, string s, bool isSmaller, bool leadingzero, int lastDigit) {
  if (in == s.size()) {
    return 1LL;
  }
  ll &res = memo[in][isSmaller][leadingzero][lastDigit];
  if (res != -1) {
    return res;
  }
  res = 0;
  int r = ((isSmaller) ? 9 : s[in] - '0');
  for (int i = 0; i <= r; i++) {
    if (lastDigit != i || (leadingzero && i == 0)) {
      res += dp(in + 1, s, isSmaller || (i < s[in] - '0'),
                leadingzero & ((i == 0)), i);
    }
  }
  return res;
}

void solve() {
  MEM(memo, -1);
  ll l, r;
  cin >> l >> r;
  ll an1 = dp(0, to_string(r), 0, 1, 10);
  MEM(memo, -1);
  cout << an1 - dp(0, to_string(l - 1), 0, 1, 10);
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