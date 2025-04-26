#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
#define retsolve int t; cin>>t; while(t--){cout<<solve()<<'\n';}
#define voidsolve int t; cin>>t; while(t--){solve();}
#define ff first
#define ss second

using namespace std;
using namespace __gnu_pbds;

template <class type1>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;
template <class type1>
using ordered_set = tree <type1, null_type, less <type1>, rb_tree_tag, tree_order_statistics_node_update>;

class elm{
    public:
        int freeL; int freeR; int cnt;  
        elm():freeL(0), freeR(0), cnt(0) {}
        elm(int freeL, int freeR, int cnt) : freeL(freeL), freeR(freeR), cnt(cnt) {}               
};

void solve(){
    string s; cin >> s;
    int n, q; cin >> q; n = s.length();
    vector<elm> v(4000007);

    //merging operation
    auto merge = [&](elm l, elm r) -> elm{ // calculate current node by merging 2 left and right node
        int cur = min(l.freeL, r.freeR);
        elm ans;
        ans.freeL = l.freeL - cur + r.freeL;
        ans.freeR = l.freeR + r.freeR - cur;
        ans.cnt = cur + l.cnt + r.cnt;
        return ans;
    };
    
    //segment tree build function
    auto build = [&](auto self, int idx, int l, int r) -> void{ //function to build segment tree
        if (l < r){
            int mid = (l + r) / 2;
            self(self, idx * 2, l, mid);
            self(self, idx * 2 + 1, mid + 1, r);
            v[idx] = merge(v[idx * 2], v[idx * 2 + 1]);
        } else if (l == r){
            if (s[l] == ')') v[idx].freeR++;
            else v[idx].freeL++;
        }
    };

    //traversing based on query.
    auto sol = [&](auto self, int l, int r, int L, int R, int idx) -> elm{
        elm p(0, 0, 0);
        if (r < L || R < l) return p; //if range outside the query return default 0 elm
        if (l >= L && R >= r) return v[idx]; // lazy traversal
        int mid = (l + r) / 2;
        elm left = self(self, l, mid, L, R, idx * 2);
        elm right = self(self, mid + 1, r, L, R, idx * 2 + 1);
        return merge(left, right);
    };

    build(build, 1, 0, n - 1);

    while (q--){
        int l, r; cin >> l >> r; l--; r--;
        cout << sol(sol, 0, n - 1, l, r, 1).cnt * 2 << '\n';
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
