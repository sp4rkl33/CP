#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define retsolve int t; cin>>t; while(t--){cout<<solve()<<'\n';}
#define voidsolve int t; cin>>t; while(t--){solve();}
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ff first
#define ss second

using namespace std;
using namespace __gnu_pbds;

template <class type1>
using ordered_multiset = tree <type1, null_type, less_equal <type1>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n; cin >> n;
    map<int, vector<int>> mp;
    int t; cin >> t;
    mp[t].push_back(1);
    int cnt = 1, ansn = t, ansl = 1, ansr = 1;

    //store index of every number into a map
    for (int i = 2; i <= n; i++){
        int x; cin >> x;
        mp[x].push_back(i);
    }

    //iterate through the map
    for (auto it:mp){
        int tcnt = 1, tl = it.ss[0], tr = tl;
	//iterate through every index of a number.
        for (int i = 1; i < (int)it.ss.size(); i++){
            tcnt += 2 - it.ss[i] + it.ss[i - 1]; 
            tr = it.ss[i];
            if (tcnt < 1){
                tcnt = 1;
                tl = tr;
            }
            if (tcnt > cnt){
                cnt = tcnt; ansn = it.ff; ansl = tl; ansr = tr; 
            }
        }
    }

    cout << ansn << ' ' << ansl << ' ' << ansr << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	  voidsolve
}
