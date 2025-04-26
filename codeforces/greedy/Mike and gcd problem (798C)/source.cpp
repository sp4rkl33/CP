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
    int c = -1, cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++){
        int it;
        cin >> it;

	// maintain the GCD of the whole array.
        if (c == -1) c = it;
        else c = __gcd(c, it);

	//let's counter do the work.
        if (it % 2 == 1) cnt++;
        else {
            ans += (cnt / 2) + (cnt % 2) * 2;
            cnt = 0;
        }
    }
    if (c > 1) cout << "YES\n" << 0 << '\n';
    else cout << "YES\n" << ans + (cnt / 2) + (cnt % 2) * 2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	solve();
}
