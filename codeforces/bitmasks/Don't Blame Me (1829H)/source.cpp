#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
#define retsolve int t; cin>>t; while(t--){cout<<solve()<<'\n';}
#define voidsolve int t; cin>>t; while(t--){solve();}
#define ff first
#define ss second
using namespace std;
using namespace __gnu_pbds;

template <class type1>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;
template <class type1>
using ordered_set = tree <type1, null_type, less <type1>, rb_tree_tag, tree_order_statistics_node_update>;

int p[64];
const ll mod = 1e9 + 7LL;

//pre-calculation of all set bits of binary presentation of x (0 <= x <= 63)
void init(){
    p[0] = 0;
    for (int i = 1; i <= 63; i++){
        int cnt = 0, t = i;
        while (t > 0){
            cnt += (t % 2);
            t /= 2;
        }
        p[i] = cnt;
    }
}

ll solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n); for (auto &it : a) cin >> it;
    vector<vector<ll>> f(n + 1, vector<ll>(70, 0));

    //Dynamic programming
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < 64; j++){
            f[i][j] += f[i - 1][j]; f[i][j] %= mod; //remember to do modular calculation
            f[i][a[i - 1] & j] += f[i - 1][j]; f[i][a[i - 1] & j] %= mod; //remember to do modular calculation
        }
        f[i][a[i - 1]]++; f[i][a[i - 1]] %= mod;
    }
   
    ll ans = 0;

    //Sum all result
    for (int i = 0; i < 64; i++) ans = p[i] == k ? (ans + f[n][i]) % mod : ans; //remember to do modular calculation
    
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    retsolve;
}
