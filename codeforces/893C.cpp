#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<vector<int> > g;
vector<ll> c;
vector<bool> v;

void dfs(int u, ll &mnc){
	v[u] = 1;
	mnc = min(mnc, c[u]);
	for(int i=0; i<g[u].size(); i++){
		if (!v[g[u][i]]) dfs(g[u][i], mnc);
	}
}

ll solve(){
	int n,m; cin>>n>>m;
	g.resize(n); c.resize(n); v.resize(n);
	for(int i=0; i<n; i++){
		cin>>c[i];
	}
	for(int i=0; i<m; i++){
		int x,y; cin>>x>>y; x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	ll ans=0;
	for (int i=0; i<n; i++){
		if (!v[i]) {
			ll mnc = c[i];
			dfs(i, mnc);
			ans += mnc;
		}
	}
	return ans;
}

int main(){
	FAST;
	cout<<solve()<<'\n';
	return 0;
}

