// Problem: Path Queries II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2134
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define pb push_back

#define FastRead                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);

struct FT {
  int n;
  vector<ll> vals;
  FT(int n) : n(n), vals(n + 1, 0ll) {}

  void update(int i, ll x) {
    for (++i; i <= n; i += i & -i) vals[i] += x;
  }

  ll query(int i) {  // sum from 0 ... i
    ll sum = 0;
    for (++i; i; i -= i & -i) sum += vals[i];
    return sum;
  }
  ll query(int i, int j) { return query(j) - query(i - 1); }
};

vector<int> parent, depth, heavy, head, pos, segment, values;
int cur_pos;

int dfs(int v, vector<vector<int>> const &adj) {
  int size = 1;
  int max_c_size = 0;
  for (int c : adj[v]) {
    if (c != parent[v]) {
      parent[c] = v, depth[c] = depth[v] + 1;
      int c_size = dfs(c, adj);
      size += c_size;
      if (c_size > max_c_size) max_c_size = c_size, heavy[v] = c;
    }
  }
  return size;
}

void decompose(int v, int h, vector<vector<int>> const &adj) {
  head[v] = h, pos[v] = cur_pos++;
  segment.pb(values[v]);
  if (heavy[v] != -1) decompose(heavy[v], h, adj);
  for (int c : adj[v]) {
    if (c != parent[v] && c != heavy[v]) decompose(c, c, adj);
  }
}

ll segment_tree_query(int a, int b, FT &ft) { return ft.query(a, b); }

ll query(int a, FT &ft) {
  ll res = 0;
  for (; head[a] != 1; a = parent[head[a]]) {
    ll cur_heavy_path_max =
        segment_tree_query(pos[head[a]] + 1, pos[a] + 1, ft);
    res += cur_heavy_path_max;
  }

  ll last_heavy_path_max = segment_tree_query(pos[1] + 1, pos[a] + 1, ft);
  res += last_heavy_path_max;
  return res;
}

void update(int a, int v, FT &ft) { ft.update(pos[a] + 1, v); }

void init(vector<vector<int>> const &adj) {
  int n = adj.size();
  parent = vector<int>(n);
  depth = vector<int>(n);
  heavy = vector<int>(n, -1);
  head = vector<int>(n);
  pos = vector<int>(n);
  cur_pos = 0;

  dfs(1, adj);
  decompose(1, 1, adj);
}

void solve() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> graph(n + 1);
  values.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> values[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    graph[x].pb(y);
    graph[y].pb(x);
  }
  init(graph);
  FT ft(n + 1);
  for (int i = 0; i < n; i++) {
    ft.update(i + 1, segment[i]);
  }
  // for (int i = 1; i <= n; i++) {
  // cout << pos[i] << ' ';
  // }
  // cout << "\n";
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, v;
      cin >> x >> v;
      update(x, -ft.query(pos[x] + 1, pos[x] + 1), ft);
      update(x, v, ft);
    } else {
      int a;
      cin >> a;
      cout << query(a, ft) << '\n';
    }
  }
}

int main() {
  FastRead;
  solve();
  return 0;
}