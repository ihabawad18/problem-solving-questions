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
// const long long mod = 1000000007;
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

// const ll mod = 1000000007;

// ll fact[200005];

// ll power(ll x, ll n)
// {
//     ll res = 1;
//     for (; n; n >>= 1, x = (x * x) % mod)
//         if (n & 1)
//             res = ((res % mod) * (x % mod)) % mod;
//     return res % mod;
// }

// ll modInv(ll x) { return power(x, mod - 2); }

// ll choose(ll N, ll K)
// {
//     ll denum = ((fact[N - K] % mod) * (fact[K] % mod)) % mod;
//     return ((fact[N] % mod) * modInv(denum)) % mod;
// }

// void solve()
// {
//     ll n, k;
//     cin >> n >> k;
//     vll v(n);
//     cin >> v;
//     ll totalOnes = accumulate(all(v), 0);
//     // cout << "ones: " << totalOnes << '\n';
//     if (totalOnes < (k + 1) / 2)
//     {
//         cout << 0 << '\n';
//         return;
//     }
//     ll sum = 0;
//     for (ll i = (k + 1) / 2; i <= min(totalOnes, k); i++)
//     {
//         ll ones = choose(totalOnes, i);
//         ll zeros = choose(n - totalOnes, k - i);
//         ll mult = ((ones % mod) * (zeros % mod)) % mod;
//         sum = ((sum % mod) + (mult % mod)) % mod;
//     }
//     cout << sum % mod << '\n';
// }

// int main()
// {
//     FastRead;
//     fact[0] = 1;
//     for (ll i = 1; i < 200005; i++)
//         fact[i] = (fact[i - 1] * i) % mod;
//     int t = 1;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }
const int mod = 1000000007;
const int MAX = 2e6 + 5;
ll fact[MAX];

ll modMult(ll a, ll b)
{
    return (a % mod * b % mod) % mod;
}

ll power(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = modMult(res, x);
        x = modMult(x, x);
        n >>= 1;
    }
    return res;
}

ll modInv(ll x)
{
    return power(x, mod - 2);
}

ll choose(ll N, ll K)
{
    if ((N == 0 && K != 0) || K > N)
    {
        return 0LL;
    }

    ll denum = modMult(fact[N - K], fact[K]);
    return modMult(fact[N], modInv(denum));
}

ll C(ll n, ll k)
{
    if ((n == 0 && k != 0) || (k > n))
    {
        return 0;
    }

    ll res = 1;
    if (k > n - k)
        k = n - k;
    for (ll i = 0; i < k; ++i)
    {
        res = modMult(res, (n - i));
        res = modMult(res, modInv(i + 1));
    }

    return res;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vll v(n);
    cin >> v;

    ll totalOnes = accumulate(v.begin(), v.end(), 0LL);

    if (totalOnes < (k + 1) / 2)
    {
        cout << 0 << '\n';
        return;
    }
    ll sum = 0;
    for (ll i = (k + 1) / 2; i <= min(totalOnes, k); i++)
    {
        ll ones = choose(totalOnes, i);
        ll zeros = choose(n - totalOnes, k - i);
        ll mult = modMult(ones, zeros);

        sum = (sum + mult) % mod;
    }

    cout << sum << '\n';
}

int main()
{
    FastRead;
    fact[0] = 1;
    for (ll i = 1; i < MAX; i++)
    {
        fact[i] = modMult(fact[i - 1], i);
    }

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}