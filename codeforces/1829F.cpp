#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bool op(int x, int y){
	return x>y;
}

void swap(int &a, int &b){
	int z=a;
	a=b;
	b=z;
}

void solve(){
	int n,m; cin>>n>>m;
	vector<int> deg(n);
	for(int i=0; i<m; i++){
		int x,y; cin>>x>>y; x--; y--;
		deg[x]++; deg[y]++;
	}
	vector<int> ma(1001), cnt;
	for (int i=0; i<n; i++){
		if (!ma[deg[i]]) cnt.push_back(deg[i]);
		ma[deg[i]]++;
	}
	sort(cnt.begin(), cnt.end(), op);
	if (ma[cnt[0]] > ma[cnt[1]]) swap(cnt[0],cnt[1]);

	
	if (cnt.size()==2){
		cout<<cnt[0]<<" "<<cnt[0]-1<<"\n";
	} else {
		cnt[1] = cnt[1]==1 ? 1:cnt[1]-1;
		cout<<cnt[0]<<" "<<cnt[1]<<"\n";
	}
	
}

int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

