#include <bits/stdc++.h>
using namespace std;

void solution(){
    string s;
    cin >> s;
    int n = s.size();
    queue<char> q;
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        if(s[i] == ')'){
            q.pop();
            if(q.empty()){
                count++;
            }
        }else {
            q.push('(');
        }
    }
    if(count == 1){
        cout << "NO\n";
    }else{
        cout << "YES\n";
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