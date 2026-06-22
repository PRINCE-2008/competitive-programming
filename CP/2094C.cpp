#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n;
    cin >> n;
    int matrix[n][n];
    vector<int> result(2*n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin >> matrix[i][j];
        }
    }
    for(int i = 0 ; i < n ; i++){
        result[i+1] = matrix[i][0];
        if(i!=n-1){
            result[i+n+1] = matrix[i+1][n-1];
        }
    }
    
    int sum = accumulate(result.begin(),result.end(),0);
    result[0] =  n*(2*n+1) - sum;

    for(int i = 0 ; i < 2*n ; i++){
        cout << result[i] << ' ';
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