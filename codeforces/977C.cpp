#include <bits/stdc++.h>

using namespace std;
vector<int> a;

int main(){
	int n,k; cin>>n>>k;
	a.resize(n);
	for (int i=0; i<n; i++){
		cin>>a[i];
	}
	
	sort(a.begin(), a.end());
	
	int ans = k==0 ? a[0]-1:a[k-1];
	if (a[k]==ans || ans==0) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
