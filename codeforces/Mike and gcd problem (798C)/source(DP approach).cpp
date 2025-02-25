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
    int n; cin >> n;
    vector<int> a(n); for (auto &it:a) cin >> it;
    vector<pair<int, int>> f(n); 
    int z = a[0];
    if (a[0] % 2 == 1) f[0] = make_pair(2, 1);

    for (int i = 1; i < n; i++){
        z = __gcd(z, a[i]);
        if (a[i] % 2 == 1){
            if (a[i - 1] % 2 == 0) {
                f[i].ff = f[i - 1].ff + 2;
                f[i].ss = 1;
            }
            else {
                if (f[i - 1].ss == 1){
                    f[i].ff = f[i - 1].ff - 1;
                    f[i].ss = 2;
                    f[i].ss = 2;
                } else if (f[i - 1].ss == 0){
                    f[i].ff = f[i - 1].ff + 1;
                    f[i].ss = 2;
                    f[i].ss = 2;
                } else {
                    f[i].ff = f[i - 1].ff + 2;
                    f[i].ss = 1;
                }
            }
        } else f[i].ff = f[i - 1].ff;
    }
    cout << "YES\n" << (z > 1 ? 0 : f[n - 1].ff);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
}
