#include <bits/stdc++.h>
#define ll long long
#define taskwithtestcase int t; cin>>t; while(t--){ cout<<(solve() ? "YES\n":"NO\n");}
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

bool solve(){
	int n,a,b; cin>>n>>a>>b; a--; b--;
	vector<vector<int>> g(n); vector<bool> vv(n, 0); vector<int> dv(n, 1<<30), dm(n, 1<<30);
	for(int i=0; i<n; i++){
		int x,y; cin>>x>>y; x--; y--;
		g[x].push_back(y); g[y].push_back(x);
	}
	int m;
	bool founded=0;
	auto dfs = [&](auto self, int u, int dist, int pst) -> void{
		vv[u]=1;
		dv[u]=min(dv[u], dist);
		for (auto i:g[u]){
			if (founded) return;
			if (!vv[i]) self(self, i, dist+1, u);
			else if (i!=pst) {
				founded=1;
				m=i;
			}
		}
	};
	auto dfsa = [&](auto self, int u, int dist, int pst) -> void{
		dm[u]=min(dist, dm[u]);
		if (u==m) return;
		for (auto i:g[u]){
			if (i!=pst) self(self, i, dist+1, u);
		}
	};
	dfs(dfs,b,0,b);
	dfsa(dfsa,a,0,a);
	return dv[m]<dm[m];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    taskwithtestcase
}
