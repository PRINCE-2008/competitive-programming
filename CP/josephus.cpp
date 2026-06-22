#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node* next;
};

void solution(){
    int n , k;
    cin >> n >> k;
    node* head = new node();
    node* first = head;
    for(int i = 1 ; i <= n ;i++){
        head->val = i;
        if(i != n){
            head->next = new node();
            head = head->next;
        }
    }
    head->next = first;
    head = head->next;
    int ans = 0;
    for(int i = 1 ; i <= k ; i++){
        ans = head->next->val;
        node* temp = head->next->next;
        delete head->next;
        head->next = temp;
        head = head->next;
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--){
            solution();
        }
    }
    return 0;
}