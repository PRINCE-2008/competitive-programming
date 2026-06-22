#include <bits/stdc++.h>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--){
        int sides[3];
        std::cin >> sides[0] >> sides[1] >> sides[2];
        std::sort(sides, sides+3);
        while(sides[0]+sides[1] <= sides[2]){
            sides[2]=sides[1]+sides[0]-1;
        }
        std::cout << sides[0]+sides[1]+sides[2] << "\n";
    }
}