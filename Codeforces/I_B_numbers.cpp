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

// Function to compute the smallest prime factor for each number
vector<int> spf;
void sieve(int n)
{
    for (int i = 1; i < n; i++)
    {
        spf[i] = i;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}
map<int, int> primeFactors;
// Function to get the prime factorization using the spf array
vector<int> getPrimeFactors(int x, bool add = true)
{
    vector<int> factors;

    while (x != 1)
    {
        if (add)
        {

            primeFactors[spf[x]]++;
        }
        factors.push_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}
// 32400
// 1 2 4
// 4 3 2

// maximum in k there is 9 primes

// total primes less than 1000

vector<int> getDivisors(int x)
{
    vector<int> divisors;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            divisors.push_back(i);
            if (i != x / i)
            {
                divisors.push_back(x / i);
            }
        }
    }
    return divisors;
}

ll modInverse(ll a, const int mod = 998244353)
{
    ll result = 1, exp = mod - 2;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        exp /= 2;
    }
    return result;
}

ll C(int n, int k, const int MOD = 998244353)
{
    ll res = 1;
    if (k > n - k)
        k = n - k;

    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res %= MOD;

        res *= modInverse(i + 1, MOD);
        res %= MOD;
    }
    return res;
}
// 2 4 4
// - - - -
const int md = 998244353;
void solve()
{
    int n, k;
    cin >> n >> k;
    vi pFactors = getPrimeFactors(k, false);
    reverse(all(pFactors));
    cout << k << ": " << getPrimeFactors(k, false) << endl;
    vector<ll> res(pFactors.size(), 0LL);
    // cout << getDivisors(32400).size() << endl;
    for (int i = 2; i <= n; i++)
    {
        cout << i << ": " << getPrimeFactors(i) << endl;
    }
    cout << endl;
    for (auto x : primeFactors)
    {
        cout << x.F << " : " << x.S << endl;
    }
    for (int i = 0; i < pFactors.size(); i++)
    {
        int c = 0;
        for (auto x : primeFactors)
        {
            if (x.S >= pFactors[i] - 1)
            {
                c++;
            }
        }
        res[i] = C(c, pFactors[i]) - i;
    }
    ll ans = 1;
    for (auto x : res)
    {
        ans = ((ans % md) * (x % md)) % md;
    }
    cout << ans % md << endl;
}

int main()
{
    FastRead;
    int t = 1;
    // cin >> t;
    spf.resize(1002);
    sieve(1002);
    while (t--)
    {
        solve();
    }
    return 0;
}