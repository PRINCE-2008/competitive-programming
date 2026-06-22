#include <bits/stdc++.h>

using namespace std;

void solution(){
    int n;
    cin >> n ;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    int d1 = 0;
    int ans = 0;
    for(int i = 1 ; i < n ; i++){
        if(arr[i] == arr[i-1]+1){
            d1++;
            ans = max(ans,d1);
        }
        else if(arr[i] == arr[i-1]){
            continue;
        }
        else{
            d1 = 0;
        }
    }
    cout << ans + 1<< "\n";
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