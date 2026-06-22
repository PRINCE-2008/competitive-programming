

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FastIO(); std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

void solution(){
    int n;
    cin >> n;
    vector<int> d = {1,2,3,4,5,6};
    vector<int> soln(n+1);
    soln[0] = 1 ;
    for(int i = 1 ; i <= n ; i++){
        for(auto x : d){
            if(i - x >= 0){
                soln[i] = (soln[i]% 1000000007 + soln[i-x]% 1000000007) % 1000000007 ;
            }
        }
    }
    cout << soln[n] << "\n";
}

int main(){
    FastIO();
    solution();
}