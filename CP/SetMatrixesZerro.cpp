#include <bits/stdc++.h>

void setZeros(std::vector<std::vector<int>>& matrix){
    int m = matrix.size();
    int n= matrix[0].size();
    std::set<int> zeroCol;
    for(int i=0 ;i< m ; i++){
        bool isZero=false;
        for(int j=0;j<n ;j++){
            if(matrix[i][j]==0){
                if(zeroCol.count(j) == 0) zeroCol.insert(j);
                isZero=true;
            }
        }
        if(isZero) matrix[i]= std::vector<int> (n,0);
    }
    for(int i : zeroCol){
        for(int j=0 ;j<m ;j++){
            matrix[j][i] = 0;
        }
    }
    return ;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t--){
        int m, n;
        std::cin >> m >> n;
        std::vector<std::vector<int>> matrix(m,std::vector<int>(n));
        for(int i=0 ;i<m ;i++){
            for(int j=0 ;j<n ;j++){
                std::cin >> matrix[i][j];
            }
        }
        setZeros(matrix);
        for(int i=0 ;i<m ;i++){
            for(int j=0 ;j<n ;j++){
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
}
