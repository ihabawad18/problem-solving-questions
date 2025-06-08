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
vi graph[(int)2e5 + 5];
ll res[(int)2e5 + 5];
ll cc[(int)2e5 + 5];
ll nb[(int)2e5 + 5];
ll initialize(int node, int p, int l) {
  nb[l]++;
  int c = 0;
  for (auto child : graph[node]) {
    if (child == p) {
      continue;
    }
    c += initialize(child, node, l + 1);
  }
  return cc[node] = c + 1;
}
void dfs(int node, int p, int n) {
  if (p != -1) {
    res[node] = res[p] - (cc[node] - 1) + (n - cc[node] - 1);
  }
  for (auto a : graph[node]) {
    if (a == p) {
      continue;
    }
    dfs(a, node, n);
  }
}
void solve() {
  ll n, b, c, d;
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    graph[x].pb(y);
    graph[y].pb(x);
  }
  initialize(1, -1, 0);
  for (ll i = 1; i <= n; i++) {
    res[1] += nb[i] * i;
  }
  dfs(1, -1, n);
  for (int i = 1; i <= n; i++) {
    cout << res[i] << ' ';
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