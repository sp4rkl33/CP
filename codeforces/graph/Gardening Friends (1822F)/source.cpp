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

ll solve(){
    int n; ll k, c; cin >> n >> k >> c;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<ll> disR(n + 1), disA(n + 1), disB(n + 1);
    int mx = 0, A = 0, B = 0; //Initialize out endpoints and mx_length

    //we only use 1 DFS function to do everything we need.
    auto dfs = [&](auto self, int u, int dist, int pst, int &f, auto &d) -> void{
        d[u] = dist;

	//this if statement only used for finding 2 endpoints.
        if (mx < dist){ 
            f = u;
            mx = dist;
        }
	    
        for (int v:g[u]) if (v != pst) self(self, v, dist + 1, u, f, d);
    };

    //find A and disR
    mx = 0; dfs(dfs, 1, 0, 0, A, disR);
    //find B and disA
    mx = 0; dfs(dfs, A, 0, 0, B, disA);
    //find disB
    dfs(dfs, B, 0, 0, mx, disB);

    ll ans = 0;
    for (int i = 1; i <= n; i++) ans = (ll)max(ans, max(disA[i], disB[i]) * k - disR[i] * c);

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	retsolve
}
 
