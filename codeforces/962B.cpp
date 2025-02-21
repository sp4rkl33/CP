#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<vector<int> > g;
vector<int> s1, s2;
vector<bool> v;

void dfs(int u, int p){
	v[u]=1; 
	if (p==0) s1.push_back(u); 
	else s2.push_back(u);
	for (int i=0; i<g[u].size(); i++){
		if (!v[g[u][i]]) dfs(g[u][i], 1-p);
	}
}

ll solve(){
	int n; cin>>n;
	if (n<=2) return 0;
	g.resize(n); v.resize(n);
	for(int i=0; i<n-1; i++){
		int x,y; cin>>x>>y; x--; y--;
		g[x].push_back(y); g[y].push_back(x);
	}
	for (int i=0; i<n; i++){
		if (!v[i]) dfs(i,0);
	}
	ll mx=s1.size()*s2.size(), sum=0;
	for (int i=0; i<s1.size(); i++){
		sum+=(ll)g[s1[i]].size();
	}
	return mx-sum;
}

int main(){
	FAST;
	cout<<solve();
	return 0;
}
