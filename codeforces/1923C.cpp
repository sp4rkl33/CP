#include <bits/stdc++.h>
#define ll long long
#define taskwithtestcase int t; cin>>t; while(t--){cout<<solve()<<'\n';}
using namespace std;
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

void solve(){
	int n,q; cin>>n>>q;
	vector<ll> sum(n+1); vector<int> cnt(n+1);
	for (int i=1; i<=n; i++){
		cin>>sum[i];
		if (sum[i]==1) cnt[i]++;
		sum[i]+=sum[i-1];
		cnt[i]+=cnt[i-1];
	} 
	
	while(q--){
		int x,y; cin>>x>>y;
		cout<<(!(x==y) && sum[y] - sum[x-1] >= cnt[y] - cnt[x-1] + y - x + 1 ? "YES":"NO");
		cout<<'\n';
	}	
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin>>t;
	while(t--) solve();
}
