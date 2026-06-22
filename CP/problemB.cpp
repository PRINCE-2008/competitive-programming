#include <bits/stdc++.h>

void solution(){
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int i = 0 ; i<n ; i++){
        std::cin >> v[i];
    }
    
    int leftidx = 0;
    int rightidx = n - 1;
    
    while (leftidx < n - 1 && v[leftidx] < v[leftidx + 1]) {
        leftidx++;
    }
    if (leftidx == n - 1) {
        std::cout << "yes\n1 1\n";
        return;
    }
    while (rightidx > 0 && v[rightidx] > v[rightidx - 1]) {
        rightidx--;
    }
    std::reverse(v.begin() + leftidx, v.begin() + rightidx + 1);
    bool issorted = true;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            issorted = false;
            break;
        }
    }
    if (issorted) {
        std::cout << "yes\n" << leftidx + 1 << " " << rightidx + 1 << "\n";
    } else {
        std::cout << "no\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    solution();
}