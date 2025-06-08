#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define FastRead                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

const int MAX_N = 1e5 + 5;

vector<int> primes;
vector<bool> is_prime(MAX_N + 1, true);

void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAX_N; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= MAX_N; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= MAX_N; i++)
    {
        if (is_prime[i])
            primes.pb(i);
    }
}

vector<pair<int, int>> factorize(int n)
{
    vector<pair<int, int>> factors;
    for (int p : primes)
    {
        if (p * p > n)
            break;
        if (n % p == 0)
        {
            int count = 0;
            while (n % p == 0)
            {
                n /= p;
                count++;
            }
            factors.pb({p, count});
        }
    }
    if (n > 1)
        factors.pb({n, 1});
    return factors;
}

void print_factorization(int n)
{
    cout << n << " = ";
    auto factors = factorize(n);
    for (const auto &factor : factors)
    {
        cout << factor.first << "^" << factor.second << " ";
    }
    cout << endl;
}

void solve()
{
    int n, m, a;
    cin >> n >> m;
    bool flag = true;
    vector<int> factors;
    while (m--)
    {
        cin >> a;
        factors.pb(a);
    }

    for (auto x : factorize(n))
    {
        bool ok = false;
        for (auto i : factors)
        {

            if (x.first == i)
            {
                ok = true;
            }
        }
        if (!ok)
        {
            flag = false;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
}

int main()
{
    FastRead;
    sieve();
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}