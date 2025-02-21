#include<bits/stdc++.h>

using namespace std;

class o{
	public:
		int p;
		int v;
	bool operator<(const o& obj) const{
		return v < obj.v;
	}
};
	

vector<o> a;
vector<int> ans;

void solve(){
	int n; cin>>n;
	a.resize(n); ans.resize(n);
	for (int i=0; i<n; i++){
		int t; cin>>t;
		a[i].p=i;
		a[i].v=t;
	}
	sort(a.begin(), a.end());
	int c=n;
	for (int i=0; i<c; i++){
		ans[a[i].p]=n;
		n--;
	}
	for (int i=0; i<c; i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int t; cin>>t;
	while(t--){
		solve();;
	}
}
