#include<bits/stdc++.h>
#define ll long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(nullptr);

using namespace std;

bool op(int a, int b){
	return a>b;
}

ll solve(){
	int n,k; cin>>n>>k;
	vector<int> a(max(n,k));
	for (int i=0; i<k; i++){
		int b,c; cin>>b>>c;
		a[b-1]+=c;
	}
	ll sum=0;
	sort(a.begin(), a.end(), op);
	for (int i=0; i<n; i++) sum+=a[i];
	return sum;
}

int main(){
	FAST
	int t; cin>>t;
	while(t--){
		cout<<solve()<<"\n";
	}
	return 0;
}
