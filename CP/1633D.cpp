#include <bits/stdc++.h>
typedef long long ll;
#define FastIO(); std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
using namespace std;

void solution(){
    int n, k; cin >> n >> k;
    vector<int> b(n+1) , c(n+1) , a(n+1,1);
    for(int i = 1 ; i <= n ; i++) cin >> b[i];
    for(int i = 1 ; i <= n ; i++) cin >> c[i];
    vector<pair<ll,ll>> ops_cost(n+1,make_pair(0,0));
    for(int i = 1 ; i <= n ; i++){
        while(a[i] < b[i]){
            int x = 1 ;
            ops_cost[i].first ++;
            while(a[i] + a[i]/x > b[i]){
                x++;
            }
            a[i] += a[i]/x ;
        }
        if(a[i] == b[i]){
            ops_cost[i].second = c[i] ;
        }
    }
    //sort the ops_cost vector based on the first element of the no of operations in ascending order
    sort(ops_cost.begin(),ops_cost.end(),[](const pair<ll,ll>& a , const pair<ll,ll>& b){
        return a.first < b.first ;
    });
    for(int i = 2 ; i <= n ; i++){
        ops_cost[i].first += ops_cost[i-1].first ;
        ops_cost[i].second += ops_cost[i-1].second ;
    }
    ll ans = 0 ;
    for(int left = 1 ; left <= n ; left++){
        for(int right = left+1 ; right <= n ; right++){
            if(ops_cost[right].first - ops_cost[left].first <= k){
                ans = max(ans,ops_cost[right].second - ops_cost[left].second);
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    FastIO();
    int t;
    cin >> t;
    while(t--){
        solution();
    }
}