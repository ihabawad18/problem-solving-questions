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

// int calculate_profit(int w, int h, int take)
// {
//     if (take == max(w, h))
//     {
//         return w + h;
//     }
//     return take;
// }

// int calculate_expense(int w, int h, int profit)
// {
//     // initially all are colored now we can erase but still preserving our profit
//     int total_expense = w * h;
//     if (max(w, h) - 1 >= profit)
//     {
//         total_expense -= (max(w, h) - profit) * min(w, h);
//     }
//     else
//     {
//         total_expense -= min(w, h);
//         int curr_profit = total_expense / min(w, h);
//         total_expense += min(profit - curr_profit, min(w, h));
//     }
//     return total_expense;
// }

int dp(int i, int k, vpi &rectangles, vvi &memo)
{
    if (k <= 0)
    {
        return 0;
    }
    if (i == rectangles.size())
    {
        return 1e3;
    }
    int &ret = memo[i][k];
    if (ret != -1)
        return ret;
    ret = 1e6;
    int w = rectangles[i].first, h = rectangles[i].second;
    int expenses = 0;
    int profit = 0;
    while (w != 0 && h != 0)
    {

        expenses += min(w, h);
        if (w == 1 && h == 1)
        {
            profit++;
        }
        if (w <= h)
        {
            h--;
        }
        else
        {
            w--;
        }
        profit++;
        ret = min(ret, expenses + dp(i + 1, k - profit, rectangles, memo));
    }
    return ret = min(ret, dp(i + 1, k, rectangles, memo));
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vpi rectangles(n);
    cin >> rectangles;
    vvi memo(n + 1, vi(k + 1, -1));
    int ans = dp(0, k, rectangles, memo);
    cout << (ans >= 1000 ? -1 : ans) << endl;
}

int main()
{
    FastRead;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}