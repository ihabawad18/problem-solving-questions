// Problem: Distinct Colors
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1139
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
#define all(c) (c).begin(), (c).end()
#define srt(c) sort(all(c))
#define pb push_back
#define unique(a) a.erase(unique(all(a)), a.end())  // ssseeesss would be ses
#define FastRead                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);

vi val, flattened, intime, outime, freqNode, freqColor;

vvi graph;

int timer = 0, ans = 0, block_size = 400;

void dfs(int i, int par) {
  flattened[timer] = i;
  intime[i] = timer++;
  for (auto child : graph[i]) {
    if (child != par) {
      dfs(child, i);
    }
  }
  flattened[timer] = i;
  outime[i] = timer++;
}

void remove(int idx) {
  int node = flattened[idx];
  freqNode[node]--;
  if (freqNode[node] == 1) {
    if (freqColor[val[node]] == 1) {
      ans--;
    }
    freqColor[val[node]]--;
  }
}
void add(int idx) {
  int node = flattened[idx];
  freqNode[node]++;
  if (freqNode[node] == 2) {
    if (freqColor[val[node]] == 0) {
      ans++;
    }
    freqColor[val[node]]++;
  }
}
ll get_answer() { return ans; }

struct Query {
  int l, r, idx;
  bool operator<(Query other) const {
    int num = l / block_size;
    if (num != other.l / block_size) {
      return l < other.l;
    }
    if (num & 1) {
      return r < other.r;
    }
    return r > other.r;
  }
};

vector<ll> mo_s_algorithm(vector<Query> &queries) {
  vector<ll> answers(queries.size());
  sort(queries.begin(), queries.end());

  // TODO: initialize data structure
  int cur_l = 0;
  int cur_r = -1;
  // invariant: data structure will always reflect the range [cur_l, cur_r]
  for (Query q : queries) {
    while (cur_l > q.l) {
      cur_l--;
      add(cur_l);
    }
    while (cur_r < q.r) {
      cur_r++;
      add(cur_r);
    }
    while (cur_l < q.l) {
      remove(cur_l);
      cur_l++;
    }
    while (cur_r > q.r) {
      remove(cur_r);
      cur_r--;
    }
    answers[q.idx] = get_answer();
  }
  return answers;
}

vi uni;

int compress(int i) { return lower_bound(all(uni), i) - uni.begin(); }

void solve() {
  int n;
  cin >> n;
  val.resize(n);
  flattened.resize(2 * n);
  intime.resize(n);
  outime.resize(n);
  graph.resize(n);
  freqNode.resize(n);
  freqColor.resize(int(2e5) + 5);
  for (int i = 0; i < n; i++) {
    cin >> val[i];
    uni.pb(val[i]);
  }
  srt(uni);
  unique(uni);
  for (int i = 0; i < n; i++) {
    val[i] = compress(val[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    graph[x].pb(y);
    graph[y].pb(x);
  }
  dfs(0, -1);
  vector<Query> queries;
  for (int i = 0; i < n; i++) {
    queries.pb({intime[i], outime[i], i});
  }

  vll ans = mo_s_algorithm(queries);
  // cout << flattened << "\n";
  for (auto x : ans) {
    cout << x << ' ';
  }
}

int main() {
  FastRead;
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}