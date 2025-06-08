// Problem: Pizzeria Queries
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2206
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
  int n;
  pi skip = {INT_MAX, INT_MAX};
  vector<pair<int, int>> st;

  pi merge(pi a, pi b) { return {min(a.F, b.F), min(a.S, b.S)}; }

  void init(int size, vector<pi> &a) {
    n = size;
    st.resize(4 * n, skip);
    build(a);
  }

  void build(int start, int ending, int node, vector<pi> &v) {
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

  pi query(int start, int ending, int l, int r, int node) {
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

    pi q1 = query(start, mid, l, r, 2 * node + 1);
    pi q2 = query(mid + 1, ending, l, r, 2 * node + 2);

    return merge(q1, q2);
  }

  void update(int start, int ending, int node, int index, pi &value) {
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

  void build(vector<pi> &v) { build(0, n - 1, 0, v); }

  pi query(int l, int r) { return query(0, n - 1, l, r, 0); }

  void update(int x, pi y) { update(0, n - 1, 0, x, y); }
};
// ========================================= Segment tree ends
// here====================================

void solve() {
  int n, q, x;
  cin >> n >> q;
  vpi v(n);
  for (int i = 0; i < n; i++) {
    cin >> x;
    v[i] = {x - i - 1, x + i + 1};
  }
  segmenttree sg;
  sg.init(n, v);
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int u, v;
      cin >> u >> v;
      --u;
      sg.update(u, {v - u - 1, v + u + 1});
    } else {
      int building;
      cin >> building;
      int a1 = sg.query(0, building - 1).F + building,
          a2 = sg.query(building - 1, n - 1).S - building;
      cout << min(a1, a2) << "\n";
    }
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