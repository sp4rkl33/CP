#include <bits/stdc++.h>
using namespace std;

int mx(int a, int b){
	return a>b? a:b;
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> res(n);
	for (int i=0; i<n; i++){
		if (i+1 >= a[i]) {
			if (i-a[i] < 0) res[i]=1;
			else res[i] = mx(1, res[i-a[i]] + 1);
		}
		if (i>0) res[i]=mx(res[i-1],res[i]);
	} 
	cout << res[n-1] << endl;
}

int main(){
	int t;
    cin >> t;
    while (t--){
    	solve();
	}
    return 0;
}
