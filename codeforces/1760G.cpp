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

string solve(){
	int n, a, b; cin>>n>>a>>b; 
	vector<vector<pair<int, int>>> g(n+1);
	vector<bool> va(n+1), vb(n+1); va[b]=va[0]=1;
	for (int i=0; i<n-1; i++){
		int u, vv, w; cin>>u>>vv>>w;
		g[u].emplace_back(make_pair(vv, w));
		g[vv].emplace_back(make_pair(u, w));
	}
	
	map<int, bool> mp;
	bool f=0;
	
	auto dfsb=[&](auto self, int u, int cur) -> void{
		if (u!=b) mp[cur]=1;
		vb[u]=1;
		for (auto it:g[u]) if (!vb[it.ff]) self(self, it.ff, cur ^ it.ss); 
	};
	
	dfsb(dfsb, b, 0);
	
	auto dfs=[&](auto self, int u, int cur){
		va[u]=1;
		if (mp[cur] || f){
			f=1;
			return;
		} 
		for (auto it:g[u]) if (!va[it.ff]) self(self, it.ff, cur ^ it.ss); 
	};
	
	dfs(dfs, a, 0);
	return f ? "YES":"NO";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	retsolve
}
