#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTree {
    vector<ll> tree;
    int n;
    // Constructor to initialize the Segment Tree with a given size
    SegmentTree(int n) : n(n) {
        // The size of the segment tree is typically 4 times the size of the input array to ensure enough space for all nodes
        tree.assign(4*n, 0);
    }
    // Build the Segment Tree from an input array
    void build(const vector<ll>& arr, int node, int start, int end) {
        // If the start and end indices are the same, we are at a leaf node, so we store the value of the array at this position
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2; // Calculate the midpoint of the current segment

        int leftChild = 2*node; // Index of the left child
        int rightChild = 2*node + 1; // Index of the right child

        // Recursively build the left and right subtrees
        build(arr, leftChild, start, mid);
        build(arr, rightChild, mid + 1, end);
        // After building the left and right subtrees, we combine their values to get the value for the current node
        // tree[node] = tree[leftChild] + tree[rightChild]; // For sum queries
        // tree[node] = max(tree[leftChild], tree[rightChild]); // For max queries
        tree[node] = min(tree[leftChild], tree[rightChild]); // For min queries
    }
    // Update the Segment Tree at index idx by adding value val
    void update(int node, int start, int end, int idx, ll val) {
        if(start == end) {
                // tree[node] += val; // For sum queries
                tree[node] = val; // for leaf node update
                // tree[node] = max(tree[node], val); // For max queries
                // tree[node] = min(tree[node], val); // For min queries
                return;
        }
         int mid = start + (end - start) / 2; // Calculate the midpoint of the current segment
         int leftChild = 2*node; // Index of the left child
         int rightChild = 2*node + 1; // Index of the right child
            // Recursively update the left or right subtree depending on the index we want to update
        if(idx <= mid) {
            update(leftChild, start, mid, idx, val);
        } else {
            update(rightChild, mid + 1, end, idx, val);
        }
        // Merge the updated values from the left and right children to update the current node
        // tree[node] = tree[leftChild] + tree[rightChild]; // For sum queries
        // tree[node] = max(tree[leftChild], tree[rightChild]); // For max queries
        tree[node] = min(tree[leftChild], tree[rightChild]); // For min queries

    }

    // Query the Segment Tree to get the sum in the range [l, r]
    ll query(int node, int start, int end, int l, int r) {
        // If the range of the current segment is completely outside the query range, return a default value (0 for sum, -inf for max, +inf for min)
        // Case 1: No overlap
        if(r < start || end < l) {
            // return 0; // For sum queries
            // return LLONG_MIN; // For max queries
            return LLONG_MAX; // For min queries
        }
        // Case 2: Total overlap
        if(l <= start && end <= r) {
            return tree[node];
        }
        // Case 3: Partial overlap
        int mid = start + (end - start) / 2; // Calculate the midpoint
        int leftChild = 2*node; // Index of the left child
        int rightChild = 2*node + 1; // Index of the right child
        // Recursively query the left and right subtrees and combine their results
        // return query(leftChild, start, mid, l, r) + query(rightChild, mid + 1, end, l, r); // For sum queries
        // return max(query(leftChild, start, mid, l, r), query(rightChild, mid + 1, end, l, r)); // For max queries
        return min(query(leftChild, start, mid, l, r), query(rightChild, mid + 1, end, l, r)); // For min queries
    }
};


int main() {
    int n = 5; // Size of the input array
    vector<ll> arr = {1, 3, 5, 7, 9}; // Example input array (1-indexed)
    SegmentTree segTree(n);
    segTree.build(arr, 1, 0, n - 1); // Build the segment tree with the input array

    // Update the value at index 2 to 10
    segTree.update(1, 0, n - 1, 2, 10);

    // Query the sum in the range [1, 3]
    cout << "Sum in the range [1, 3]: " << segTree.query(1, 0, n - 1, 1, 3) << endl; // Output: 20

    // Query the maximum value in the range [0, 4]
    cout << "Max in the range [0, 4]: " << segTree.query(1, 0, n - 1, 0, 4) << endl; // Output: 10

    // Query the minimum value in the range [0, 4]
    cout << "Min in the range [0, 4]: " << segTree.query(1, 0, n - 1, 0, 4) << endl; // Output: 1

    return 0;
}