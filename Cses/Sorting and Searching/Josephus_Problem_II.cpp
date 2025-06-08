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

using namespace __gnu_pbds;
// typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

// ====================================start of the segment tree=========================================
struct segmenttree
{
    int n, skip = 0;
    vector<long long> st;

    ll merge(ll a, ll b)
    {
        return a + b;
    }

    void init(int size, vector<int> &a)
    {
        n = size;
        st.resize(4 * n, skip);
        build(a);
    }

    void build(int start, int ending, int node, vector<int> &v)
    {
        // leaf node base case
        if (start == ending)
        {
            st[node] = v[start];
            return;
        }

        int mid = (start + ending) / 2;

        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);

        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = merge(st[node * 2 + 1], st[node * 2 + 2]);
    }

    ll query(int start, int ending, int node, int k)
    {
        if (start == ending)
        {
            return start;
        }

        int mid = (start + ending) / 2;
        if (st[node * 2 + 1] >= k)
        {
            return query(start, mid, 2 * node + 1, k);
        }

        return query(mid + 1, ending, 2 * node + 2, k - st[node * 2 + 1]);
    }

    void update(int start, int ending, int node, int index, int value)
    {
        // base case
        if (start == ending)
        {
            st[node] = value;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid)
        {
            // left subtree
            update(start, mid, 2 * node + 1, index, value);
        }
        else
        {
            // right
            update(mid + 1, ending, 2 * node + 2, index, value);
        }

        st[node] = merge(st[node * 2 + 1], st[node * 2 + 2]);
    }

    void build(vector<int> &v) { build(0, n - 1, 0, v); }

    ll query(int k) { return query(0, n - 1, 0, k); }

    void update(int x) { update(0, n - 1, 0, x, 0); }
};
// ========================================= Segment tree ends here====================================

// sol 1 Segment tree

// void solve()
// {
//     int n, k;
//     cin >> n >> k;
//     vector<int> v(n + 1, 1);
//     v[0] = 0;
//     segmenttree st;
//     st.init(n + 1, v);
//     int curr = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         curr = (curr + k) % (n - i + 1);
//         int index = st.query(curr + 1);
//         cout << index << " ";
//         st.update(index);
//     }
// }

// Sol 2 ordered statistics tree
void solve()
{
    int n, k;
    cin >> n >> k;
    ordered_set os;
    for (int i = 1; i <= n; i++)
    {
        os.insert(i);
    }
    int curr = 0, c = 0;

    while (os.size())
    {
        curr = (curr + k) % (os.size());
        int index = *os.find_by_order(curr);
        // for (auto x : os)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        os.erase(index);
        cout << index << " ";
        c++;
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