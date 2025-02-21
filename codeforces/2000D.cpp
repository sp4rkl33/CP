#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> a;

ll solve(){
	int n; cin>>n; n++;
	a.resize(n);
	for (int i=1; i<n; i++){
		int t; cin>>t;
		a[i]=a[i-1]+t;
	}
	string s; cin>>s; s='.'+s;
	int l=1, r=n;
	ll ans=0;
	while (l<r){
		while(s[r]!='R' && r>l){
			r--;
		}
		while(s[l]!='L' && r>l){
			l++;
		}
		if (l>=r) break;
		ans+=a[r]-a[l-1];
		l++; r--;
	}
	return ans;
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
	return 0;
}
