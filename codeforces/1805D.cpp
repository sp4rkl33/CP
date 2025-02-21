#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
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
	int n; cin>>n;
	vector<vector<int>> g(n);
	for (int i=0; i<n-1; i++){
		int x, y; cin>>x>>y; x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<int> dis(n), disL(n), disR(n);
	int mx = 0, _l, _r;
	auto dfs = [&](auto self, int u, int d, int pst, int &farth, vector<int> &dist) -> void{
		dist[u]=d;
		if (mx<d){
			farth=u;
			mx=d;
		}
		for(int i:g[u]) if (i != pst) self(self, i, d+1, u, farth, dist);
	};
	
	dfs(dfs, 0, 0, 0, _l, dis);
	mx = 0; dfs(dfs, _l, 0, _l, _r, disL);
	dfs(dfs, _r, 0, _r, mx, disR);
	
	dis.resize(n,0);
	for (int i=0; i<n; i++) dis[i] = max(disL[i], disR[i]);
	sort(dis.begin(), dis.end());
	//__print(dis); cout<<'\n';
	for (int i=1; i<=n; i++) {
		int ans = (int)(lower_bound(dis.begin(), dis.end(), i) - dis.begin());
		cout<<min(ans + 1, n)<<" ";
	}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}
