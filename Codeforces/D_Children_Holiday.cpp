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
    int m, n;
    cin >> m >> n;
    vvi v(n, vi(3));
    cin >> v;

    auto check = [&](int time)
    {
        ll total_balloons = 0;
        vll ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            ll my_balloons = (time / ((v[i][0] * v[i][1]) + v[i][2])) * v[i][1];
            int left_time = time % ((v[i][0] * v[i][1]) + v[i][2]);
            if (left_time >= v[i][0] * v[i][1])
            {
                my_balloons += v[i][1];
            }
            else
            {
                my_balloons += left_time / v[i][0];
            }
            ans[i] = my_balloons;
            total_balloons += my_balloons;
        }
        return make_pair(total_balloons >= m, ans);
    };

    int l = -1, r = 1 << 30;
    vll ans;
    int time;
    while (r > l + 1)
    {
        int mid = (l + r) / 2;
        if (check(mid).first)
        {
            r = mid;
            ans = check(mid).second;
            time = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << time << '\n';
    for (auto x : ans)
    {
        cout << min(x, m * 1LL) << ' ';
        m -= min(x, m * 1LL);
    }
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