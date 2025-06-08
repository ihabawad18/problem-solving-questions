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
const long long md = 1000000007;
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
const int mxN = 1e6 + 6;
ll dp[mxN][3];
void compute() {
  dp[1][1] = dp[1][2] = 1;
  for (int i = 2; i < mxN; i++) {
    dp[i][1] = ((dp[i - 1][1] * 4) % md + dp[i - 1][2]) % md;
    dp[i][2] = (dp[i - 1][1] + (dp[i - 1][2] * 2) % md) % md;
  }
}
void solve() {
  int n;
  cin >> n;
  cout << (dp[n][1] % md + dp[n][2] % md) % md << endl;
}

int main() {
  FastRead;
  int t;
  cin >> t;
  compute();
  while (t--) {
    solve();
  }
  return 0;
}