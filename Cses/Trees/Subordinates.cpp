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
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Check cout << "Done in " << clock() / CLOCKS_PER_SEC << " sec" << endl;
#define FastRead ios_base::sync_with_stdio(false);

vector<int> graph[(int)2e5 + 5];
int dp[(int)2e5 + 5];
int dfs(int i) {
  int res = 0;
  for (auto x : graph[i]) {
    res += 1 + dfs(x);
  }
  return dp[i] = res;
}
void solve() {
  ll n, b, c, d;
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    int x;
    cin >> x;
    x--;
    graph[x].pb(i);
  }
  dfs(0);
  for (int i = 0; i < n; i++) {
    cout << dp[i] << " ";
  }
  /*for (int i = 0; i < n; i++) {
    for (auto j : graph[i]) {
      cout << j << " ";
    }
    cout << endl;
  }*/
}

int main() {
  FastRead;
  int t;
  // cin >> t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}