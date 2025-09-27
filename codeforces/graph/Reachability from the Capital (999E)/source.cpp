#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#include <e:\\cp\\debug_template.cpp>
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

void solve(){
    int n, m, s; cin >> n >> m >> s;
    vector<vector<int>> adj(n + 1), tAdj(n + 1);
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        edges.emplace_back(u, v);
        adj[u].emplace_back(v);
        tAdj[v].emplace_back(u);
    }
 
    stack<int> st;
    vector<int> vis(n + 1);
    vector<vector<int>> scc;
 
    auto dfs = [&](auto self, int u) -> void{
        if (vis[u]) return;
        vis[u] = 1;
        for (int v : adj[u]){
            if (!vis[v]) self(self, v);
        }
 
        st.push(u);
    };
    
    auto dfs2 = [&](auto self, int u, vector<int> &tmp) -> void{
        if (vis[u]) return;
        vis[u] = 1;
        tmp.emplace_back(u);
        for (int v : tAdj[u]){
            if (!vis[v]) self(self, v, tmp);
        }
    };
    
    dfs(dfs, s); st = std::stack<int>();

    for (int i = 1; i <= n; i++){
        if (!vis[i]) dfs(dfs, i);
    }
    
    vis.assign(n + 1, 0);
     
    while (!st.empty()){
       if (!vis[st.top()]){
           vector<int> t;
           dfs2(dfs2, st.top(), t);
           scc.emplace_back(t);
       }
       st.pop();
    }
    
    int cnt = 0;
    vis.assign(n + 1, 0);
    
    for (auto it : scc){
        for (int u : it){
            if (!vis[u]){
                cnt++;
                dfs(dfs, u);
            }
        }
    }

    cout << cnt << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    multi_testcase
    return 0;
}
