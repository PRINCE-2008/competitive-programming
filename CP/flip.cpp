//given two binary strings a and b of the same length n , you can perform the following operation on string n number of times: 
// choose l and r (1<=l<r<=n) and flip the bits of a from l to r (both inclusive) .
// Your task is to find the  number of operations required to make a and b equal. or determine that it is impossible to make a and b equal.
// output should be number of operations required to make a and b equal or -1 if it is impossible to make a and b equal.
// if operations are possible then also output the [l,r] pairs of the operations required to make a and b equal.
#include <bits/stdc++.h>

void solution(){
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    std::vector<std::pair<int,int>> operations;
    for(int i=0 ;i<n ;i++){
        if(a[i] != b[i]){
            int j = i;
            while(j<n && a[j] != b[j]) j++;
            if(j == i+1){
                std::cout << "-1\n";
                return;
            }
            operations.push_back({i+1,j});
            for(int k=i ;k<j ;k++) a[k] = (a[k] == '0') ? '1' : '0';
        }
    }
    if(a == b){
        std::cout << operations.size() << "\n";
        for(auto op : operations) std::cout << op.first << " " << op.second << "\n";
    }
    else std::cout << "-1\n";

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