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

int dp[2005][2005];

// int dpSolve(int i, int j)
// {
//     if (i == 0)
//         return 1;
//     if (i < 0)
//         return 0;
//     int &ret = dp[i][j];
//     if (ret != -1)
//         return ret;
//     ret = 0;
//     for (int k = j * 2; k <= 2000; k++)
//     {
//         ret += dpSolve(i - k, k);
//     }
//     return ret;
// }

int dp2[23][4];
// 0 a 1 b 2 c 3 none
int n;
int dpSolve2(int i, int prev)
{
    if (i == n)
        return 1;
    int &ret = dp2[i][prev];
    if (ret != -1)
        return ret;
    ret = 0;
    if (prev == 0)
    {
        ret += dpSolve2(i + 1, 0);
        ret += dpSolve2(i + 1, 2);
    }
    else
    {
        ret += dpSolve2(i + 1, 0);
        ret += dpSolve2(i + 1, 1);
        ret += dpSolve2(i + 1, 2);
    }
    return ret;
}

void solve()
{
    cin >> n;
    MEM(dp2, -1);
    // int res = 0;
    // for (int i = 0; i <= min(n, 2); i++)
    // {
    //     res += dpSolve(n - i, i);
    //     cout << dpSolve(n - i, i) << endl;
    // }
    cout << dpSolve2(0, 3) << endl;
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