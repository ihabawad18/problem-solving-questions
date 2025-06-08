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

void solve()
{
    int n;
    cin >> n;
    map<pi, int> a;
    vector<pi> line0, line1;
    map<int, int> sameX;
    vector<pi> v;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        a[mp(x, y)]++;
        v.pb(mp(x, y));
        if (y == 0)
        {
            line0.pb(mp(x, y));
        }

        if (y == 1)
        {
            line1.pb(mp(x, y));
        }
        if (y == 1)
        {
            sameX[x]++;
        }
    }
    ll ans = 0;
    for (auto i : v)
    {
        // first type
        if (i.second == 1 && a[mp(i.first - 1, i.second - 1)] > 0 && a[mp(i.first + 1, i.second - 1)] > 0)
        {
            ans++;
        }
        // first type 2
        if (i.second == 0 && a[mp(i.first - 1, i.second + 1)] > 0 && a[mp(i.first + 1, i.second + 1)] > 0)
        {
            ans++;
        }

        // second type
        if (i.second == 1 && a[mp(i.first, 0)] > 0 && line1.size() > 0)
        {
            ans += line1.size() - 1;
        }
        // third type
        if (i.second == 0 && sameX[i.first] > 0 && line0.size() > 0)
        {
            ans += line0.size() - 1;
        }
    }
    cout << ans << endl;
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