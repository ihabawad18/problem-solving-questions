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

vi v;
// int dp[100005][1024];

// int dpSolve(int n, int prevNb)
// {
//     if (n == v.size())
//     {
//         return 0;
//     }
//     int &ret = dp[n][prevNb];
//     if (ret != -1)
//         return ret;
//     ret = 1e9;

//     if (prevNb <= v[n])
//     {
//         ret = min(ret, dpSolve(n + 1, v[n]));
//     }
//     else
//     {
//         // make me equal
//         int ops = __builtin_popcount(v[n] ^ prevNb);
//         ret = min(ret, dpSolve(n + 1, prevNb) + ops);
//         // use the biggest bit to make me greater
//         int biggestBit = __lg(prevNb), temp = v[n];
//         if (biggestBit == 9)
//         {
//             int ops2 = 0;
//             for (int i = 9; i >= 0; i--)
//             {
//                 if (!prevNb & (1 << i))
//                 {
//                     if (v[n] & (1 << i))
//                     {
//                         break;
//                     }
//                     else
//                     {
//                         ops2++;
//                         temp |= (1 << i);
//                     }
//                 }
//                 if (prevNb & (1 << i) && !(v[n] & (1 << i)))
//                 {
//                     ops2++;
//                     temp |= (1 << i);
//                 }
//             }
//             ret = min(ret, dpSolve(n + 1, temp) + ops2);
//         }
//         else
//         {
//             ret = min(ret, dpSolve(n + 1, v[n] | (1 << biggestBit)) + 1);
//         }
//     }
//     return ret;
// }
void solve()
{
    // MEM(dp, -1);
    int n;
    cin >> n;
    v.resize(n);
    cin >> v;
    // cout << dpSolve(1, v[0]) << endl;
    vector<int> dp(1024, 1e9), next_dp(1024);

    // Initialize the base case
    fill(dp.begin(), dp.end(), 0);

    for (int i = n - 1; i >= 1; i--)
    {
        fill(next_dp.begin(), next_dp.end(), 1e9);

        for (int j = 1023; j >= v[0]; j--)
        {
            if (j <= v[i])
            {
                next_dp[j] = min(next_dp[j], dp[v[i]]);
            }
            else
            {
                // make me equal
                int ops = __builtin_popcount(v[i] ^ j);
                next_dp[j] = min(next_dp[j], dp[j] + ops);

                // use the biggest bit to make me greater
                int biggestBit = __lg(j), temp = v[i];
                if (biggestBit == 9)
                {
                    int ops2 = 0;
                    for (int k = 9; k >= 0; k--)
                    {
                        if (!(j & (1 << k)))
                        {
                            if (v[i] & (1 << k))
                            {
                                break;
                            }
                            else
                            {
                                ops2++;
                                temp |= (1 << k);
                            }
                        }
                        if ((j & (1 << k)) && !(v[i] & (1 << k)))
                        {
                            ops2++;
                            temp |= (1 << k);
                        }
                    }
                    next_dp[j] = min(next_dp[j], dp[temp] + ops2);
                }
                else
                {
                    next_dp[j] = min(next_dp[j], dp[v[i] | (1 << biggestBit)] + 1);
                }
            }
        }

        dp.swap(next_dp);
    }

    cout << dp[v[0]] << endl;
}

int main()
{
    FastRead;
    int t = 1;
    //   cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}