#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution(){
    int n , m;
    cin >> n >> m ;
    vector<array<int, 3>> idx_point_weight(m);
    for(int i = 0 ; i < m ; i++){
        idx_point_weight[i][0] = i+1 ;
        cin >> idx_point_weight[i][1] >> idx_point_weight[i][2] ;
    }
    sort(idx_point_weight.begin(),idx_point_weight.end(),[](const vector<int>& a, const vector<int>& b){
        return a[2] < b[2] ;
    });
    ll weight_sum = accumulate(idx_point_weight.begin(),idx_point_weight.begin() + 2*n,0LL,[](ll sum,const vector<int>& v){
        return sum + v[2] ;
    });
    cout << weight_sum << "\n";
    sort(idx_point_weight.begin(),idx_point_weight.begin() + 2*n,[](const vector<int>& a, const vector<int>& b){
        return a[1] < b[1] ;
    });
    for(int i = 0 ; i < n ; i++){
        cout << idx_point_weight[i][0] << ' ' << idx_point_weight[2*n - 1 - i][0] << "\n";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solution();
    }
}