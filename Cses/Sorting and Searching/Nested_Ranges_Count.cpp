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

    ll query(int start, int ending, int l, int r, int node)
    {
        // non overlapping case
        if (start > r || ending < l)
        {
            return skip;
        }

        // complete overlap
        if (start >= l && ending <= r)
        {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        ll q1 = query(start, mid, l, r, 2 * node + 1);
        ll q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return merge(q1, q2);
    }

    void update(int start, int ending, int node, int index, int value)
    {
        // base case
        if (start == ending)
        {
            st[node] += value;
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

    ll query(int l, int r) { return query(0, n - 1, l, r, 0); }

    void update(int x, int y) { update(0, n - 1, 0, x, y); }
};
// ========================================= Segment tree ends here====================================

// coordinate compression or implicit segment tree
vi values;

int data_compress(int val)
{
    return lower_bound(all(values), val) - values.begin();
}

void solve()
{
    int n;
    cin >> n;
    vpi v(n);
    cin >> v;
    vvi mod_array(n, vi(3));
    for (int i = 0; i < n; i++)
    {
        values.push_back(v[i].F);
        values.push_back(v[i].S);
    }
    srt(values);
    unique(values);
    for (int i = 0; i < n; i++)
    {
        mod_array[i][0] = data_compress(v[i].F);
        mod_array[i][1] = data_compress(v[i].S);
        mod_array[i][2] = i;
    }
    sort(all(mod_array), [](vi a, vi b)
         {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0]; });

    const int MA = values.size() + 2;
    vi temp1(MA, 0), temp2(MA, 0);
    segmenttree contain, contained;

    contain.init(MA, temp1);
    contained.init(MA, temp2);

    vi ans1(n, 0), ans2(n, 0);
    for (int i = 0; i < n; i++)
    {
        ans2[mod_array[i][2]] = contained.query(mod_array[i][1], MA);
        contained.update(mod_array[i][1], 1);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        ans1[mod_array[i][2]] = contain.query(0, mod_array[i][1]);
        contain.update(mod_array[i][1], 1);
    }

    cout << ans1 << endl;
    cout << ans2 << endl;
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