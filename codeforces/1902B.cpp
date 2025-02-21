#include<bits/stdc++.h>
#define ll long long 

using namespace std;

int solve(){
	ll n,p,l,t; cin>>n>>p>>l>>t;
	ll cnt = (n-1)/7 + 1;
	ll ans=0;
	if (cnt/2 > 0){
		ans = p/(2*t+l);
		if (p%(2*t+l)!=0) ans++;
		ans = min(ans,cnt/2);
	}
	p-=ans*(2*t+l);
	if (p<=0) return max((ll)0,n-ans);
	ans+=cnt%2;
	p=cnt%2==0 ? p:p-(cnt%2)*t-l;
	p=max((ll)0,p);
	ans = p>0 ? (p%l==0 ? ans+p/l:ans+p/l+1):ans;
	
	return max((ll)0,n-ans);
}
int main(){
	int t; cin>>t;
	while(t--){
		cout<<solve()<<endl;
	}
}
