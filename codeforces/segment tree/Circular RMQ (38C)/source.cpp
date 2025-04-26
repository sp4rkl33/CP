#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define retsolve int t; cin>>t; while(t--){cout<<solve()<<'\n';}
#define voidsolve int t; cin>>t; while(t--){solve();}
#define ff first
#define ss second

using namespace std;

const ll inf = 1e18;

void solve(){
    int n; cin >> n;
    vector<ll> a(n); for(auto &it : a) cin >> it;
    vector<pair<ll,ll>> v(4 * n + 7);

    auto build = [&](auto self, int l, int r, int idx) -> void{
        if (l < r){
            int mid = (l + r) / 2;
            self(self, l, mid, 2 * idx);
            self(self, mid + 1, r, 2 * idx + 1);
            v[idx].ff = min(v[2 * idx].ff, v[2 * idx + 1].ff);
        } else v[idx].ff = a[l];
    };
    
    auto lazy = [&](int l, int r, int idx) -> void{
        if (l >= r || v[idx].ss == 0) return;
        v[idx * 2].ff += v[idx].ss;
        v[idx * 2].ss += v[idx].ss;
        v[idx * 2 + 1].ff += v[idx].ss;
        v[idx * 2 + 1].ss += v[idx].ss;
        v[idx].ss = 0;
        v[idx].ff = min(v[idx * 2].ff, v[idx * 2 + 1].ff);
    };

    auto update = [&](auto self, int l, int r, int L, int R, int idx, ll k) -> void{
        if (r < L || R < l) return;

        if (L <= l && r <= R){
            v[idx].ff += k;
            v[idx].ss += k;
            lazy(l, r, idx);
            return;
        }

        int mid = (l + r) / 2;
        lazy(l, r, idx);
        self(self, l, mid, L, R, 2 * idx, k);
        self(self, mid + 1, r, L, R, 2 * idx + 1, k);
        v[idx].ff = min(v[idx * 2].ff, v[idx * 2 + 1].ff);
    };
    
    auto sol = [&](auto self, int l, int r, int L, int R, int idx) -> ll{
        if (r < L || R < l) return inf;

        if (L <= l && r <= R){
            lazy(l, r, idx);
            return v[idx].ff;
        }

        int mid = (l + r) / 2;
        lazy(l, r, idx);
        return min(self(self, l, mid, L, R, 2 * idx), self(self, mid + 1, r, L, R, 2 * idx + 1));
    };
    
    build(build, 0, n - 1, 1);
    int q; cin >> q; q++;
    while (q--){ 
        vector<ll> query;
        string line; getline(cin, line);
        stringstream iss(line);
        ll nm;
        while(iss >> nm) query.push_back(nm);
        if (query.size() == 0) continue;
        if ((int)query.size() == 2){
            int l = query[0], r = query[1];
            if (l > r) {
                int ln = sol(sol, 0, n - 1, 0, r, 1), rn = sol(sol, 0, n - 1, l, n - 1, 1);
                cout << min(ln, rn) << '\n';
            } else cout << sol(sol, 0, n - 1, l, r, 1) << '\n';
        } else if ((int)query.size() == 3) {
            int l = query[0], r = query[1]; ll x = query[2];
            if (l > r){
                update(update, 0, n - 1, 0, r, 1, x);
                update(update, 0, n - 1, l, n - 1, 1, x);
            } else update(update, 0, n - 1, l, r, 1, x);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
}
