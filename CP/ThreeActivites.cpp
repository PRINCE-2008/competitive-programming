#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> top3(vector<int> &v){
    vector<pair<int,int>> vla_idx(v.size());
    for(int i = 0 ; i < v.size() ; i++){
        vla_idx[i] = {v[i], i};
    }
    sort(vla_idx.begin(), vla_idx.end(), [](const pair<int,int> &a, const pair<int,int> &b){
        return a.first > b.first;
    });
    return {vla_idx[0], vla_idx[1], vla_idx[2]};

}

void solution(){
    int n ;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    for(int i = 0 ; i < n ; i++) cin >> b[i];
    for(int i = 0 ; i < n ; i++) cin >> c[i];

    auto top3_a = top3(a);
    auto top3_b = top3(b);
    auto top3_c = top3(c);
    int ans = 0; 
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            for(int k = 0 ; k < 3 ; k++){
                if(top3_a[i].second != top3_b[j].second && top3_b[j].second != top3_c[k].second && top3_a[i].second != top3_c[k].second){
                    ans = max(ans, top3_a[i].first + top3_b[j].first + top3_c[k].first);
                    
                }
            }
        }
        // cout << ans << "\n";
    }
    cout << ans << "\n";
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