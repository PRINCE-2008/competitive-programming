#include <bits/stdc++.h>
using namespace std;

void solution(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v(n);
    for(auto c : s){
        v.push_back(c - '0');
    }
    sort(v.begin()+2,v.end());
    cout << v[0] << "\n";
    int ans = 0 ;
    int freqcount = 0 ;
    int sum  = 0 ;
    for(int i = 1 ; i < n ; i++){
        sum += v[i];
        if(sum < 8){
            freqcount++;
        }else if(sum == 8){
            freqcount++;
            break;
        } else {
            sum -= v[i];
            break;
        }
        cout << freqcount << "\n";
    }
    if(sum+v[0] > 9){
        ans = n - freqcount -1 ;
    } else {
        ans = n - freqcount  ;
    }
    cout << ans << "\n" ;
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