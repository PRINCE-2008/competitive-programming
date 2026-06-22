// You are given an m x n matrix mat that has its rows sorted in non-decreasing order and an integer k.

// You are allowed to choose exactly one element from each row to form an array.

// Return the kth smallest array sum among all possible arrays.

#include <bits/stdc++.h>
typedef long long ll;

int kthSmallest(std::vector<std::vector<int>>& mat, int k){
    int m = mat.size();
    int n = mat[0].size();
    std::priority_queue<std::pair<int,std::vector<int>>> pq;
    std::vector<int> indices(m,0);
    int sum=0;
    for(int i=0 ;i<m ;i++) sum+=mat[i][0];
    pq.push({sum,indices});
    while(k--){
        auto curr = pq.top();
        pq.pop();
        sum = curr.first;
        indices = curr.second;
        for(int i=0 ;i<m ;i++){
            if(indices[i] == n-1) continue;
            std::vector<int> newIndices = indices;
            newIndices[i]++;
            int newSum = sum - mat[i][indices[i]] + mat[i][newIndices[i]];
            pq.push({newSum,newIndices});
            std::accumulate(newIndices.begin(), newIndices.end(), 0);
        }
    }
    return pq.top().first;
}