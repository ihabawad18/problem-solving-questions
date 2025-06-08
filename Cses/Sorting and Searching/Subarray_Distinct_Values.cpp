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

// sol1
//  void solve()
//  {
//      int n, k;
//      cin >> n >> k;
//      vi v(n);
//      cin >> v;
//      ll l = 0, j = 0, c = 0;
//      map<int, set<int>> mp;
//      while (l < n)
//      {
//          mp[v[l]].insert(l);
//          ll temp1 = l - 1, temp2 = j;
//          while (j < l && mp.size() > k)
//          {

//             mp[v[j]].erase(j);
//             if (mp[v[j]].empty())
//             {
//                 c += (temp1 - temp2 + 1) * (temp1 - temp2 + 2) / 2LL - ((l - j - 1) * (l - j) / 2LL);
//                 mp.erase(v[j]);
//             }
//             j++;
//         }
//         if (l == n - 1)
//         {
//             c += (l - j + 1) * (l - j + 2) / 2LL;
//         }
//         l++;
//     }
//     cout << c << endl;
// }

// sol 2
void solve()
{
    int n, k;
    cin >> n >> k;
    vi v(n);
    cin >> v;
    ll l = 0, j = 0, c = 0;
    map<int, int> mp;
    while (l < n)
    {
        mp[v[l]]++;
        while (j < l && mp.size() > k)
        {

            mp[v[j]]--;
            if (mp[v[j]] == 0)
            {
                mp.erase(v[j]);
            }
            j++;
        }
        c += l - j + 1;
        l++;
    }
    cout << c << endl;
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