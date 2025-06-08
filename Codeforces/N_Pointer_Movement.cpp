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

// Function to compute the LPS (Longest Prefix Suffix) array
vector<int> computeLPSArray(const string &pattern)
{
    int m = pattern.length();
    vector<int> lps(m);
    int length = 0; // length of the previous longest prefix suffix
    lps[0] = 0;     // lps[0] is always 0

    int i = 1;
    while (i < m)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP algorithm to find all occurrences of the pattern in the text
vector<pair<int, int>> KMPSearch(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = computeLPSArray(pattern);
    vector<pair<int, int>> occurrences; // To store the start and end indexes of each occurrence

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            // Found an occurrence of the pattern
            int start = i - j;
            int end = i - 1;
            occurrences.push_back({start, end});
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return occurrences;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s, p;
    cin >> s >> p;
    if (n == 1)
    {
        cout << "YES\n";
        return;
    }

    // see the positions of p in s
    vpi poss = KMPSearch(s, p);
    // validate the positions
    int last = 0;
    for (auto x : poss)
    {
        if (x.F - last - 1 >= k)
        {
            cout << "NO\n";
            return;
        }
        last = x.S;
    }
    if (poss.empty())
    {
        cout << "NO\n";
        return;
    }
    cout << (poss[poss.size() - 1].S != n - 1 ? "NO\n" : "YES\n");
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