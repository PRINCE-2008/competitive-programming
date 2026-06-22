#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> res;
    if(s[0] == '0'){
        res.push_back(1);
        for(int i = 1 ; i < n ; i++){
            if(s[i] == '1'){
                res.push_back(i+1);
            }
        }
        cout << res.size() << "\n";
        for(int i = 0 ; i < res.size() ; i++){
            cout << res[i] << ' ';
        }
        cout << "\n";
        return;
    }
    int count1 = count(s.begin(),s.end(),'1');
    int count0 = count(s.begin(),s.end(),'0');
    if(count1 == 1){
        cout << 1 << "\n";
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '1'){
                cout << i+1 << "\n";
                return;
            }
        }
    }
    if(count0 == 1){
        cout << 1 << "\n";
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0'){
                cout << i+1 << "\n";
                return;
            }
        }
    }
    if(s[0] == '1'){
        if(s[s.size()-1] == '0'){
            if(s.size() == 2) {
                cout << 1 << "\n";
                cout << 2 << "\n";
            } else {
                cout << -1 << "\n";
            }
            return;
        }
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '0'){
                res.push_back(i+1);
            }
        }
        res.push_back(n);
        cout << res.size() << "\n";
        for(int i = 0 ; i < res.size() ; i++){
            cout << res[i] << ' ';
        }
        cout << "\n";
        return;
    }
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