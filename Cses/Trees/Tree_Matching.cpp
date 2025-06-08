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
vi graph[int(2e5) + 5];
int dp[int(2e5) + 5][2];
int treematching(int node, int parent, int included) {
  int &res = dp[node][included];
  if (res != -1) {
    return res;
  }
  int sum1 = 0;
  int sum2 = 0;
  for (auto child : graph[node]) {
    if (child != parent) {
      sum1 += treematching(child, node, 1);
    }
  }
  if (included) {
    for (auto child : graph[node]) {
      if (child != parent) {
        sum2 = max(sum2, 1 + sum1 - treematching(child, node, 1) +
                             treematching(child, node, 0));
      }
    }
  }
  return res = max(sum1, sum2);
}

void solve() {
  ll n;
  cin >> n;
  MEM(dp, -1);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    graph[x].pb(y);
    graph[y].pb(x);
  }
  cout << max(treematching(1, -1, 1), treematching(1, -1, 0));
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