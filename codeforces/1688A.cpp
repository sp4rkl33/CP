#include <bits/stdc++.h>

using namespace std;


int solve(){
	int n;
	cin>>n;
	if (n<=2) return 3;
	else if(n%2!=0) return 1;
	//find the rightmost 1 bit
	int c=n;
	int t=1;
	while (true){
		if (n%2==1) break;
		t*=2;
		n=n>>1;
	}
	return c==t?t+1:t;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
	return 0;
}
