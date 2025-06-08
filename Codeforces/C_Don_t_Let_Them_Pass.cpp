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
#define FastRead                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

// ================================== take ip/op like vector,pairs directly!==================================
template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a) { return cin >> a.first >> a.second; }
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
    for (auto &x : a)
        cout << x << '\n';
    return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}
// ===================================END Of the input module ==========================================

int n, m;
vi positions;

int dp[1004][1004];

int dpSolve(int i, int prev)
{
    if (i == positions.size())
        return 0;
    int &ret = dp[i][prev];
    if (ret != -1)
        return ret;
    ret = 1e7;

    // either match my prev pos or if possible be up by 1 or down by 1
    int movesEqual = abs(positions[i] - prev), movesDown = movesEqual + 1, movesUp = movesEqual + 1;
    if (positions[i] < prev)
    {
        movesDown = movesEqual + 1;
        movesUp = movesEqual - 1;
    }
    else if (positions[i] > prev)
    {
        movesDown = movesEqual - 1;
        movesUp = movesEqual + 1;
    }
    if (prev > 0)
    {
        ret = min(ret, dpSolve(i + 1, prev - 1) + movesUp);
    }
    if (prev < n - 1)
    {
        ret = min(ret, dpSolve(i + 1, prev + 1) + movesDown);
    }

    return ret = min(ret, dpSolve(i + 1, prev) + movesEqual);
}

void solve()
{
    MEM(dp, -1);
    cin >> n >> m;
    vvi v(n, vi(m));
    cin >> v;
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i][j] == 1)
            {
                positions.pb(i);
            }
        }
    }
    int res = 1e7;
    // first element try to place in any row
    for (int j = 0; j < n; j++)
    {
        res = min(res, dpSolve(1, j) + abs(positions[0] - j));
    }
    cout << res << endl;
}

int main()
{
    FastRead;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}