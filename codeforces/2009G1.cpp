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
	int n,k,q; cin>>n>>k>>q;
	vector<int> a(n); for(auto &it:a) cin>>it;
	vector<int> f(n);
	map<int, int> mp;
	multiset<int> ms;
	
	for(int i=0; i<k-1; i++) {
		if (ms.find(mp[a[i] - i]) != ms.end()) ms.erase(ms.find(mp[a[i] - i]));
		mp[a[i]-i]++;
		ms.insert(mp[a[i] - i]);
	}	
	
	for (int i=k-1; i<n; i++){
		int t = i - k + 1;
		if (ms.find(mp[a[i] - i]) != ms.end()) ms.erase(ms.find(mp[a[i] - i]));
		mp[a[i] - i]++;
		ms.insert(mp[a[i] - i]);
		f[t] = *ms.rbegin();
		if (ms.find(mp[a[t] - t]) != ms.end()) ms.erase(ms.find(mp[a[t] - t]));
		mp[a[t] - t]--;
		ms.insert(mp[a[t] - t]);
	}

	while (q--){
		int l, r; cin>>l>>r;
		cout<<k-f[l-1]<<'\n';
	}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	voidsolve
}
