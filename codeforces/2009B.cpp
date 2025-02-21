#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        string s; cin>>s;
        a[i]=s.find('#')+1;
    }
    for(int i=n-1; i>=0; i--){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
}
