#include <iostream>
#include <vector>

using namespace std;

void permutation(vector<int> nums, int l, vector<vector<int>> &res){
    // if(l==nums.size()){
    //     res.push_back(nums);
    //     return ;
    // }
    // for(int i=l ;i<nums.size() ;i++){
    //     swap(nums[l], nums[i]);
    //     permutation(nums, l+1, res);
    //     swap(nums[l], nums[i]);
    // }\

    // for O(n) space complexity
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0 ;i<n ;i++) cin >> nums[i];
    vector<vector<int>> res;
    permutation(nums, 0, res);
    for(auto &it : res){
        for(auto &num : it) cout << num << " ";
        cout << "\n";
    }
}