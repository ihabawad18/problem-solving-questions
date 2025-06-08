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

void dfs(int u, vector<vi> &adj, vi &vis)
{
    vis[u] = 1;
    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v, adj, vis);
        }
    }
}

vector<pair<int, int>> bridges;
vector<int> disc, low, parent;
int timee = 0;

void dfs_bridge(int u, vector<vi> &adj)
{
    disc[u] = low[u] = ++timee;
    for (int v : adj[u])
    {
        if (disc[v] == -1)
        {
            parent[v] = u;
            dfs_bridge(v, adj);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u])
            {
                bridges.push_back({u, v});
            }
        }
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int findBridges(int n, vector<vi> &adj)
{
    disc.assign(n + 1, -1);
    low.assign(n + 1, -1);
    parent.assign(n + 1, -1);
    timee = 0;
    bridges.clear();

    for (int i = 1; i <= n; i++)
    {
        if (disc[i] == -1)
        {
            dfs_bridge(i, adj);
        }
    }

    return bridges.size();
}

void solve()
{
    int n, e, x;
    cin >> n >> e >> x;
    vector<vi> adj(n + 1, vi());
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi vis(n + 1, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis);
            cnt++;
        }
    }
    int bridgeCount = findBridges(n, adj);
    // cout << "bridgeCount: " << bridgeCount << '\n';
    int op1 = 0, op2 = x - cnt;
    // cout << "op2: " << op2 << '\n';
    if (op2 < 0)
    {
        cout << -1 << '\n';
        return;
    }
    if (bridgeCount > 0)
    {

        op1 = min(bridgeCount, op2);
        op2 = op2 - min(bridgeCount, op2);
    }
    cout << op1 + op2 << '\n';
    cout << op1 << " " << op2 << '\n';
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