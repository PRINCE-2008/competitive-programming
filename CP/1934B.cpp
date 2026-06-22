#include <bits/stdc++.h>
typedef long long ll ;

void solution(){
     ll  n;
     std::cin >> n;
     ll val = 0;
     std::set<int> ones = {1,3,6,10,15};
     std::set<int> twos = {2,4,7,9,11,12,13,16,18,20,21,25,};
     std::set<int> three = {5,8,14,17,19,22,23,24,26,27,28};
     std::set<int> four = {29};
     val = (n/15>0)? n/15-1 : 0 ;
     ll rem = (n/15>0) ? n%15+15 : n%15 ;
     if(rem == 0) std::cout << val << '\n' ;
    // std::cout << val << '\n' ;
     if(ones.count(rem)) std::cout << val+1 << '\n' ;
     if(twos.count(rem)) std::cout << val+2 << '\n' ;
     if(three.count(rem)) std::cout << val+3 << '\n' ;
     if(four.count(rem)) std::cout << val+4 << '\n' ;


}

int main() { 
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t ;
    std::cin >> t ;
    while(t--){
        solution();
    }
}