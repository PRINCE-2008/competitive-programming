#include <bits/stdc++.h>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t; // testcases
    std::cin >> t;
    while(t--){
    std::string s;
    std::cin >> s;
    int n = s.size();
    int maxlen=0;
    int start=0;
    std::unordered_map<char,int> m;
    for(int i=0 ;i<n  ;i++){
        m[s[i]]++;
        if(m[s[i]]>1){
            while(m[s[i]]>1){
                m[s[start]]--;
                start++;
            }
        }
        maxlen = std::max(maxlen, i-start+1);
    }
    std::cout << maxlen << std::endl;
}
}