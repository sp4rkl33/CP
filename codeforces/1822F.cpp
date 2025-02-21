#include <bits/stdc++.h>
#define ll long long
#define taskwithtestcase int t; cin>>t; while(t--){ cout<<solve()<<'\n';}
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

ll solve(){
	int n; ll k,c; cin>>n>>k>>c;
	vector<vector<int>> g(n);
	for (int i=0; i<n-1; i++){
		int x,y; cin>>x>>y; x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector<int> disR(n), disA(n), disB(n);
	int mx=0, farA=0, farB=0;
	auto dfs = [&](auto self, int u, int d, int pst, int &farth, vector<int> &dist) -> void{
		dist[u]=d;
		if (mx<d){
			farth=u;
			mx=d;
		}
		for(int i:g[u]) if (i != pst) self(self, i, d+1, u, farth, dist);
	};
	mx=0; dfs(dfs, 0, 0, 0, farA, disR);
	mx=0; dfs(dfs, farA, 0, farA, farB, disA);
	dfs(dfs, farB, 0, farB, mx, disB);
	ll ans=0;
	for (int i=0; i<n; i++) ans = (ll)max((ll)max(disA[i], disB[i])*k - (ll)disR[i]*c, ans);
	return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    taskwithtestcase
}
