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
class STree{
private:
    vi tree;
    int n;
    int Xor(int v, int tl, int tr, int l, int r) {      
        if (l > r) return 0;
        if (l == tl && r == tr) return tree[v];
        
        int tm = (tl + tr) / 2;
        return Xor(v*2, tl, tm, l, min(r, tm))  ^ Xor(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
    void buildTree(vector<int>& a,int tl, int tr,int v=1){
        if(tl>tr) return;
        if(tl==tr){
            tree[v]=a[tl];
            return;
        }
 
        int mid=(tl+tr)/2;
        buildTree(a,tl,mid,v*2);
        buildTree(a,mid+1,tr,v*2+1);
        tree[v]=tree[v*2]^tree[v*2+1];
    }
    void update(int idx,int val,int v,int tl,int tr){
        if(tl>tr) return;
        if(idx<tl || idx>tr)  return;     //not in the current range
        if(tl==tr){
            tree[v]=val;
            return;
        }
        int tmid=(tl+tr)/2;
        update(idx,val,v*2,tl,tmid);
        update(idx,val,v*2+1,tmid+1,tr);
        tree[v]=tree[v*2]^tree[v*2+1];
    }
public:
    STree(int sz,vector<int>& vec){
        n=sz;
        tree.assign(sz*4,0);
        buildTree(vec,0,n-1);
    }
 
    ll getXor(int l,int r){
        return Xor(1,0,n-1,l,r);         // call the function!
    }
    void update(int idx,int val){     // v is the new value!
        update(idx,val,1,0,n-1);
    }
    void printTree(vector<int>& v){
        cout<<v<<"\n";
    }
 
};
// ========================================= Segment tree ends here====================================
void solve() {
  ll n, q;
  cin >> n >> q;
  vi v(n, 0);
  for (auto &a : v) {
    cin >> a;
  }
  STree st(n,v);
  
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    ll a = st.getXor(x, y);
    cout << a << endl;
  }
  // st.printTree();
}

int main() {
  FastRead;
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}