#include<bits/stdc++.h>

using namespace std;

int solve(){
	int n; cin>>n;
	vector<vector<int> > a;
	a.resize(n);
	for(int i=0; i<n; i++){
		a[i].resize(n);
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}
	int ans=0;
	for (int i=-n+1; i<n; i++){
		if (i<0){
			int t = abs(i), j=0;
			int mn = 1e9 + 7;
			for (; t<n; t++){
				mn = min(a[t][j], mn);
				j++;
			}
			ans = mn<0 ? ans+-mn:ans;
		} else {
			int t = i, j=0;
			int mn = 1e9+7;
			for (; t<n; t++){
				mn = min(mn, a[j][t]);
				j++;
			}
			ans = mn<0 ? ans+-mn:ans;
		}
	}
	return ans;
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
}
