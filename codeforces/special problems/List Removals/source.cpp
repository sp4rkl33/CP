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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}" << "\n";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

void solve(){
    int n, q; cin >> n; q = n;
    vector<int> a(n), v(4 * n + 7); for (auto &it : a) cin >> it;

    auto build = [&](auto self, int l, int r, int idx) -> void{
        if (l < r){
            int mid = (l + r) / 2;
            self(self, l, mid, 2 * idx);
            self(self, mid + 1, r, 2 * idx + 1);
            v[idx] = v[idx * 2] + v[idx * 2 + 1];
        } else v[idx] = 1;
    };

    auto update = [&](auto self, int l, int r, int k, int idx) -> void{
        if (l > k || k > r) return;
        if (l == r) {
            v[idx] = 0;
            return;
        }
        int mid = (l + r) / 2;
        self(self, l, mid, k, 2 * idx);
        self(self, mid + 1, r, k, 2 * idx + 1);
        v[idx] = v[idx * 2] + v[idx * 2 + 1];
    };

    auto sol = [&](auto self, int l, int r, int L, int R, int idx) -> int{
        if (R < l || r < L) return 0;
        if (L <= l && r <= R) return v[idx];
        int mid = (l + r) / 2;
        return self(self, l, mid, L, R, 2 * idx) + self(self, mid + 1, r, L, R, 2 * idx + 1);
    };
    //
    build(build, 0, n - 1, 1);
    while(q--){
        int x, p; cin >> x;
        int l = 0, r = n - 1;
        while (l <= r){
            int mid = (l + r) / 2, res = sol(sol, 0, n - 1, 0, mid, 1);
            if (res < x) l = mid + 1;
			else if (res > x) r = mid - 1;
			else{
				p = mid;
				r = mid - 1;
			}
        }
        update(update, 0, n - 1, p, 1);
        cout << a[p] << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
