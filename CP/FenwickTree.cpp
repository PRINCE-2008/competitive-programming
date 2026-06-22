#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct FenwickTree {
    vector<ll> tree;
    int n;
    // constructor to initialize the Fenwick Tree with a given size
    FenwickTree(int n) : n(n) {
        tree.assign(n + 1, 0);
    }
    //Update the Fenwick Tree at index idx by adding value val
    void update(int idx, ll val) {
        while (idx <= n) {
            tree[idx] += val;
            idx += idx & -idx; // Move to the next parent node
        }
    }
    //Query the Fenwick Tree to get the prefix sum up to index idx
    ll query(int idx) {
        ll sum = 0 ; 

        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    // query the Fenwick Tree to get the sum in the range [l, r]
    ll queryRange(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    int n = 10; // Size of the Fenwick Tree
    FenwickTree bit(n);
    // Update some values in the Fenwick Tree
    bit.update(1, 5);
    bit.update(3, 10);
    bit.update(5, 15);
    // Query the prefix sum up to index 5
    cout << "Prefix sum up to index 5: " << bit.query(5) << endl; // Output: 30
    // Query the sum in the range [2, 5]
    cout << "Sum in the range [2, 5]: " << bit.queryRange(2, 5) << endl; // Output: 25
    return 0;

}