#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct segmenttree {
    int n;
    vector<long long> st, lazy;
 
    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }
 
    void build(int start, int ending, int node, vector<long long> &v) {
        // leaf node base case
        if (start == ending) {
            st[node] = v[start];
            return;
        }
 
        int mid = (start + ending) / 2;
 
        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);
 
        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);
 
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
    }
 
    long long query(int start, int ending, int l, int r, int node) {
        // non overlapping case
        if (start > r || ending < l) {
            return 0;
        }
 
        // lazy propagation / clear the lazy update
        if (lazy[node] != 0) {
            // pending updates
            // update the segment tree node
            st[node] += lazy[node] * 1LL *(ending - start + 1);
            if (start != ending) {
                // propagate the updated value
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
 
        // complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }
 
        // partial case
        int mid = (start + ending) / 2;
 
        long long q1 = query(start, mid, l, r, 2 * node + 1);
        long long q2 = query(mid + 1, ending, l, r, 2 * node + 2);
 
        return q1 + q2;
    }
 
    void update(int start, int ending, int node, int l, int r, int value) {
        // non overlapping case
        if (start > r || ending < l) {
            return ;
        }
 
        // lazy propagation / clear the lazy update
        if (lazy[node] != 0) {
            // pending updates
            // update the segment tree node
            st[node] += lazy[node] * 1LL*(ending - start + 1);
            if (start != ending) {
                // propagate the updated value
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
 
        // complete overlap
        if (start >= l && ending <= r) {
            st[node] += (long long )(value *1LL* (ending - start + 1));
            if (start != ending) {
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }
 
        // partial case
        int mid = (start + ending) / 2;
 
        update(start, mid, 2 * node + 1, l, r, value);
 
        update(mid + 1, ending, 2 * node + 2, l, r, value);
 
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];
 
        return;
    }
 
    void build(vector<long long> &v) {
        build(0, n - 1, 0, v);
    }
 
    ll query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }
 
    void update(int l, int r, int x) {
        update(0, n - 1, 0, l, r, x);
    }
};
 
int main()
{
    int n,q;
    cin >> n >> q;
    vector<long long> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    segmenttree tree;
 
    tree.init(v.size());
 
    tree.build(v);
    while(q--){
        int x;
        cin >> x;
        if(x==1){
            int l,r,val;
            cin >> l >> r >> val;
            tree.update(l-1,r-1,val);
        }
        else{
            int l;
            cin >> l;
            cout<<tree.query(l-1,l-1)<<endl;
        }
    }
 
 
    return 0;
}