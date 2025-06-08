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

int dp[505][70000];
int answ, n;

int dpp(int i, int j) {
  if (i == n || j > answ) {
    return j == answ;
  }
  int &res = dp[i][j];
  if (res != -1) {
    return res % mod;
  }
  return res = (dpp(i + 1, j) % mod + dpp(i + 1, j + i) % mod) % mod;
}
void solve() {
  ll b, c, d;
  cin >> n;
  answ = ((n) * (n + 1)) / 2;
  if (answ % 2) {
    cout << 0 << endl;
    return;
  }
  answ /= 2;
  MEM(dp, -1);
  cout << (dpp(1, 0));
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