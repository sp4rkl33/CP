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

//template <class type1>
//using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;
//template <class type1>
//using ordered_set = tree <type1, null_type, less <type1>, rb_tree_tag, tree_order_statistics_node_update>;
//
//void __print(int x) {cerr << x;}
//void __print(long x) {cerr << x;}
//void __print(long long x) {cerr << x;}
//void __print(unsigned x) {cerr << x;}
//void __print(unsigned long x) {cerr << x;}
//void __print(unsigned long long x) {cerr << x;}
//void __print(float x) {cerr << x;}
//void __print(double x) {cerr << x;}
//void __print(long double x) {cerr << x;}
//void __print(char x) {cerr << '\'' << x << '\'';}
//void __print(const char *x) {cerr << '\"' << x << '\"';}
//void __print(const string &x) {cerr << '\"' << x << '\"';}
//void __print(bool x) {cerr << (x ? "true" : "false");}
//template<typename T, typename V>
//void __print(const pair<T, V> &x);
//template<typename T>
//void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}" << "\n";}
//template<typename T, typename V>
//void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
//void _print() {cerr << "]\n";}
//template <typename T, typename... V>
//void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
//#ifdef DEBUG
//#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
//#else
//#define dbg(x...)
//#endif

ll solve(){
	int n, k; cin>>n>>k;
	vector<pair<int, int>> a(n);
	for(auto &it:a) cin>>it.ff;
	for(auto &it:a) cin>>it.ss;
	
	
	auto f = [&](int g) -> int{
		int cnt = 0, cntK = 0;
		for (auto &it:a) {
			if (cntK > k) return -1;
			if (g <= it.ff) {
				cnt++;
			} else if (g <= it.ss){
				cnt++; cntK++;
			}
		}
		return cntK > k ? -1 : cnt;
	};
	
	ll ans = 0;
	int l=0, r=1000000000;
	while (l <= r){
		ll mid = (l + r) / 2LL;
		ll c = f(mid);
		//cout<<l<<" "<<r<<" "<<mid<<" "<<c<<'\n';
		if (c != -1 && (c * mid > ans)){
			l = mid + 1;
			ans = (ll)((ll)c * (ll)mid);
		} else r = mid - 1;
	}
	return ans;
} 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	retsolve
}
