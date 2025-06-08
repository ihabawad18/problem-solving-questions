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
#define FastRead ios_base::sync_with_stdio(false);

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
// ===================================END Of the input module ==========================================

// ====================================start of the segment tree=========================================


struct segmenttree {
  struct data{
    ll seg,pref,suff,sum;
    data(ll _val){
            sum = _val ;
            pref = suff = seg = max(0LL,_val) ;
    }
  };
  int n;
  vector<data> st;
  void init(int _n) {
    this->n = _n;
    st.resize(4 * n,data(0));
  }
  void currbest(){
        cout << st[0].seg << endl ;
    }
  
  void build(int start, int ending, int node, vector<int> &v) {
    // leaf node base case
    if (start == ending) {
      st[node] = data(v[start]);
      return;
    }

    int mid = (start + ending) / 2;

    // left subtree is (start,mid)
    build(start, mid, 2 * node + 1, v);

    // right subtree is (mid+1,ending)
    build(mid + 1, ending, 2 * node + 2, v);

    st[node] = operation(st[node * 2 + 1] , st[node * 2 + 2]);
  }
  void update(int start, int ending, int node, int index, int value) {
    // base case
    if (start == ending) {
      st[node] = data(value);
      return;
    }

    int mid = (start + ending) / 2;
    if (index <= mid) {
      // left subtree
      update(start, mid, 2 * node + 1, index, value);
    } else {
      // right
      update(mid + 1, ending, 2 * node + 2, index, value);
    }

    st[node] = operation(st[node * 2 + 1] , st[node * 2 + 2]);
  }
  data operation(data l,data r){
        data new_(0) ;
        new_.sum = l.sum + r.sum ;
        new_.suff = max(r.suff, l.suff + r.sum) ;
        new_.pref = max(l.pref , l.sum + r.pref) ;
        new_.seg =  max({l.seg,r.seg, r.pref + l.suff}) ;
        return new_ ;
  }

  void build(vector<int> &v) { build(0, n - 1, 0, v); }
  void update(int x, int y) { update(0, n - 1, 0, x, y); }
};
// ========================================= Segment tree ends here====================================



void solve() {
    int n,q;
    cin >> n >> q;
    vi v(n);
    cin >> v;
    segmenttree s;
    s.init(n);
    s.build(v);
    while(q--){
      int l,v;
      cin >> l>>v;
      s.update(l-1,v);
      s.currbest();
  }
}

int main() {
  FastRead;
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}