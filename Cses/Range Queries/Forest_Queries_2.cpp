// Problem: Forest Queries II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1739
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

// Queries take O(log^2 n) time
struct FT2D {
  int n, m;
  vector<vector<int>> vals;
  FT2D() {}
  FT2D(int _n, int _m) : n(_n), m(_m), vals(_n + 1, vector<int>(_m + 1, 0)) {}

  // Adds val to (i,j) 0-indexed
  void update(int i, int j, int val) {
    for (++i, ++j; i <= n; i += i & -i)
      for (int _j = j; _j <= m; _j += _j & -_j) vals[i][_j] += val;
  }

  // Sum of the rectangle (0,0), (i,j)  0-indexed
  int query(int i, int j) const {
    int sum = 0;
    for (++i, ++j; i; i -= i & -i)
      for (int _j = j; _j; _j -= _j & -_j) sum += vals[i][_j];
    return sum;
  }

  // Sum of the rectangle (i1,j1), (i2,j2)
  int query(int i1, int j1, int i2, int j2) const {
    return query(i2, j2) - query(i2, j1 - 1) - query(i1 - 1, j2) +
           query(i1 - 1, j1 - 1);
  }
};

void solve() {
  int n, m;
  cin >> n >> m;
  FT2D ft(n, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char x;
      cin >> x;
      if (x == '*') {
        ft.update(i, j, 1);
      }
    }
  }
  while (m--) {
    int op;
    cin >> op;
    if (op == 2) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      x1--;
      x2--;
      y1--;
      y2--;
      cout << ft.query(x1, y1, x2, y2) << "\n";
    } else {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      if (ft.query(u, v, u, v) == 1) {
        ft.update(u, v, -1);
      } else {
        ft.update(u, v, 1);
      }
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