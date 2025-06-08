// Problem: Subtree Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1137
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

// ====================================start of the segment
// tree=========================================
struct segmenttree {
  int n, skip = 0;
  vector<long long> st;

  ll merge(ll a, ll b) { return a + b; }

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

  ll query(int start, int ending, int l, int r, int node) {
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

    ll q1 = query(start, mid, l, r, 2 * node + 1);
    ll q2 = query(mid + 1, ending, l, r, 2 * node + 2);

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

  ll query(int l, int r) { return query(0, n - 1, l, r, 0); }

  void update(int x, int y) { update(0, n - 1, 0, x, y); }
};
// ========================================= Segment tree ends
// here====================================

vi subtree;
vvi graph;
int n;
int dfs(int i, int par) {
  int s = 1;
  for (auto child : graph[i]) {
    if (child != par) {
      s += dfs(child, i);
    }
  }
  return subtree[i] = s;
}

int get_centroid(int i, int par) {
  for (auto child : graph[i]) {
    if (child != par && subtree[child] * 2 > n) {
      return get_centroid(child, i);
    }
  }
  return i;
}

void solve() {
  cin >> n;
  graph.resize(n + 1);
  subtree.resize(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    graph[x].pb(y);
    graph[y].pb(x);
  }
  dfs(1, -1);
  cout << get_centroid(1, -1) << "\n";
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