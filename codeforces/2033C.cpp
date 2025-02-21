#include<bits/stdc++.h>

using namespace std;

int f(int l, int m1, int m2, int r){
	int res=0;
	if (l==m1) res++;
	if (r==m2) res++;
	return res;
}

int solve(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	if (n==2) {
		return a[0]==a[1];
	}
	int l = n/2 - 1, r = n%2==0 ? n/2:n/2+1, ans = 0;
	if (n%2==0){
		ans = a[l]==a[r];
		l--; r++;
	}
	while (l>=0){
		ans += min(f(a[l],a[l+1],a[r-1],a[r]), f(a[r],a[l+1],a[r-1],a[l]));
		l--; r++;
	}
	return ans;
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
}
