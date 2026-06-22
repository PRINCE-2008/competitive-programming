#include <bits/stdc++.h>

void solution(){
    std::string s;
    std::cin >> s;
    int n = s.size();
    int min = n+4;
    int count = 0;
    bool flag =  false ;
    std::set<char> set;
    for(int i=0 ; i < n-1 ; i++){
        if(!flag){
            if(s[i]==s[i+1]) continue;
            else{
                flag = true;
                count+=2;
                set.insert(s[i]);
                set.insert(s[i+1]);
            }
        }else {
            if(s[i]==s[i+1]){
                count++;
                continue;
            }
            else {
                if(set.count(s[i+1])){
                    count = 0;
                    flag = false;
                    set.clear();
                    i--;
                }else{
                    flag = false;
                    count++;
                    min = std::min(min , count);
                    count = 0;
                    if(min == 3){
                        std:: cout << 3 << '\n' ;
                        return;
                    }
                    i--;
                    set.clear();
                }
            }
        }
    }
    if(min==n+4) std::cout << 0 << '\n' ;
    else std::cout << min << '\n' ;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--){
        solution();
    }
}