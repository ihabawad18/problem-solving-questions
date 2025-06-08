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

bool canPlace(int board[][8], int n, int x, int y) {

  // Column
  for (int k = 0; k < x; k++) {
    if (board[k][y] == 1) {
      return false;
    }
  }
  // Left Diag
  int i = x;
  int j = y;
  while (i >= 0 and j >= 0) {
    if (board[i][j] == 1) {
      return false;
    }
    i--;
    j--;
  }

  // Right Diag
  i = x;
  j = y;
  while (i >= 0 and j < n) {
    if (board[i][j] == 1) {
      return false;
    }
    i--;
    j++;
  }
  return true;
}

vector<vector<char>> v(8, vector<char>(8));
int solveNQueen(int n, int board[][8], int i) {
  if (i == n) {
    return 1;
  }
  int ways = 0;
  for (int j = 0; j < n; j++) {
    if (canPlace(board, n, i, j) && (v[i][j] != '*')) {
      board[i][j] = 1;
      ways += solveNQueen(n, board, i + 1);
      board[i][j] = 0;
    }
  }
  return ways;
}

void solve() {
  int board[8][8] = {0};
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; j++) {
      cin >> v[i][j];
    }
  }
  cout << solveNQueen(8, board, 0);
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