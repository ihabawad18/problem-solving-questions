// Problem: Range Updates and Sums
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1735
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
  ll n, skip_modify_1 = 0, skip_modify_2 = LLONG_MAX, skip = 0;
  pll skip2 = {skip_modify_1, skip_modify_2};
  vector<ll> st;
  vector<pll> lazy;
  ll merge(ll a, ll b) { return a + b; }

  void init(int size, vector<ll> &a) {
    n = size;
    st.resize(4 * n, skip);
    lazy.resize(4 * n,
                skip2);  // resize with a value that dont change the queries
    build(a);
  }

  void push(ll l, ll r, int v) {
    if (lazy[v].F == skip_modify_1 && lazy[v].S == skip_modify_2) {
      return;
    }
    if (lazy[v].S != skip_modify_2) {
      if (l != r) {
        lazy[2 * v + 1].S = lazy[v].S;
        lazy[2 * v + 2].S = lazy[v].S;
        lazy[2 * v + 1].F = lazy[v].F;
        lazy[2 * v + 2].F = lazy[v].F;
      }
      st[v] = (r - l + 1) * (lazy[v].S + lazy[v].F);
      lazy[v] = skip2;
    }

    if (lazy[v].F != skip_modify_1) {
      if (l != r) {
        lazy[2 * v + 1].F += lazy[v].F;
        lazy[2 * v + 2].F += lazy[v].F;
      }
      st[v] += (r - l + 1) * lazy[v].F;
      lazy[v].F = skip_modify_1;
    }
  }

  void build(int start, int ending, int node, vector<ll> &v) {
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
    push(start, ending, node);
    // leaf node case
    if (start > r || ending < l) {
      return skip;
    }
    // complete overlap
    if (start >= l && ending <= r) {
      return st[node];
    }

    int mid = (start + ending) / 2;
    return merge(query(start, mid, l, r, 2 * node + 1),
                 query(mid + 1, ending, l, r, 2 * node + 2));
  }

  void update(int start, int ending, int node, int type, int l, int r,
              int value) {
    push(start, ending, node);
    // non overlapping case
    if (start > r || ending < l) {
      return;
    }
    if (start >= l && ending <= r) {
      if (type == 1) {
        lazy[node] = {value + lazy[node].F, skip_modify_2};
      } else {
        lazy[node] = {0, value};
      }
      push(start, ending, node);
      return;
    }
    // partial case
    int mid = (start + ending) / 2;

    update(start, mid, 2 * node + 1, type, l, r, value);
    update(mid + 1, ending, 2 * node + 2, type, l, r, value);
    st[node] = merge(st[node * 2 + 1], st[node * 2 + 2]);
  }

  void build(vector<ll> &v) { build(0, n - 1, 0, v); }

  ll query(int l, int r) { return query(0, n - 1, l, r, 0); }

  void update(int type, int l, int r, int v) {
    update(0, n - 1, 0, type, l, r, v);
  }
};
// ========================================= Segment tree ends
// here====================================

void solve() {
  int n, q;
  cin >> n >> q;
  vll a(n);
  cin >> a;
  segmenttree sg;
  sg.init(n, a);
  while (q--) {
    int op;
    cin >> op;
    if (op == 1 || op == 2) {
      int l, r, v;
      cin >> l >> r >> v;
      sg.update(op, --l, --r, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << sg.query(--l, --r) << "\n";
    }
  }
}

int main() {
  FastRead;
  int t = 1;
  // cin >> t;
  solve();
  return 0;
}
