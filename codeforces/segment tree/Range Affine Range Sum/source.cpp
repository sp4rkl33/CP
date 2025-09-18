#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <e:\\cp\\debug_template.cpp>
#define ll long long
#define ull unsigned long long
#define multi_testcase int t = 1; while(t--){solve();}
#define ff first
#define ss second
using namespace std;
using namespace __gnu_pbds;

template <class type1>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;
template <class type1>
using ordered_set = tree <type1, null_type, less <type1>, rb_tree_tag, tree_order_statistics_node_update>;

const ll MOD = 998244353;

struct lazySegmentTree{
    int n;
    vector<ll> v, a, tagB, tagC;
    lazySegmentTree(int sz){
        n = sz;
        v.resize(4 * n + 3); tagB.resize(4 * n + 3, 1); tagC.resize(4 * n + 3, 0); a.resize(n);
        for (auto &it : a) cin >> it;
    }
    
    void applyTag(int l, int r, int idx){
        if (!(tagB[idx] != 1 || tagC[idx] != 0)) return;
        
        v[idx] = ((tagB[idx] * v[idx]) % MOD + ((ll)(r - l + 1) * tagC[idx]) % MOD) % MOD;

        if (l < r){
            tagB[idx * 2] = (tagB[idx * 2] * tagB[idx]) % MOD;
            tagC[idx * 2] = ((tagB[idx] * tagC[idx * 2]) % MOD + tagC[idx]) % MOD;
            tagB[idx * 2 + 1] = (tagB[idx * 2 + 1] * tagB[idx]) % MOD;
            tagC[idx * 2 + 1] = ((tagB[idx] * tagC[idx * 2 + 1]) % MOD + tagC[idx]) % MOD;
        }

        tagB[idx] = 1; tagC[idx] = 0;
    }

    void build(int l, int r, int idx){
        if (l < r) {
            int mid = (l + r) / 2;
            build(l, mid, 2 * idx);
            build(mid + 1, r, 2 * idx + 1);
            v[idx] = (v[idx * 2] + v[idx * 2 + 1]) % MOD;
        } else v[idx] = a[l];
    }

    void update(int l, int r, int L, int R, int idx, ll b, ll c) {
        applyTag(l, r, idx);
        if (r < L || R < l) return;

        if (L <= l && r <= R) {
            tagB[idx] = (tagB[idx] * b) % MOD;
            tagC[idx] = ((b * tagC[idx]) % MOD + c) % MOD;
            applyTag(l, r, idx);
            return;
        }

        int mid = (l + r) / 2;
        update(l, mid, L, R, 2 * idx, b, c);
        update(mid + 1, r, L, R, 2 * idx + 1, b, c);
        v[idx] = (v[idx * 2] + v[idx * 2 + 1]) % MOD;
    }

    ll query(int l, int r, int L, int R, int idx){
        applyTag(l, r, idx);
        if (r < L || R < l) return 0LL;

        if (L <= l && r <= R) return v[idx];

        int mid = (l + r) / 2;
        return (query(l, mid, L, R, 2 * idx) + query(mid + 1, r, L, R, 2 * idx + 1)) % MOD;
    }

    void build(){build(0, n - 1, 1);}
    void update(int l, int r, ll b, ll c){update(0, n - 1, l, r, 1, b, c);}
    ll query(int l, int r){return query(0, n - 1, l, r, 1);}
};

void solve(){
    int n, q; cin >> n >> q;
    lazySegmentTree st(n); st.build();

    while (q--){
        int t, l, r; cin >> t >> l >> r; r--;
        if (!t) {
            ll b, c; cin >> b >> c;
            st.update(l, r, b, c);
        } else cout << st.query(l, r) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    multi_testcase
    return 0;
}

