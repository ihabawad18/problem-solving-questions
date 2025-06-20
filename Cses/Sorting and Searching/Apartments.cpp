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
void print(vi v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << "\n";
}
void solve() {
  ll n, b, c, d;
  cin >> n >> b >> d;
  vi v(n), v2(b);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  for (int i = 0; i < b; i++) {
    cin >> v2[i];
  }
  reverse_sort(v);
  reverse_sort(v2);
  int i = 0, j = 0;
  int ans = 0;
  while (i < n && j < b) {
    if (abs(v2[j] - v[i]) <= d) {
      ans++;
      i++;
      j++;
    } else if (v[i] > v2[j]) {
      i++;
    } else {
      j++;
    }
  }
  // print(v);
  // print(v2);
  cout << ans << endl;
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