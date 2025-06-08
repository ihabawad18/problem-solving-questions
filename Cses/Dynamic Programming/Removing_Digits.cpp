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

vi dp(int(1e6) + 5, 1e9);
int dpp(int sum) {
  if (sum == 0) {
    return 0;
  }
  if (sum < 0) {
    return 1e9;
  }
  int &res = dp[sum];
  if (res != 1e9) {
    return res;
  }
  res = 1e9;
  string s = to_string(sum);
  for (int i = 0; i < s.size(); i++) {
    res = min(res, 1 + dpp(sum - (s[i] - '0')));
  }
  return res;
}
void solve() {
  ll n, b, c, d;
  cin >> n;
  cout << dpp(n);
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