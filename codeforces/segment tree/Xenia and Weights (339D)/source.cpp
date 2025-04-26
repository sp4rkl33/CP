#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define retsolve int t; cin>>t; while(t--){cout<<solve()<<'\n';}
#define voidsolve int t; cin>>t; while(t--){solve();}
#define ff first
#define ss second

using namespace std;

void solve(){
    int n, m, e; cin >> e >> m; n = (1 << (e));
    vector<int> v(4 * n + 7), a(n);
    for (auto &it:a) cin >> it;
    //typical segment tree build function
    auto build = [&](auto self, int l, int r, int idx, bool x) -> void{
        if (l < r){
            int mid = (l + r) / 2;
            self(self, l, mid, 2 * idx, !x);
            self(self, mid + 1, r, 2 * idx + 1, !x);
            v[idx] = x ? v[idx * 2] ^ v[idx * 2 + 1] : v[idx * 2] | v[idx * 2 + 1];
        } else v[idx] = a[l];
    };

    auto sol = [&](auto self, int l, int r, int p, int idx, bool x) -> void{    
       if (p > r || l > p) return; // checking if the position still inside the query we asking for.
       if (l == p && r == p) { //update the leaf
            v[idx] = a[p];
            return;
       }
       int mid = (l + r) / 2;
       self(self, l, mid, p, 2 * idx, !x);
       self(self, mid + 1, r, p, 2 * idx + 1, !x);
       v[idx] = x ? v[idx * 2] ^ v[idx * 2 + 1] : v[idx * 2] | v[idx * 2 + 1];
    };

    build(build, 0, n - 1, 1, !(e % 2));
    
    while (m--){
        int p, x; cin >> p >> x; p--; a[p] = x;
        sol(sol, 0, n - 1, p, 1, !(e % 2));
        cout << v[1] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
}
