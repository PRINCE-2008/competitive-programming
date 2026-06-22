#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
typedef long long ll;
using namespace std;

int negpow(int x){
    if(x%2==0) return 1;
    else return -1;
}

struct pos{
    int index;
    ll value;
    pos(): index(-1), value(LLONG_MAX) {}
    pos(int i, ll v): index(i), value(v) {}
};

void solution(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n ;i++) cin >> a[i];
    int sign = 1;
    vector<pos> positive(n);
    for (int i=n-1; i>=0 ;i--){
        if(a[i]>0) positive[i] = pos(i, a[i]);
        else positive[i] = pos(-1, LLONG_MAX);
        if(i<n-1 && positive[i+1].value < positive[i].value) positive[i] = positive[i+1];
    }
    vector<ll> absSum(n);
    for (int i=0; i<n ;i++){
        if(i==0) absSum[i] = abs(a[i]);
        else absSum[i] = absSum[i-1] + abs(a[i]);
    }
    vector<ll> sum(n);
    for (int i=0; i<n ;i++){
        if(i==0) sum[i] = a[i];
        else sum[i] = sum[i-1] + a[i];
    }
    if(absSum[n-1] == abs(sum[n-1])) {
        cout << 0 << endl;
        cout << endl;
        return ;
    }
    //finding the positive element whose left side elements all become positve after flippin
    // and right side elements remains unchanged ans the element itself become negative to get maximum sum of the array
    ll maxSum = 0;
    int idx = -1;
    for (int i=0; i<n ; i++){
        if(positive[i].index==-1) continue;
        maxSum = max(maxSum, sum[n-1] -sum[positive[i].index] + absSum[positive[i].index]-2*positive[i].value);
        if(maxSum == sum[n-1] -sum[positive[i].index] + absSum[positive[i].index]-2*positive[i].value) {
            if(sum[positive[i].index]==absSum[positive[i].index]) continue;
            idx = positive[i].index;}
    }


    //flipping the left side elements of the positive element at idx
    vector<int> flip;
    for (int i=0; i<idx ;i++) { 
        if(a[idx-i-1]*negpow(flip.size())>0) flip.push_back(idx-i-1);
    }
    flip.push_back(idx);
    if(flip.size()==1) {
        if(flip[0]==-1) {
        cout << 0 << endl;
        cout << endl;
        return ;
    }}
    cout << flip.size() << endl;
    if(flip.size()!=0) for(int i : flip) cout << i+1 << " ";
    cout << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solution();
    }
}