#include<bits/stdc++.h>

using namespace std;

int solve(){
	int n,x,y; cin>>n>>x>>y;
	int ans=min(x,y);
	return n%ans==0? n/ans:n/ans + 1;	
}

int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;		
	}
}
