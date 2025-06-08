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
// #define unique(a) a.erase(unique(all(a)), a.end()) // ssseeesss would be ses
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

// prefix sum sol 1

// vi values;
// int dataCompression(int x)
// {
//     return upper_bound(values.begin(), values.end(), x) - values.begin();
// }
// void solve()
// {
//     int n;
//     cin >> n;
//     vpi v(n);
//     cin >> v;
//     for (auto x : v)
//     {
//         values.pb(x.F);
//         values.pb(x.S);
//     }
//     sort(values.begin(), values.end());
//     values.erase(unique(values.begin(), values.end()), values.end());

//     vll dp(values.size() + 2, 0);
//     for (int i = 0; i < n; i++)
//     {
//         dp[dataCompression(v[i].F)]++;
//         dp[dataCompression(v[i].S) + 1]--;
//     }
//     for (int i = 1; i <= values.size(); i++)
//     {
//         dp[i] += dp[i - 1];
//     }
//     cout << *max_element(all(dp)) << '\n';
// }

// sol 2 BS
void solve()
{
    int n;
    cin >> n;
    vpi v(n);
    cin >> v;
    srt(v);
    int ma = 1;
    cout << v << endl;
    for (int i = 0; i < n - 1; i++)
    {
        int l = i + 1, end = n;
        while (l + 1 < end)
        {
            int mid = (l + end) / 2;
            if (v[mid].F <= v[i].S)
            {
                l = mid;
            }
            else
            {
                end = mid;
            }
        }
        bool ok = l == i + 1 ? v[l].F > v[i].S : false;
        // cout << "test: " << i << " " << l << " " << ok << endl;
        ma = max(ma, l - i - ok + 1);
    }
    cout << ma << '\n';
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