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

ll dp[1001][1001];
int n;
char arr[1001][1001];
ll dpp(int i, int j) {
  // cout << i << " " << j << endl;
  if (i == n - 1 && j == n - 1) {
    return 1;
  }
  if (i >= n || j >= n) {
    return 0;
  }
  ll &res = dp[i][j];
  if (res != -1) {
    return res % mod;
  }
  res = 0;
  if (arr[i + 1][j] != '*') {
    res += dpp(i + 1, j);
  }
  if (arr[i][j + 1] != '*') {
    res += dpp(i, j + 1);
  }
  return res % mod;
}

void solve() {
  int b, c, d;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  if (arr[0][0] == '*') {
    cout << 0;
    return;
  }
  MEM(dp, -1);
  cout << dpp(0, 0);
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