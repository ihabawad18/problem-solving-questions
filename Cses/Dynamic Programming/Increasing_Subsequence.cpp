// Problem: Increasing Subsequence
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1145
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
  ll n, skip = 0;
  vector<int> st;

  int merge(int a, int b) { return max(a, b); }

  void init(int size) {
    n = size;
    st.resize(4 * n, skip);
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

  int query(int l, int r) { return query(0, n - 1, l, r, 0); }

  void update(int x, int y) { update(0, n - 1, 0, x, y); }
};
// ========================================= Segment tree ends
// here====================================

vi uni;

int compress(int i) { return upper_bound(all(uni), i) - uni.begin(); }

void solve() {
  int n;
  cin >> n;
  vll a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    uni.pb(a[i]);
  }
  srt(uni);
  unique(uni);
  segmenttree sg;
  sg.init(int(2e5) + 5);
  for (int i = 0; i < n; i++) {
    a[i] = compress(a[i]);
    int curr = sg.query(0, a[i] - 1);
    sg.update(a[i], curr + 1);
  }
  int ma = *max_element(all(a));
  cout << sg.query(0, ma) << endl;
}

int main() {
  FastRead;
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}