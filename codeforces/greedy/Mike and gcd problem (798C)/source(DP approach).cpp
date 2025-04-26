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

void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto &it:a) cin >> it;
    vector<pair<int, int>> f(n); 
    int z = a[0];
    if (a[0] % 2 == 1) f[0] = make_pair(2, 1);

    for (int i = 1; i < n; i++){
        z = __gcd(z, a[i]);
        if (a[i] % 2 == 1){ //if current number is an odd we proceed the calculation
            if (a[i - 1] % 2 == 0) { //if previous number is an even
                f[i].ff = f[i - 1].ff + 2;
                f[i].ss = 1;
            }
            else {
                if (f[i - 1].ss == 1){ //if previous number was merged with an even
                    f[i].ff = f[i - 1].ff - 1;
                    f[i].ss = 2;
                } else if (f[i - 1].ss == 0){ //if previous number was a free odd number
                    f[i].ff = f[i - 1].ff + 1;
                    f[i].ss = 2;
                } else { //if previous number was merged with an even 
                    f[i].ff = f[i - 1].ff + 2;
                    f[i].ss = 1;
                }
            }
        } else f[i].ff = f[i - 1].ff;
    }
    cout << "YES\n" << (z > 1 ? 0 : f[n - 1].ff);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
}
