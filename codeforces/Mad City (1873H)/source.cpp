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

string solve(){
    int n, a, b; cin >> n >> a >> b;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> v(n + 1);
    int p = -1;

    auto dfs = [&](auto self, int u, int pst) -> void{
        v[u] = 1;
        for (int it:g[u]){
            if (p != -1) return;
            if (!v[it]) self(self, it, u);
            else if (it != pst) {
                p = it;
                return;
            }
        }
    };

    auto bfs = [&](auto self, int u) -> int{
        queue<int> q;
        vector<int> d(n + 1, 1 << 30);
        q.push(u);
        d[u] = 0; 
        vector<bool> v(n + 1); v[u] = 1;
        while(!q.empty()){
            int it = q.front(); q.pop();
            for (int i:g[it]){
                if (v[i]) continue;
                d[i] = d[it] + 1;
                v[i] = 1;
                q.push(i);
            }
        }
        return d[p];
    };

    dfs(dfs, b, 0);

    return bfs(bfs, b) < bfs(bfs, a) ? "yes" : "no";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	  retsolve
}
 
