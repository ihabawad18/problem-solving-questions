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

// ====================================start of the segment
// tree=========================================
struct segmenttree {
  int n, skip = -1e9;
  vector<int> st;

  int merge(int a, int b) { return max(a, b); }

  void init(int size, vector<int> &a) {
    n = size;
    st.resize(4 * n, skip);
    build(a);
  }

  void build(int start, int ending, int node, vector<int> &v) {
    // leaf node base case
    if (start == ending) {
      st[node] = v[start];
      return;
    }

    int mid = (start + ending) / 2;

    // left subtree is (start,mid)
    build(start, mid, 2 * node + 1, v);

    // right subtree is (mid+1,ending)
    build(mid + 1, ending, 2 * node + 2, v);

    st[node] = merge(st[node * 2 + 1], st[node * 2 + 2]);
  }

  int query(int start, int ending, int l, int r, int node) {
    // non overlapping case
    if (start > r || ending < l) {
      return skip;
    }

    // complete overlap
    if (start >= l && ending <= r) {
      return st[node];
    }

    // partial case
    int mid = (start + ending) / 2;

    int q1 = query(start, mid, l, r, 2 * node + 1);
    int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

    return merge(q1, q2);
  }

  void update(int start, int ending, int node, int index, int value) {
    // base case
    if (start == ending) {
      st[node] = value;
      return;
    }

    int mid = (start + ending) / 2;
    if (index <= mid) {
      // left subtree
      update(start, mid, 2 * node + 1, index, value);
    } else {
      // right
      update(mid + 1, ending, 2 * node + 2, index, value);
    }

    st[node] = merge(st[node * 2 + 1], st[node * 2 + 2]);
  }

  void build(vector<int> &v) { build(0, n - 1, 0, v); }

  int query(int l, int r) { return query(0, n - 1, l, r, 0); }

  void update(int x, int y) { update(0, n - 1, 0, x, y); }
};
// ========================================= Segment tree ends
// here====================================

vector<int> parent, depth, heavy, head, pos, segment, values;
int cur_pos;
segmenttree sg;
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

int segment_tree_query(int a, int b) { return sg.query(a, b); }

int query(int a, int b) {
  int res = 0;
  for (; head[a] != head[b]; b = parent[head[b]]) {
    if (depth[head[a]] > depth[head[b]]) swap(a, b);
    int cur_heavy_path_max = segment_tree_query(pos[head[b]], pos[b]);
    res = max(res, cur_heavy_path_max);
  }
  if (depth[a] > depth[b]) swap(a, b);
  int last_heavy_path_max = segment_tree_query(pos[a], pos[b]);
  res = max(res, last_heavy_path_max);
  return res;
}

void update(int a, int v) { sg.update(pos[a], v); }

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
  sg.init(n, segment);
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, v;
      cin >> x >> v;
      update(x, v);
    } else {
      int a, b;
      cin >> a >> b;
      cout << query(a, b) << ' ';
    }
  }
}

int main() {
  FastRead;
  solve();
  return 0;
}