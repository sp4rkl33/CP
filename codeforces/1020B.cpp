#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<vector<int> >g;

int dfs(int u, vector<int> &state){
	state[u]=1;
	for(int i=0; i<g[u].size(); i++){
		if (state[g[u][i]]==1) return g[u][i];
		else if (state[g[u][i]]==0) return dfs(g[u][i], state);
	}
}

void solve(){
	int n; cin>>n;
	g.resize(n+1);
	for(int i=1; i<=n; i++){
		int x; cin>>x;
		g[i].push_back(x);
	}
	for (int i=1; i<=n; i++){
		vector<int> state(n+1);
		cout<<dfs(i,state)<<" ";	
	}
}

int main(){
	FAST;
	solve();
	return 0;
}

