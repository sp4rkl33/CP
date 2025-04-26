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

string solve(){
   int n, m; cin >> n >> m;
   map<int, int> mp;

   //store all element of A in a map
   for (int i = 0; i < n; i++) {
       int x; cin >> x;
       mp[x]++;
   }

    vector<int> b(m); for (auto &it:b) cin >> it;

   //iterate through every nums in B
   for (int x:b){
       //using heap to maintain the algorithm in time limit
       priority_queue<int, vector<int>, greater<int>> pq;
       pq.push(x);
       while (!pq.empty()){
           int cur = pq.top(); pq.pop();
           if (cur == 0) return "NO";
           else if (mp[cur] > 0){
                mp[cur]--;
                n--;
           } else {
               pq.push(cur / 2);
               pq.push(cur % 2 + cur / 2);
           }
       }
   }

   return n > 0 ? "NO" : "YES";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	retsolve
}
