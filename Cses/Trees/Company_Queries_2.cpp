// Problem: Company Queries I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1687
// Memory Limit: 512 MB
// Time Limit: 1000 ms

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
#define unique(a) a.erase(unique(all(a)), a.end())  // ssseeesss would be ses
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define Check cout << "Done in " << clock() / CLOCKS_PER_SEC << " sec" << endl;
#define FastRead                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);

// ================================== take ip/op like vector,pairs
// directly!==================================
template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) {
  return cin >> a.first >> a.second;
}
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a) {
  for (auto &x : a) cin >> x;
  return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) {
  return cout << a.first << ' ' << a.second;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a) {
  for (auto &x : a) cout << x << '\n';
  return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a) {
  int n = a.size();
  if (!n) return cout;
  cout << a[0];
  for (int i = 1; i < n; i++) cout << ' ' << a[i];
  return cout;
}
// ===================================END Of the input module
// ==========================================

int dp[int(2e5) + 5][22];
int level[int(2e5) + 5];
vvi graph;
void dfs(int i, int p) {
  dp[i][0] = p;
  for (auto x : graph[i]) {
    if (x != p) {
      level[x] = level[i] + 1;
      dfs(x, i);
    }
  }
}
void init() {
  MEM(dp, -1);
  dfs(1, -1);
  for (int j = 1; j < 22; j++) {
    for (int i = 1; i < (int(2e5) + 5); i++) {  //  based indexing
      if (dp[i][j - 1] != -1) {
        int node = dp[i][j - 1];
        dp[i][j] = dp[node][j - 1];
      }
    }
  }
}

int get_lca(int a, int b) {
  if (level[a] > level[b]) {
    swap(a, b);
  }
  int d = level[b] - level[a];
  while (d) {
    for (int i = 0; i < 22; i++) {
      if (d & (1 << i)) {
        d -= (1 << i);
        b = dp[b][i];
      }
    }
  }
  if (a == b) {
    return a;
  }
  for (int i = 21; i >= 0; i--) {
    if (dp[a][i] != -1 && dp[a][i] != dp[b][i]) {
      a = dp[a][i];
      b = dp[b][i];
    }
  }
  return dp[a][0];
}

void solve() {
  int n, m;
  cin >> n >> m;
  graph.resize(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    graph[i].pb(x);
    graph[x].pb(i);
  }
  init();
  while (m--) {
    int a, b;
    cin >> a >> b;
    cout << get_lca(a, b) << "\n";
  }
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