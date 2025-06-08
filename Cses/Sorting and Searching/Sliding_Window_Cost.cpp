
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
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
const long long MOD = 1000000007;
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

using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

ll n, k;
multiset<pll> low, up;
ll sum_low = 0, sum_up = 0;

void inc(ll a, ll b)
{
    sum_low += a;
    sum_up += b;
}

void ins(int a, int index)
{
    ll median = low.empty() ? 1e18 : low.rbegin()->first;
    if (a > median)
    {
        up.insert({a, index});
        sum_up += a;
        if (up.size() > (k) / 2)
        {
            inc(up.begin()->first, -up.begin()->first);
            low.insert(*up.begin());
            up.erase(up.begin());
        }
    }
    else
    {
        low.insert({a, index});
        sum_low += a;
        if (low.size() > (k + 1) / 2)
        {
            inc(-low.rbegin()->first, low.rbegin()->first);

            up.insert(*low.rbegin());
            low.erase(*low.rbegin());
        }
    }
}

void del(int a, int index)
{
    if (up.find(mp(a, index)) != up.end())
    {
        sum_up -= a;
        up.erase(up.find(mp(a, index)));
    }
    else
    {
        sum_low -= a;
        low.erase(low.find(mp(a, index)));
    }
    if (low.empty() && !up.empty())
    {
        inc(up.rbegin()->first, -up.rbegin()->first);
        low.insert(*up.begin());
        up.erase(up.begin());
    }
}

ll get_value()
{
    ll median = low.rbegin()->first;
    ll left_sum = (low.size() * median) - sum_low;
    ll right_sum = sum_up - (up.size() * median);
    return left_sum + right_sum;
}

void solve()
{
    cin >> n >> k;
    vi v(n);
    cin >> v;

    low.insert({v[0], 0});
    sum_low += v[0];
    for (int i = 1; i < k; i++)
    {
        ins(v[i], i);
    }
    cout << get_value() << ' ';
    for (int i = k; i < n; i++)
    {
        del(v[i - k], i - k);
        ins(v[i], i);
        cout << get_value() << ' ';
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
