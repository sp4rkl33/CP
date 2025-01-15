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
//using ordered_set = tree <type1, null_type, less <type1>, rb_tree_tag, tree_order_statistics_node_update>;

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
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
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
#define pp pair<pair<int, int>, int>

int solve(){
	string s; cin>>s;
	int n = s.length(), q; cin>>q;
	vector<pp> v(4 * n + 7);
	
	auto f=[&](pp x, pp y){
		pp e; e.ff.ss = 0; e.ff.ff = 0;
		int l = x.ff.ff, r = y.ff.ss; e.ss = min(l, r) * 2 + x.ss + y.ss;
		int gap = abs(l - r);
		if (l > r) e.ff.ff = gap;
		else e.ff.ss = gap;
		e.ff.ff += y.ff.ff; e.ff.ss += x.ff.ss;
		return e;
	};
	
	auto build=[&](auto self, int l, int r, int idx) -> void{
		if (l < r){
			int mid = (l + r) / 2;
			self(self, l, mid, idx * 2);
			self(self, mid + 1, r, idx * 2 + 1);
			v[idx]=f(v[idx * 2], v[idx * 2 + 1]);
		} else {
			if (s[l] == '(') v[idx].ff.ff++;
			else v[idx].ff.ss++;
		}
	};
	
	auto sol=[&](auto self, int L, int R, int l, int r, int idx) -> pp{
		pp t;
		t.ff.ff = 0; t.ff.ss = 0; t.ss = 0;
		if (l > R || r < L) return t;
		if (L >= l && R <= r) return v[idx];
		int mid=(L + R) / 2;
		pp el = self(self, L, mid, l, r, idx * 2), er = self(self, mid+1, R, l, r, idx * 2 + 1);
		return f(el, er);
	};

	build(build, 0, n - 1, 1);

	while (q--){
		int x, y; cin>>x>>y; x--; y--;
		cout<<sol(sol, 0, n - 1, x, y, 1).ss<<'\n';
	}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
}
