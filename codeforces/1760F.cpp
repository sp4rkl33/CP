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

#define int long long
void solve(){
	int n,d; ll c; cin>>n>>c>>d;
	vector<ll> a(n); for(auto &it:a) cin>>it;
	
	sort(a.begin(), a.end(), greater<ll>());
	vector<ll> s(n);
	for (int i=0; i<n; i++)	s[i] = i==0 ? a[i]:a[i]+s[i-1];
	
	if (s[min(n-1,d-1)]>=c){
		cout<<"Infinity\n";
		return;
	}
	if (a[0] * d < c){
		cout << "Impossible\n";
		return;
	}
	int l=0, r=1e9;
	int ans=-1;
	auto f=[&](int k) -> ll{
		ll sum=0;
		for (int i=0; i<d; i++) 
			if (i%(k+1)<n) sum+=a[i%(k+1)]; 
		return sum;
	};
	
	while (l<=r){
		int mid = (l+r)/2;
		if (f(mid) >= c){
			ans = max(mid, ans);
			l = mid+1;
		} else r=mid-1;
	}
	assert(ans!=-1);
	cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	voidsolve
	return 0;
}
