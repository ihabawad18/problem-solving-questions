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
    int n, m;
    cin >> n >> m;
    vi v(n);
    cin >> v;
    vi pos(n + 1);
    for (int i = 0; i < n; i++)
    {
        pos[v[i]] = i + 1;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (pos[i] < pos[i - 1])
        {
            ans++;
        }
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        int leftValue = v[x - 1], rightValue = v[y - 1];
        set<pi> s;
        if (leftValue > 1)
        {
            s.insert({leftValue - 1, leftValue});
        }
        if (leftValue < n)
        {
            s.insert({leftValue, leftValue + 1});
        }

        if (rightValue > 1)
        {
            s.insert({rightValue - 1, rightValue});
        }
        if (rightValue < n)
        {
            s.insert({rightValue, rightValue + 1});
        }
        for (auto p : s)
        {
            if (p.first == min(leftValue, rightValue) && p.second == max(rightValue, leftValue))
            {
                // edge case if leftValue and rightValue are adjacent
                if (pos[min(leftValue, rightValue)] > pos[max(leftValue, rightValue)])
                {
                    ans--;
                }
                else
                {
                    ans++;
                }
            }
            // leftValue in range case
            else if (p.F == leftValue || p.S == leftValue)
            {
                bool before, next;
                if (p.F == leftValue)
                {
                    before = pos[p.S] > pos[p.F];
                    next = pos[p.S] > pos[rightValue];
                }
                else
                {
                    before = pos[p.S] > pos[p.F];
                    next = pos[rightValue] > pos[p.F];
                }
                if (before ^ next)
                {
                    ans += before ? 1 : -1;
                }
            }
            // rightValue in range case
            else
            {
                bool before, next;
                if (p.F == rightValue)
                {
                    before = pos[p.S] > pos[p.F];
                    next = pos[p.S] > pos[leftValue];
                }
                else
                {
                    before = pos[p.S] > pos[p.F];
                    next = pos[leftValue] > pos[p.F];
                }
                if (before ^ next)
                {
                    ans += before ? 1 : -1;
                }
            }
        }
        pos[leftValue] = y;
        pos[rightValue] = x;
        swap(v[x - 1], v[y - 1]);
        cout << ans << endl;
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