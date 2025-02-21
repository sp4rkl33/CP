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

ull maxN = 1e18 + 5e17;

void solve(){
	int n; cin>>n;
	vector<ull> a(n); for (auto &it:a) cin>>it;
	auto dfs = [&](auto self, ull x, map<ull, bool> &mp, vector<ull> &ans) -> void{
		mp[x]=0;
		ans.emplace_back(x);
		for (int i=0; i<2; i++){
			if (i%2){
				if (x<=maxN && mp[x*2]) self(self, x*2, mp, ans); 
			} else {
				if (x%3==0 && mp[x/3]) self(self, x/3, mp, ans);
			}
		}
	};
	
	vector<ull> ans;
	for (int i=0; i<n; i++){
		map<ull, bool> mp;
		for (int z=0; z<n; z++) mp.insert(make_pair(a[z], 1));		
		ans.clear();
		dfs(dfs, a[i], mp, ans);
		if (ans.size() == n) break;
	}
	for (ull it:ans) cout<<it<<" ";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
}
