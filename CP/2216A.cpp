#include <bits/stdc++.h>
using namespace std;
void solutiion(){
    int n , k ;
    cin >> n >> k ;
    vector<vector<int>> v(k+2);
    for(int i = 0 ; i < k ; i++){
        int x;
        cin >> x;
    }
    for(int i = 1 ; i<= n ; i++){
        int temp ;
        cin >> temp;
        v[temp].push_back(i);
    }
    vector<int> ans ;
    for(int i = k ; i > 0 ; i--){
        for(int j = 0 ; j < v[i].size() ; j++){
            int temp = v[i][j];
            for(int p = i ; p <=k ; p++){
                ans.push_back(temp);
            }
        }
    }
    // reverse(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solutiion();
    }
}