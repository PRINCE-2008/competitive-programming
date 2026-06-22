#include <bits/stdc++.h>

using namespace std;

void solution(){
    int n ;
    cin >> n;
    vector<bool> s(n);
    for(int i = 0 ; i < n ; i++){
        char c ;
        cin >> c ;
        s[i] = (c == '1') ;
    }
    //string s is a binary string of length n
    
    
    vector<bool> st;
    vector<int> dp(n, 0);
    dp[0] = 1 ;
    st.push_back(s[0]);
    int ans = 0 ;
    for(int i = 1 ; i < n ; i++){
        if(s[i] == st.back()){
            int pos = i ;
            int temp = s[i] ;
            while(!st.empty() && st.back() == temp){
                st.pop_back();
                dp[i]++;
                temp = !temp ;
                pos-- ;
            }
            st.push_back(s[i]);
            dp[i]++;
            if(st.size() == 1){
                dp[i] += pos ;
            }
        } else {
            st.push_back(s[i]);
            dp[i]++;
        }
    }
    cout << accumulate(dp.begin(),dp.end(),0) << "\n" ;
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