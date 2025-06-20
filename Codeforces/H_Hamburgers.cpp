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

ll money;
string s;
vector<int> have(3), prices(3);

bool check(ll m)
{
    ll have_money = money;
    ll b = count(all(s), 'B'), su = count(all(s), 'S'), c = count(all(s), 'C');

    ll can_b = have[0] / (b ? b : 1), can_s = have[1] / (su ? su : 1), can_c = have[2] / (c ? c : 1);
    ll remainder_b = have[0] % (b ? b : 1), remainder_s = have[1] % (su ? su : 1), remainder_c = have[2] % (c ? c : 1);
    if (can_b < m && b > 0)
    {
        have_money -= ((m - can_b) * b - remainder_b) * prices[0];
    }
    if (can_s < m && su > 0)
    {
        have_money -= ((m - can_s) * su - remainder_s) * prices[1];
    }
    if (can_c < m && c > 0)
    {
        have_money -= ((m - can_c) * c - remainder_c) * prices[2];
    }
    return have_money >= 0;
}

void solve()
{
    cin >> s >> have >> prices >> money;
    ll l = 0, r = 4e12;
    while (r > l + 1)
    {
        ll m = l + ((r - l) >> 1);
        // cout << m << endl;
        if (check(m))
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    cout << l << '\n';
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