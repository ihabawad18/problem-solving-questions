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

vpll v;

int dp[100005][3];
// 0 -> no tree cut
// 1 -> tree cut and left
// 2 -> tree cut and right
int dpSolve(int i, int j)
{
    if (i == v.size())
    {
        return 0;
    }
    int &ret = dp[i][j];
    if (ret != -1)
        return ret;
    ret = i == 0 ? 1 + dpSolve(i + 1, 1) : i == v.size() - 1 ? 1 + dpSolve(i + 1, 2)
                                                             : dpSolve(i + 1, 0);
    // before me is cut and right
    if (i > 0 && i < v.size() - 1)
    {
        // try to cut to right
        if (v[i].F + v[i].S < v[i + 1].F)
        {
            ret = max(ret, 1 + dpSolve(i + 1, 2));
        }
        int beforeMe = j == 2 ? v[i - 1].F + v[i - 1].S : v[i - 1].F;
        // try to cut to left
        if (beforeMe < v[i].F - v[i].S)
        {
            ret = max(ret, 1 + dpSolve(i + 1, 1));
        }
    }
    return ret;
}

void solve()
{
    MEM(dp, -1);
    int n;
    cin >> n;
    v.resize(n);
    cin >> v;
    cout << dpSolve(0, 0) << endl;
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